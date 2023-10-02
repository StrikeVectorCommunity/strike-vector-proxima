#include "pch.h"
#include "SteamUtils.hpp"

STEAM_IGNORE_WARNINGS_START

namespace Steam
{
	unsigned int Utils::GetSecondsSinceAppActive()
	{
		//return Game::Sys_Milliseconds() / 1000;
		return 0;
	}

	unsigned int Utils::GetSecondsSinceComputerActive()
	{
		//return timeGetTime();
		return 0;
	}

	EUniverse Utils::GetConnectedUniverse()
	{
		return EUniverse::k_EUniversePublic;
	}

	unsigned int Utils::GetServerRealTime()
	{
		DUMP_FUNC_NAME();
		uint32 server_time = std::chrono::duration_cast<std::chrono::duration<uint32>>(std::chrono::system_clock::now().time_since_epoch()).count();
		return server_time;
	}

	const char* Utils::GetIPCountry()
	{
		return "US";
	}

	bool Utils::GetImageSize(int iImage, unsigned int *pnWidth, unsigned int *pnHeight)
	{
		return false;
	}

	bool Utils::GetImageRGBA(int iImage, unsigned char *pubDest, int nDestBufferSize)
	{
		return false;
	}

	bool Utils::GetCSERIPPort(unsigned int *unIP, unsigned short *usPort)
	{
		DUMP_FUNC_NAME();
		return false;
	}

	unsigned char Utils::GetCurrentBatteryPower()
	{
		return 255;
	}

	unsigned int Utils::GetAppID()
	{
		return STRIKE_VECTOR_APPID;
	}

	void Utils::SetOverlayNotificationPosition(ENotificationPosition eNotificationPosition)
	{
		//Proxy::SetOverlayNotificationPosition(eNotificationPosition);
	}

	bool Utils::IsAPICallCompleted(SteamAPICall_t hSteamAPICall, bool *pbFailed)
	{
		DUMP_FUNC_NAME();
		return true;
	}

	ESteamAPICallFailure Utils::GetAPICallFailureReason(SteamAPICall_t hSteamAPICall)
	{
		DUMP_FUNC_NAME();
		return ESteamAPICallFailure::k_ESteamAPICallFailureNone;
	}

	bool Utils::GetAPICallResult(SteamAPICall_t hSteamAPICall, void *pCallback, int cubCallback, int iCallbackExpected, bool *pbFailed)
	{
		DUMP_FUNC_NAME();
		return false;
	}

	void Utils::RunFrame()
	{
	}

	unsigned int Utils::GetIPCCallCount()
	{
		DUMP_FUNC_NAME();
		return 0;
	}

	void Utils::SetWarningMessageHook(SteamAPIWarningMessageHook_t)
	{
	}

	bool Utils::IsOverlayEnabled()
	{
		return false;
	}

	bool Utils::BOverlayNeedsPresent()
	{
		return false;
	}

	SteamAPICall_t Utils::CheckFileSignature(const char* szFileName)
	{
		return SteamAPICall_t();
	}

	bool Utils::ShowGamepadTextInput(EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, const char* pchDescription, unsigned int unCharMax)
	{
		return false;
	}
	unsigned int Utils::GetEnteredGamepadTextLength()
	{
		return 0;
	}
	bool Utils::GetEnteredGamepadTextInput(char* pchText, unsigned int cchText)
	{
		return false;
	}
}

STEAM_IGNORE_WARNINGS_END
