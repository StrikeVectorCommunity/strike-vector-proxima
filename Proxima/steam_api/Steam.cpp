#include "pch.h"

namespace Steam
{
	SteamAPICall_t Callbacks::CallID = 0;
	std::map<SteamAPICall_t, bool> Callbacks::Calls;
	std::map<SteamAPICall_t, Callbacks::Base*> Callbacks::ResultHandlers;
	std::vector<Callbacks::Result> Callbacks::Results;
	std::vector<Callbacks::Base*> Callbacks::CallbackList;
	std::recursive_mutex Callbacks::Mutex;

	SteamAPICall_t Callbacks::RegisterCall()
	{
		std::lock_guard<std::recursive_mutex> _(Callbacks::Mutex);
		Callbacks::Calls[++Callbacks::CallID] = false;
		return Callbacks::CallID;
	}

	void Callbacks::RegisterCallback(Callbacks::Base* handler, int callback)
	{
		std::lock_guard<std::recursive_mutex> _(Callbacks::Mutex);
		handler->SetICallback(callback);
		Callbacks::CallbackList.push_back(handler);
	}

	void Callbacks::RegisterCallResult(SteamAPICall_t call, Callbacks::Base* result)
	{
		std::lock_guard<std::recursive_mutex> _(Callbacks::Mutex);
		Callbacks::ResultHandlers[call] = result;
	}

	void Callbacks::ReturnCall(void* data, int size, int type, SteamAPICall_t call)
	{
		std::lock_guard<std::recursive_mutex> _(Callbacks::Mutex);

		Callbacks::Result result{};

		Logger::Print("Returning call {} of type {} with data ptr {} (length={})", call, type, reinterpret_cast<int>(data), size);

		Callbacks::Calls[call] = true;

		result.call = call;
		result.data = malloc(size); // This will get freed later during result handling
		std::memcpy(result.data, data, size);

		result.size = size;
		result.type = type;
		
		Logger::Print("Pushing back results ({} results already)", Results.size());
		Callbacks::Results.push_back(result);
	}

	void Callbacks::RunCallbacks()
	{
		std::lock_guard<std::recursive_mutex> _(Callbacks::Mutex);

		auto results = Callbacks::Results;
		Callbacks::Results.clear();

		for (auto result : results)
		{
			if (Callbacks::ResultHandlers.find(result.call) != Callbacks::ResultHandlers.end())
			{
				Callbacks::ResultHandlers[result.call]->Run(result.data, false, result.call);
			}

			for (auto callback : Callbacks::CallbackList)
			{
				if (callback && callback->GetICallback() == result.type)
				{
					Logger::Print("Running callback on result type {}!", result.type);
					callback->Run(result.data, false, 0);
				}
			}

			if (result.data)
			{
				Logger::Print("Freeing result data for result type {}", result.type);
				free(result.data);
			}
		}
	}

	void Callbacks::RunCallback(int32_t callback, void* data)
	{
		std::lock_guard<std::recursive_mutex> _(Callbacks::Mutex);

		for (auto cb : Callbacks::CallbackList)
		{
			if (cb && cb->GetICallback() == callback)
			{
				cb->Run(data);
			}
		}
	}

	void Callbacks::Uninitialize()
	{
		std::lock_guard<std::recursive_mutex> _(Callbacks::Mutex);

		for (auto result : Callbacks::Results)
		{
			if (result.data)
			{
				free(result.data);
			}
		}

		Callbacks::Results.clear();
	}

	bool Enabled()
	{
		return false;
	}

	extern "C"
	{
		bool SteamAPI_Init()
		{
			//Proxy::SetGame(10190);

			//if (!Proxy::Inititalize())
			//{
			//	OutputDebugStringA("Steam proxy not initialized properly");
			//}
			//else
			//{
			//	Proxy::SetMod("IW4x: Modern Warfare 2");
			//	Proxy::RunGame();
			//}

			return true;
		}

		void SteamAPI_RegisterCallResult(Callbacks::Base* result, SteamAPICall_t call)
		{
			Callbacks::RegisterCallResult(call, result);
		}

		void SteamAPI_RegisterCallback(Callbacks::Base* handler, int callback)
		{
			Callbacks::RegisterCallback(handler, callback);
		}

		void SteamAPI_RunCallbacks()
		{
			Callbacks::RunCallbacks();
			Proxima::Client::RunFrame();
		}

		void SteamAPI_Shutdown()
		{
			//Proxy::Uninititalize();
			Callbacks::Uninitialize();
		}

		void SteamAPI_UnregisterCallResult(Callbacks::Base* result, SteamAPICall_t call)
		{
			DUMP_FUNC_NAME();
		}

		void SteamAPI_UnregisterCallback(Callbacks::Base* result)
		{
			DUMP_FUNC_NAME();
		}

		bool SteamGameServer_Init(uint32 unIP, uint16 usSteamPort, uint16 usGamePort, uint16 usQueryPort, EServerMode eServerMode, const char* pchVersionString)
		{
			DUMP_FUNC_NAME();
			return true;

			/*bool ret = SteamInternal_GameServer_Init( unIP, usSteamPort, usGamePort, usQueryPort, serverMode, pchVersionString );
			if (logon_anon) {
				get_steam_client()->steam_gameserver->LogOnAnonymous();
			}

			return ret;*/
		}

		void SteamGameServer_RunCallbacks()
		{
		}

		void SteamGameServer_Shutdown()
		{
			DUMP_FUNC_NAME();
		}

		bool SteamGameServer_BSecure()
		{
			DUMP_FUNC_NAME();
			return true;
		}

		uint64 SteamGameServer_GetSteamID()
		{
			DUMP_FUNC_NAME();
			return 1;
		}


		Steam::Friends* SteamFriends()
		{
			return SteamClient()->GetISteamFriends(SteamAPI_GetHSteamUser(), SteamAPI_GetHSteamPipe(), nullptr);
		}

		Steam::Matchmaking* SteamMatchmaking()
		{
			return SteamClient()->GetISteamMatchmaking(SteamAPI_GetHSteamUser(), SteamAPI_GetHSteamPipe(), nullptr);
		}

		Steam::GameServer* SteamGameServer()
		{
			return SteamClient()->GetISteamGameServer(SteamAPI_GetHSteamUser(), SteamAPI_GetHSteamPipe(), nullptr);
		}

		Steam::Networking* SteamNetworking()
		{
			return SteamClient()->GetISteamNetworking(SteamAPI_GetHSteamUser(), SteamAPI_GetHSteamPipe(), nullptr);
		}

		Steam::Networking* SteamGameServerNetworking()
		{
			return SteamClient()->GetISteamNetworking(SteamAPI_GetHSteamUser(), SteamAPI_GetHSteamPipe(), nullptr);
		}

		Steam::RemoteStorage* SteamRemoteStorage()
		{
			return SteamClient()->GetISteamRemoteStorage(SteamAPI_GetHSteamUser(), SteamAPI_GetHSteamPipe(), nullptr);
		}

		Steam::User* SteamUser()
		{
			return SteamClient()->GetISteamUser(SteamAPI_GetHSteamUser(), SteamAPI_GetHSteamPipe(), nullptr);
		}

		Steam::Utils* SteamUtils()
		{
			return SteamClient()->GetISteamUtils(SteamAPI_GetHSteamPipe(), nullptr);

		}
		Steam::Client* SteamClient()
		{
			static Steam::Client iClient;
			return &iClient;
		}
		HSteamPipe SteamAPI_GetHSteamPipe()
		{
			return HSteamPipe();
		}
		HSteamUser SteamAPI_GetHSteamUser()
		{
			return NULL;
		}
		Steam::Apps* SteamApps()
		{
			return SteamClient()->GetISteamApps(SteamAPI_GetHSteamUser(), SteamAPI_GetHSteamPipe(), nullptr);
		}

		Steam::MatchmakingServers* SteamMatchmakingServers()
		{
			return SteamClient()->GetISteamMatchmakingServers(SteamAPI_GetHSteamUser(), SteamAPI_GetHSteamPipe(), nullptr);
		}

		Steam::UserStats* SteamUserStats()
		{
			return SteamClient()->GetISteamUserStats(SteamAPI_GetHSteamUser(), SteamAPI_GetHSteamPipe(), nullptr);
		}

		Steam::GameServerStats* SteamGameServerStats()
		{
			return SteamClient()->GetISteamGameServerStats(SteamAPI_GetHSteamUser(), SteamAPI_GetHSteamPipe(), nullptr);
		}
	}
}
