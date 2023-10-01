#include "pch.h"
#include "SteamUser.hpp"

STEAM_IGNORE_WARNINGS_START

namespace Steam
{
	int User::GetHSteamUser()
	{
		return NULL;
	}

	bool User::BLoggedOn()
	{
		return true;
	}

	CSteamID User::GetSteamID()
	{
		return Proxima::Client::GetSteamID();
	}

	int User::InitiateGameConnection( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure)
	{
		//Components::Logger::Print("%s\n", __FUNCTION__);
		return 0;
	}


	void User::TerminateGameConnection(uint32 unIPServer, uint16 usPortServer)
	{
	}

	void User::TrackAppUsageEvent(CGameID gameID, int eAppUsageEvent, const char* pchExtraInfo)
	{
	}

	bool User::GetUserDataFolder(char *pchBuffer, int cubBuffer)
	{
		return false;
	}

	void User::StartVoiceRecording()
	{
	}

	void User::StopVoiceRecording()
	{
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
		return 0;
	}

	HAuthTicket User::GetAuthSessionTicket(void* pTicket, int cbMaxTicket, uint32* pcbTicket)
	{
		return HAuthTicket();
	}

	EBeginAuthSessionResult User::BeginAuthSession(const void *pAuthTicket, int cbAuthTicket, CSteamID steamID)
	{
		return EBeginAuthSessionResult::k_EBeginAuthSessionResultOK;
	}

	void User::EndAuthSession(CSteamID steamID)
	{
	}

	bool User::BIsBehindNAT()
	{
		return false;
	}

	void User::AdvertiseGame(CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer)
	{
	}

	SteamAPICall_t User::RequestEncryptedAppTicket(void* pUserData, int cbUserData)
	{
		return 0;
	}

	bool User::GetEncryptedAppTicket(void* pTicket, int cbMaxTicket, uint32* pcbTicket)
	{
		return false;
	}

	void User::CancelAuthTicket(unsigned int hAuthTicket)
	{
	}

	EUserHasLicenseForAppResult User::UserHasLicenseForApp(CSteamID steamID, AppId_t appID)
	{
		return EUserHasLicenseForAppResult::k_EUserHasLicenseResultHasLicense;
	}
}

STEAM_IGNORE_WARNINGS_END
