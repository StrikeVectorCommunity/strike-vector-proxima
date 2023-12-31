#include "pch.h"
#include "SteamClient.hpp"

STEAM_IGNORE_WARNINGS_START

namespace Steam
{
	HSteamPipe Client::CreateSteamPipe()
	{
		DUMP_FUNC_NAME();
		return HSteamPipe();
	}
	bool Client::BReleaseSteamPipe(HSteamPipe hSteamPipe)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	HSteamUser Client::ConnectToGlobalUser(HSteamPipe hSteamPipe)
	{
		DUMP_FUNC_NAME();
		return HSteamUser();
	}
	HSteamUser Client::CreateLocalUser(HSteamPipe* phSteamPipe, EAccountType eAccountType)
	{
		DUMP_FUNC_NAME();
		return HSteamUser();
	}
	void Client::ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hUser)
	{
		DUMP_FUNC_NAME();
	}

	Steam::User* Client::GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char* pchVersion)
	{
		DUMP_FUNC_NAME();

		static Steam::User i;
		return &i;
	}
	Steam::GameServer* Client::GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char* pchVersion)
	{
		DUMP_FUNC_NAME();

		static Steam::GameServer i;
		return &i;
	}
	void Client::SetLocalIPBinding(uint32 unIP, uint16 usPort)
	{
		DUMP_FUNC_NAME();
	}

	Steam::Friends* Client::GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char* pchVersion)
	{
		DUMP_FUNC_NAME();

		static Steam::Friends i;
		return &i;
	}
	Steam::Utils* Client::GetISteamUtils(HSteamPipe hSteamPipe, const char* pchVersion)
	{
		DUMP_FUNC_NAME();

		static Steam::Utils i;
		return &i;
	}
	Steam::Matchmaking* Client::GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char* pchVersion)
	{
		DUMP_FUNC_NAME();

		static Steam::Matchmaking i;
		return &i;
	}
	Steam::MatchmakingServers* Client::GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char* pchVersion)
	{
		DUMP_FUNC_NAME();

		static Steam::MatchmakingServers i;
		return &i;
	}
	void* Client::GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char* pchVersion)
	{
		DUMP_FUNC_NAME();

		OutputDebugStringA(pchVersion);
		return nullptr;
	}
	Steam::UserStats* Client::GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char* pchVersion)
	{
		DUMP_FUNC_NAME();

		static Steam::UserStats i;
		return &i;
	}
	Steam::GameServerStats* Client::GetISteamGameServerStats(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char* pchVersion)
	{
		DUMP_FUNC_NAME();

		static Steam::GameServerStats i;
		return &i;
	}
	Steam::Apps* Client::GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char* pchVersion)
	{
		DUMP_FUNC_NAME();

		static Steam::Apps i;
		return &i;
	}
	Steam::Networking* Client::GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char* pchVersion)
	{
		DUMP_FUNC_NAME();

		static Steam::Networking i;
		return &i;
	}
	Steam::RemoteStorage* Client::GetISteamRemoteStorage(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char* pchVersion)
	{
		DUMP_FUNC_NAME();

		static Steam::RemoteStorage i;
		return &i;
	}
	Steam::Screenshots* Client::GetISteamScreenshots(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char* pchVersion)
	{
		DUMP_FUNC_NAME();

		static Steam::Screenshots i;
		return &i;
	}

	void Client::RunFrame()
	{
	}

	uint32 Client::GetIPCCallCount()
	{
		DUMP_FUNC_NAME();
		return uint32();
	}

	void Client::SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction)
	{
		DUMP_FUNC_NAME();
	}

	bool Client::BShutdownIfAllPipesClosed()
	{
		DUMP_FUNC_NAME();
		return false;
	}
}

STEAM_IGNORE_WARNINGS_END
