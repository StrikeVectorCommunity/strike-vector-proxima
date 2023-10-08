#include "pch.h"

namespace Steam
{
	Callbacks::Callbacks()
	{
		resultsClient = new SteamCallResults();
		resultsServer = new SteamCallResults();

		callbacksClient = new SteamCallBacks(GetResultsClient());
		callbacksServer = new SteamCallBacks(GetResultsServer());
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

		void SteamAPI_RegisterCallResult(CCallbackBase* result, SteamAPICall_t call)
		{
			std::lock_guard<std::recursive_mutex> lock(globalMutex);
			Steam::callbacks->GetResultsClient()->AddCallback(call, result);
			Steam::callbacks->GetResultsServer()->AddCallback(call, result);
		}

		void SteamAPI_RegisterCallback(class CCallbackBase* pCallback, int iCallback)
		{
			bool isGameServer = CCallbackMgr::isServer(pCallback);
			if (isGameServer) {
				Steam::callbacks->GetServer()->AddCallback(iCallback, pCallback);
			}
			else {
				Steam::callbacks->GetClient()->AddCallback(iCallback, pCallback);
			}
		}

		void SteamAPI_RunCallbacks()
		{
			Proxima::Client::RunFrame();
		}

		void SteamAPI_Shutdown()
		{
			//Proxy::Uninititalize();
			DUMP_FUNC_NAME();
		}

		void SteamAPI_UnregisterCallResult(class CCallbackBase* pCallback, SteamAPICall_t hAPICall)
		{
			DUMP_FUNC_NAME();
			if (!hAPICall)
				return;

			std::lock_guard<std::recursive_mutex> lock(globalMutex);
			Steam::callbacks->GetResultsClient()->RemoveCallback(hAPICall, pCallback);
			Steam::callbacks->GetResultsServer()->RemoveCallback(hAPICall, pCallback);
		}

		void SteamAPI_UnregisterCallback(class CCallbackBase* pCallback)
		{
			int iCallback = pCallback->GetICallback();
			bool isGameServer = CCallbackMgr::isServer(pCallback);
			if (isGameServer) {
				Steam::callbacks->GetServer()->RemoveCallback(iCallback, pCallback);
			}
			else {
				Steam::callbacks->GetClient()->RemoveCallback(iCallback, pCallback);
			}
		}

		bool SteamGameServer_Init(uint32 unIP, uint16 usSteamPort, uint16 usGamePort, uint16 usQueryPort, EServerMode eServerMode, const char* pchVersionString)
		{
			Logger::Print("Initialized steam game server:\nIP:{}\nPort:{}\nMode:{}\nVersion:{}", unIP, usGamePort, static_cast<int>(eServerMode), pchVersionString);
			return true;

			/*bool ret = SteamInternal_GameServer_Init( unIP, usSteamPort, usGamePort, usQueryPort, serverMode, pchVersionString );
			if (logon_anon) {
				get_steam_client()->steam_gameserver->LogOnAnonymous();
			}

			return ret;*/
		}

		void SteamGameServer_RunCallbacks()
		{
			Proxima::Server::RunFrame();
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
			return SteamClient()->GetISteamGameServer(SteamAPI_GetHSteamPipe(), SteamAPI_GetHSteamUser(), nullptr)->GetSteamID().m_unAll64Bits;
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
			return 1;
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
