#include "pch.h"
#include "SteamUser.hpp"

STEAM_IGNORE_WARNINGS_START

namespace Steam
{
	int User::GetHSteamUser()
	{
		DUMP_FUNC_NAME();
		return NULL;
	}

	bool User::BLoggedOn()
	{
		DUMP_FUNC_NAME();
		return true;
	}

	CSteamID User::GetSteamID()
	{
		return Proxima::Client::GetSteamID();
	}

	int User::InitiateGameConnection( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure)
	{
		DUMP_FUNC_NAME();
		//Components::Logger::Print("%s\n", __FUNCTION__);
		return 0;
	}


	void User::TerminateGameConnection(uint32 unIPServer, uint16 usPortServer)
	{
		DUMP_FUNC_NAME();
	}

	void User::TrackAppUsageEvent(CGameID gameID, int eAppUsageEvent, const char* pchExtraInfo)
	{
		DUMP_FUNC_NAME();
	}

	bool User::GetUserDataFolder(char *pchBuffer, int cubBuffer)
	{
		DUMP_FUNC_NAME();
		return false;
	}

	void User::StartVoiceRecording()
	{
		DUMP_FUNC_NAME();
	}

	void User::StopVoiceRecording()
	{
		DUMP_FUNC_NAME();
	}

	EVoiceResult User::GetAvailableVoice(uint32* pcbCompressed, uint32* pcbUncompressed, uint32 nUncompressedVoiceDesiredSampleRate)
	{
		return EVoiceResult::k_EVoiceResultNoData;
	}

	EVoiceResult User::GetVoice(bool bWantCompressed, void* pDestBuffer, uint32 cbDestBufferSize, uint32* nBytesWritten, bool bWantUncompressed, void* pUncompressedDestBuffer, uint32 cbUncompressedDestBufferSize, uint32* nUncompressBytesWritten, uint32 nUncompressedVoiceDesiredSampleRate)
	{
		return EVoiceResult::k_EVoiceResultNoData;
	}

	EVoiceResult User::DecompressVoice(const void* pCompressed, uint32 cbCompressed, void* pDestBuffer, uint32 cbDestBufferSize, uint32* nBytesWritten, uint32 nDesiredSampleRate)
	{
		return EVoiceResult::k_EVoiceResultNoData;
	}

	uint32 User::GetVoiceOptimalSampleRate()
	{
		DUMP_FUNC_NAME();
		return 0;
	}

	HAuthTicket User::GetAuthSessionTicket(void* pTicket, int cbMaxTicket, uint32* pcbTicket)
	{
		DUMP_FUNC_NAME();
		return Proxima::Auth::GenerateTicket(pTicket, cbMaxTicket, pcbTicket);
	}

	EBeginAuthSessionResult User::BeginAuthSession(const void *pAuthTicket, int cbAuthTicket, CSteamID steamID)
	{
		DUMP_FUNC_NAME();
		return Proxima::Auth::BeginAuth(pAuthTicket, cbAuthTicket, steamID);
	}

	void User::EndAuthSession(CSteamID steamID)
	{
		DUMP_FUNC_NAME();
		Proxima::Auth::EndAuth(steamID);
	}

	bool User::BIsBehindNAT()
	{
		DUMP_FUNC_NAME();
		return false;
	}

	void User::AdvertiseGame(CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer)
	{
		DUMP_FUNC_NAME();
	}

	SteamAPICall_t User::RequestEncryptedAppTicket(void* pUserData, int cbUserData)
	{
		DUMP_FUNC_NAME();
		return 0;
	}

	bool User::GetEncryptedAppTicket(void* pTicket, int cbMaxTicket, uint32* pcbTicket)
	{
		DUMP_FUNC_NAME();
		return false;
	}

	void User::CancelAuthTicket(unsigned int hAuthTicket)
	{
		DUMP_FUNC_NAME();
		Proxima::Auth::CancelTicket(hAuthTicket);
	}

	EUserHasLicenseForAppResult User::UserHasLicenseForApp(CSteamID steamID, AppId_t appID)
	{
		return EUserHasLicenseForAppResult::k_EUserHasLicenseResultHasLicense;
	}
}

STEAM_IGNORE_WARNINGS_END
