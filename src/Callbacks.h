#pragma once

namespace Steam
{
	// This class is mostly taken entirely from Goldberg Steam Emu
	// I had written mine and i had a bug with it, which I thought was due to me
	// So I replaced it with goldberg's. The bug was still there
	// Turns out I had simply forgotten to run a callback result somewhere in a steam function
	//	but it was too late, now we have goldberg's callback class, for better or worse

	static std::recursive_mutex globalMutex;

	//-----------------------------------------------------------------------------
	// Purpose: base for callbacks and call results - internal implementation detail
	//-----------------------------------------------------------------------------
	class CCallbackBase
	{
	public:
		CCallbackBase() { m_nCallbackFlags = 0; m_iCallback = 0; }
		// don't add a virtual destructor because we export this binary interface across dll's
		virtual void Run(void* pvParam) = 0;
		virtual void Run(void* pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall) = 0;
		int GetICallback() { return m_iCallback; }
		virtual int GetCallbackSizeBytes() = 0;

	protected:
		enum { k_ECallbackFlagsRegistered = 0x01, k_ECallbackFlagsGameServer = 0x02 };
		uint8 m_nCallbackFlags;
		int m_iCallback;
		friend class CCallbackMgr;

	private:
		CCallbackBase(const CCallbackBase&);
		CCallbackBase& operator=(const CCallbackBase&);
	};

	//-----------------------------------------------------------------------------
	// Purpose: templated base for callbacks - internal implementation detail
	//-----------------------------------------------------------------------------
	template< int sizeof_P >
	class CCallbackImpl : protected CCallbackBase
	{
	public:
		virtual ~CCallbackImpl() { if (m_nCallbackFlags & k_ECallbackFlagsRegistered) SteamAPI_UnregisterCallback(this); }
		void SetGameserverFlag() { m_nCallbackFlags |= k_ECallbackFlagsGameServer; }

	protected:
		friend class CCallbackMgr;
		virtual void Run(void* pvParam) = 0;
		virtual void Run(void* pvParam, bool /*bIOFailure*/, SteamAPICall_t /*hSteamAPICall*/) { Run(pvParam); }
		virtual int GetCallbackSizeBytes() { return sizeof_P; }
	};


	//-----------------------------------------------------------------------------
	// Purpose: maps a steam async call result to a class member function
	//			template params: T = local class, P = parameter struct
	//-----------------------------------------------------------------------------
	template< class T, class P >
	class CCallResult : private CCallbackBase
	{
	public:
		typedef void (T::* func_t)(P*, bool);

		CCallResult();
		~CCallResult();

		void Set(SteamAPICall_t hAPICall, T* p, func_t func);
		bool IsActive() const;
		void Cancel();

		void SetGameserverFlag() { m_nCallbackFlags |= k_ECallbackFlagsGameServer; }
	private:
		virtual void Run(void* pvParam);
		virtual void Run(void* pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall);
		virtual int GetCallbackSizeBytes() { return sizeof(P); }

		SteamAPICall_t m_hAPICall;
		T* m_pObj;
		func_t m_Func;
	};



	//-----------------------------------------------------------------------------
	// Purpose: maps a steam callback to a class member function
	//			template params: T = local class, P = parameter struct,
	//			bGameserver = listen for gameserver callbacks instead of client callbacks
	//-----------------------------------------------------------------------------
	template< class T, class P, bool bGameserver = false >
	class CCallback : public CCallbackImpl< sizeof(P) >
	{
	public:
		typedef void (T::* func_t)(P*);

		// NOTE: If you can't provide the correct parameters at construction time, you should
		// use the CCallbackManual callback object (STEAM_CALLBACK_MANUAL macro) instead.
		CCallback(T* pObj, func_t func);

		void Register(T* pObj, func_t func);
		void Unregister();

	protected:
		virtual void Run(void* pvParam);

		T* m_pObj;
		func_t m_Func;
	};


	//-----------------------------------------------------------------------------
	// Purpose: subclass of CCallback which allows default-construction in
	//			an unregistered state; you must call Register manually
	//-----------------------------------------------------------------------------
	template< class T, class P, bool bGameServer = false >
	class CCallbackManual : public CCallback< T, P, bGameServer >
	{
	public:
		CCallbackManual() : CCallback< T, P, bGameServer >(nullptr, nullptr) {}

		// Inherits public Register and Unregister functions from base class
	};


	template< class T, class P >
	inline CCallResult<T, P>::CCallResult()
	{
		m_hAPICall = k_uAPICallInvalid;
		m_pObj = nullptr;
		m_Func = nullptr;
		m_iCallback = P::k_iCallback;
	}

	template< class T, class P >
	inline void CCallResult<T, P>::Set(SteamAPICall_t hAPICall, T* p, func_t func)
	{
		if (m_hAPICall)
			SteamAPI_UnregisterCallResult(this, m_hAPICall);

		m_hAPICall = hAPICall;
		m_pObj = p;
		m_Func = func;

		if (hAPICall)
			SteamAPI_RegisterCallResult(this, hAPICall);
	}

	template< class T, class P >
	inline bool CCallResult<T, P>::IsActive() const
	{
		return (m_hAPICall != k_uAPICallInvalid);
	}

	template< class T, class P >
	inline void CCallResult<T, P>::Cancel()
	{
		if (m_hAPICall != k_uAPICallInvalid)
		{
			SteamAPI_UnregisterCallResult(this, m_hAPICall);
			m_hAPICall = k_uAPICallInvalid;
		}
	}

	template< class T, class P >
	inline CCallResult<T, P>::~CCallResult()
	{
		Cancel();
	}

	template< class T, class P >
	inline void CCallResult<T, P>::Run(void* pvParam)
	{
		m_hAPICall = k_uAPICallInvalid; // caller unregisters for us
		(m_pObj->*m_Func)((P*)pvParam, false);
	}

	template< class T, class P >
	inline void CCallResult<T, P>::Run(void* pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall)
	{
		if (hSteamAPICall == m_hAPICall)
		{
			m_hAPICall = k_uAPICallInvalid; // caller unregisters for us
			(m_pObj->*m_Func)((P*)pvParam, bIOFailure);
		}
	}

	template< class T, class P, bool bGameserver >
	inline CCallback< T, P, bGameserver >::CCallback(T* pObj, func_t func)
		: m_pObj(nullptr), m_Func(nullptr)
	{
		if (bGameserver)
		{
			this->SetGameserverFlag();
		}
		Register(pObj, func);
	}

	template< class T, class P, bool bGameserver >
	inline void CCallback< T, P, bGameserver >::Register(T* pObj, func_t func)
	{
		if (!pObj || !func)
			return;

		if (this->m_nCallbackFlags & CCallbackBase::k_ECallbackFlagsRegistered)
			Unregister();

		m_pObj = pObj;
		m_Func = func;
		// SteamAPI_RegisterCallback sets k_ECallbackFlagsRegistered
		SteamAPI_RegisterCallback(this, P::k_iCallback);
	}

	template< class T, class P, bool bGameserver >
	inline void CCallback< T, P, bGameserver >::Unregister()
	{
		// SteamAPI_UnregisterCallback removes k_ECallbackFlagsRegistered
		SteamAPI_UnregisterCallback(this);
	}

	template< class T, class P, bool bGameserver >
	inline void CCallback< T, P, bGameserver >::Run(void* pvParam)
	{
		(m_pObj->*m_Func)((P*)pvParam);
	}

	//////////////////// CALL BACK MANAGER

	struct SteamAPICallCompleted_t
	{
		enum { k_iCallback = k_iSteamUtilsCallbacks + 3 };
		SteamAPICall_t m_hAsyncCall;
		int m_iCallback;
		uint32 m_cubParam;
	};


#define DEFAULT_CB_TIMEOUT 0.002

	class CCallbackMgr
	{
	public:
		static void SetRegister(class CCallbackBase* pCallback, int iCallback) {
			pCallback->m_nCallbackFlags |= CCallbackBase::k_ECallbackFlagsRegistered;
			pCallback->m_iCallback = iCallback;
		};

		static void SetUnregister(class CCallbackBase* pCallback) {
			if (pCallback)
				pCallback->m_nCallbackFlags &= !CCallbackBase::k_ECallbackFlagsRegistered;
		};

		static bool isServer(class CCallbackBase* pCallback) {
			return (pCallback->m_nCallbackFlags & CCallbackBase::k_ECallbackFlagsGameServer) != 0;
		};
	};

#define STEAM_CALLRESULT_TIMEOUT 120.0
#define STEAM_CALLRESULT_WAIT_FOR_CB 0.01

	static SteamAPICall_t nextCallID = 1;
	static SteamAPICall_t generate_steam_api_call_id() {
		return nextCallID++;
	}

	struct Steam_Call_Result {
		Steam_Call_Result(SteamAPICall_t a, int icb, void* r, unsigned int s, double r_in, bool run_cc_cb) {
			api_call = a;
			result.resize(s);
			if (s > 0 && r != NULL)
				memcpy(&(result[0]), r, s);
			created = std::chrono::high_resolution_clock::now();
			run_in = r_in;
			run_call_completed_cb = run_cc_cb;
			iCallback = icb;
		}

		bool operator==(const struct Steam_Call_Result& a)
		{
			return a.api_call == api_call && a.callbacks == callbacks;
		}

		bool HasTimedOut(std::chrono::high_resolution_clock::time_point old, double timeout)
		{
			if (timeout == 0.0) return true;

			std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
			if (std::chrono::duration_cast<std::chrono::duration<double>>(now - old).count() > timeout) {
				return true;
			}

			return false;
		}

		bool HasTimedOut() {
			return HasTimedOut(created, STEAM_CALLRESULT_TIMEOUT);
		}

		bool HasCallCompleted() {
			return (!reserved) && HasTimedOut(created, run_in);
		}

		bool CanExecute() {
			return (!to_delete) && HasCallCompleted() && (HasCallbacks() || HasTimedOut(created, STEAM_CALLRESULT_WAIT_FOR_CB));
		}

		bool HasCallbacks() {
			return callbacks.size() > 0;
		}

		SteamAPICall_t api_call;
		std::vector<class CCallbackBase*> callbacks;
		std::vector<char> result;
		bool to_delete = false;
		bool reserved = false;
		std::chrono::high_resolution_clock::time_point created;
		double run_in;
		bool run_call_completed_cb;
		int iCallback;
	};


	class SteamCallResults {
		std::vector<struct Steam_Call_Result> callresults{};
		std::vector<class CCallbackBase*> completed_callbacks{};
		void (*cb_all)(std::vector<char> result, int callback) = nullptr;

	public:
		void AddCallCompleted(class CCallbackBase* cb) {
			if (std::find(completed_callbacks.begin(), completed_callbacks.end(), cb) == completed_callbacks.end()) {
				completed_callbacks.push_back(cb);
			}
		}

		void RemoveCallCompleted(class CCallbackBase* cb) {
			auto c = std::find(completed_callbacks.begin(), completed_callbacks.end(), cb);
			if (c != completed_callbacks.end()) {
				completed_callbacks.erase(c);
			}
		}

		void AddCallback(SteamAPICall_t api_call, class CCallbackBase* cb) {
			auto cb_result = std::find_if(callresults.begin(), callresults.end(), [api_call](struct Steam_Call_Result const& item) { return item.api_call == api_call; });
			if (cb_result != callresults.end()) {
				cb_result->callbacks.push_back(cb);
				CCallbackMgr::SetRegister(cb, cb->GetICallback());
			}
		}

		bool HasCompleted(SteamAPICall_t api_call) {
			auto cr = std::find_if(callresults.begin(), callresults.end(), [api_call](struct Steam_Call_Result const& item) { return item.api_call == api_call; });
			if (cr == callresults.end()) return false;
			if (!cr->HasCallCompleted()) return false;
			return true;
		}

		bool GrabResult(SteamAPICall_t api_call, void* copy_to, unsigned int size) {
			auto cb_result = std::find_if(callresults.begin(), callresults.end(), [api_call](struct Steam_Call_Result const& item) { return item.api_call == api_call; });
			if (cb_result != callresults.end()) {
				if (!cb_result->HasCallCompleted()) return false;
				if (cb_result->result.size() > size) return false;

				memcpy(copy_to, &(cb_result->result[0]), cb_result->result.size());
				cb_result->to_delete = true;
				return true;
			}
			else {
				return false;
			}
		}

		void RemoveCallback(SteamAPICall_t api_call, class CCallbackBase* cb) {
			auto cb_result = std::find_if(callresults.begin(), callresults.end(), [api_call](struct Steam_Call_Result const& item) { return item.api_call == api_call; });
			if (cb_result != callresults.end()) {
				auto it = std::find(cb_result->callbacks.begin(), cb_result->callbacks.end(), cb);
				if (it != cb_result->callbacks.end()) {
					cb_result->callbacks.erase(it);
					CCallbackMgr::SetUnregister(cb);
				}
			}
		}

		void RemoveCallback(class CCallbackBase* cb) {
			//TODO: check if callback is callback or call result?
			for (auto& cr : callresults) {
				auto it = std::find(cr.callbacks.begin(), cr.callbacks.end(), cb);
				if (it != cr.callbacks.end()) {
					cr.callbacks.erase(it);
				}

				if (cr.callbacks.size() == 0) {
					cr.to_delete = true;
				}
			}
		}

		SteamAPICall_t AddCallResult(SteamAPICall_t api_call, int iCallback, void* result, unsigned int size, double timeout = DEFAULT_CB_TIMEOUT, bool run_call_completed_cb = true) {
			auto cb_result = std::find_if(callresults.begin(), callresults.end(), [api_call](struct Steam_Call_Result const& item) { return item.api_call == api_call; });
			if (cb_result != callresults.end()) {
				if (cb_result->reserved) {
					std::chrono::high_resolution_clock::time_point created = cb_result->created;
					std::vector<class CCallbackBase*> temp_cbs = cb_result->callbacks;
					*cb_result = Steam_Call_Result(api_call, iCallback, result, size, timeout, run_call_completed_cb);
					cb_result->callbacks = temp_cbs;
					cb_result->created = created;
					return cb_result->api_call;
				}
			}
			else {
				struct Steam_Call_Result res = Steam_Call_Result(api_call, iCallback, result, size, timeout, run_call_completed_cb);
				callresults.push_back(res);
				return callresults.back().api_call;
			}

			return 0;
		}

		SteamAPICall_t ReserveCallResult() {
			struct Steam_Call_Result res = Steam_Call_Result(generate_steam_api_call_id(), 0, NULL, 0, 0.0, true);
			res.reserved = true;
			callresults.push_back(res);
			return callresults.back().api_call;
		}

		SteamAPICall_t AddCallResult(int iCallback, void* result, unsigned int size, double timeout = DEFAULT_CB_TIMEOUT, bool run_call_completed_cb = true) {
			return AddCallResult(generate_steam_api_call_id(), iCallback, result, size, timeout, run_call_completed_cb);
		}

		void setCbAll(void (*_cb_all)(std::vector<char> result, int callback)) {
			this->cb_all = _cb_all;
		}

		void RunCallResults() {
			unsigned long current_size = callresults.size();
			for (unsigned i = 0; i < current_size; ++i) {
				unsigned index = i;

				if (!callresults[index].to_delete) {
					if (callresults[index].CanExecute()) {
						std::vector<char> result = callresults[index].result;
						SteamAPICall_t api_call = callresults[index].api_call;
						bool run_call_completed_cb = callresults[index].run_call_completed_cb;
						int iCallback = callresults[index].iCallback;
						if (run_call_completed_cb) {
							callresults[index].run_call_completed_cb = false;
						}

						callresults[index].to_delete = true;
						if (callresults[index].HasCallbacks()) {
							std::vector<class CCallbackBase*> temp_cbs = callresults[index].callbacks;
							for (auto& cb : temp_cbs) {
								globalMutex.unlock();
								//TODO: unlock relock doesn't work if mutex was locked more than once.
								if (run_call_completed_cb) { //run the right function depending on if it's a callback or a call result.
									cb->Run(&(result[0]), false, api_call);
								}
								else {
									cb->Run(&(result[0]));
								}
								//COULD BE DELETED SO DON'T TOUCH CB
								globalMutex.lock();
							}
						}

						if (run_call_completed_cb) {
							//can it happen that one is removed during the callback?
							std::vector<class CCallbackBase*> completedCallbacks = completed_callbacks;
							SteamAPICallCompleted_t data;
							data.m_hAsyncCall = api_call;
							data.m_iCallback = iCallback;
							data.m_cubParam = result.size();

							for (auto& cb : completedCallbacks) {
								//TODO: check if this is a problem or not.
								SteamAPICallCompleted_t temp = data;
								globalMutex.unlock();
								cb->Run(&temp);
								globalMutex.lock();
							}

							if (cb_all) {
								std::vector<char> res;
								res.resize(sizeof(data));
								memcpy(&(res[0]), &data, sizeof(data));
								cb_all(res, data.k_iCallback);
							}
						}
						else {
							if (cb_all) {
								cb_all(result, iCallback);
							}
						}
					}
					else {
						if (callresults[index].HasTimedOut()) {
							callresults[index].to_delete = true;
						}
					}
				}
			}

			auto c = std::begin(callresults);
			while (c != std::end(callresults)) {
				if (c->to_delete) {
					if (c->HasTimedOut()) {
						c = callresults.erase(c);
					}
					else {
						++c;
					}
				}
				else {
					++c;
				}
			}
		}
	};


	struct Steam_Call_Back {
		std::vector<class CCallbackBase*> callbacks;
		std::vector<std::vector<char>> results;
	};

	class SteamCallBacks {
		std::map<int, struct Steam_Call_Back> callbacks;
		SteamCallResults* results;
	public:
		SteamCallBacks(SteamCallResults* results) {
			this->results = results;
		}

		void AddCallback(int iCallback, class CCallbackBase* cb) {
			if (iCallback == SteamAPICallCompleted_t::k_iCallback) {
				results->AddCallCompleted(cb);
				CCallbackMgr::SetRegister(cb, iCallback);
				return;
			}

			if (std::find(callbacks[iCallback].callbacks.begin(), callbacks[iCallback].callbacks.end(), cb) == callbacks[iCallback].callbacks.end()) {
				callbacks[iCallback].callbacks.push_back(cb);
				CCallbackMgr::SetRegister(cb, iCallback);
				for (auto& res : callbacks[iCallback].results) {
					//TODO: timeout?
					SteamAPICall_t api_id = results->AddCallResult(iCallback, &(res[0]), res.size(), 0.0, false);
					results->AddCallback(api_id, cb);
				}
			}
		}

		void AddCallbackResult(int iCallback, void* result, unsigned int size, double timeout, bool dont_post_if_already) {
			if (dont_post_if_already) {
				for (auto& r : callbacks[iCallback].results) {
					if (r.size() == size) {
						if (memcmp(&(r[0]), result, size) == 0) {
							//cb already posted
							return;
						}
					}
				}
			}

			std::vector<char> temp;
			temp.resize(size);
			memcpy(&(temp[0]), result, size);
			callbacks[iCallback].results.push_back(temp);
			for (auto cb : callbacks[iCallback].callbacks) {
				SteamAPICall_t api_id = results->AddCallResult(iCallback, result, size, timeout, false);
				results->AddCallback(api_id, cb);
			}

			if (callbacks[iCallback].callbacks.empty()) {
				results->AddCallResult(iCallback, result, size, timeout, false);
			}
		}

		void AddCallbackResult(int iCallback, void* result, unsigned int size) {
			AddCallbackResult(iCallback, result, size, DEFAULT_CB_TIMEOUT, false);
		}

		void AddCallbackResult(int iCallback, void* result, unsigned int size, bool dont_post_if_already) {
			AddCallbackResult(iCallback, result, size, DEFAULT_CB_TIMEOUT, dont_post_if_already);
		}

		void AddCallbackResult(int iCallback, void* result, unsigned int size, double timeout) {
			AddCallbackResult(iCallback, result, size, timeout, false);
		}

		void RemoveCallback(int iCallback, class CCallbackBase* cb) {
			if (iCallback == SteamAPICallCompleted_t::k_iCallback) {
				results->RemoveCallCompleted(cb);
				CCallbackMgr::SetUnregister(cb);
				return;
			}

			auto c = std::find(callbacks[iCallback].callbacks.begin(), callbacks[iCallback].callbacks.end(), cb);
			if (c != callbacks[iCallback].callbacks.end()) {
				callbacks[iCallback].callbacks.erase(c);
				CCallbackMgr::SetUnregister(cb);
				results->RemoveCallback(cb);
			}
		}

		void RunCallbacks() {
			for (auto& c : callbacks) {
				c.second.results.clear();
			}
		}
	};
}