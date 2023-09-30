#pragma once

namespace Steam
{
	//====== Copyright © 1996-2008, Valve Corporation, All rights reserved. =======
	//
	// Purpose: interface to app data in Steam
	//
	//=============================================================================

	// STEAMAPPS_INTERFACE_VERSION005

	const int k_cubAppProofOfPurchaseKeyMax = 240;			// max supported length of a legacy cd key 
	enum { k_iSteamAppsCallbacks = 1000 };

	class Apps
	{
	public:

		virtual bool BIsSubscribed();
		virtual bool BIsLowViolence();
		virtual bool BIsCybercafe();
		virtual bool BIsVACBanned();
		virtual const char* GetCurrentGameLanguage();
		virtual const char* GetAvailableGameLanguages();

		// only use this member if you need to check ownership of another game related to yours, a demo for example
		virtual bool BIsSubscribedApp(AppId_t appID);

		// Takes AppID of DLC and checks if the user owns the DLC & if the DLC is installed
		virtual bool BIsDlcInstalled(AppId_t appID);

		// returns the Unix time of the purchase of the app
		virtual unsigned int GetEarliestPurchaseUnixTime(AppId_t nAppID);

		// Checks if the user is subscribed to the current app through a free weekend
		// This function will return false for users who have a retail or other type of license
		// Before using, please ask your Valve technical contact how to package and secure your free weekened
		virtual bool BIsSubscribedFromFreeWeekend();

		// Returns the number of DLC pieces for the running app
		virtual int GetDLCCount();

		// Returns metadata for DLC by index, of range [0, GetDLCCount()]
		virtual bool BGetDLCDataByIndex(int iDLC, AppId_t* pAppID, bool* pbAvailable, char* pchName, int cchNameBufferSize);

		// Install/Uninstall control for optional DLC
		virtual void InstallDLC(AppId_t nAppID);
		virtual void UninstallDLC(AppId_t nAppID);

		// Request cd-key for yourself or owned DLC. If you are interested in this
		// data then make sure you provide us with a list of valid keys to be distributed
		// to users when they purchase the game, before the game ships.
		// You'll receive an AppProofOfPurchaseKeyResponse_t callback when
		// the key is available (which may be immediately).
		virtual void RequestAppProofOfPurchaseKey(AppId_t nAppID);

		virtual bool GetCurrentBetaName(char* pchName, int cchNameBufferSize); // returns current beta branch name, 'public' is the default branch
		virtual bool MarkContentCorrupt(bool bMissingFilesOnly); // signal Steam that game files seems corrupt or missing
		virtual unsigned int GetInstalledDepots(DepotId_t* pvecDepots, unsigned int cMaxDepots); // return installed depots in mount order

		// returns current app install folder for AppID, returns folder name length
		virtual unsigned int GetAppInstallDir(AppId_t appID, char* pchFolder, unsigned int cchFolderBufferSize);
		virtual bool BIsAppInstalled(AppId_t appID);
	};

	//-----------------------------------------------------------------------------
	// Purpose: posted after the user gains ownership of DLC & that DLC is installed
	//-----------------------------------------------------------------------------
	struct DlcInstalled_t
	{
		enum { k_iCallback = k_iSteamAppsCallbacks + 5 };
		unsigned int m_nAppID;		// AppID of the DLC
	};


	//-----------------------------------------------------------------------------
	// Purpose: possible results when registering an activation code
	//-----------------------------------------------------------------------------
	enum ERegisterActivationCodeResult
	{
		k_ERegisterActivationCodeResultOK = 0,
		k_ERegisterActivationCodeResultFail = 1,
		k_ERegisterActivationCodeResultAlreadyRegistered = 2,
		k_ERegisterActivationCodeResultTimeout = 3,
		k_ERegisterActivationCodeAlreadyOwned = 4,
	};


	//-----------------------------------------------------------------------------
	// Purpose: response to RegisterActivationCode()
	//-----------------------------------------------------------------------------
	struct RegisterActivationCodeResponse_t
	{
		enum { k_iCallback = k_iSteamAppsCallbacks + 8 };
		ERegisterActivationCodeResult m_eResult;
		unsigned int m_unPackageRegistered;						// package that was registered. Only set on success
	};


	//---------------------------------------------------------------------------------
	// Purpose: posted after the user gains executes a steam url with query parameters
	// such as steam://run/<appid>//?param1=value1;param2=value2;param3=value3; etc
	// while the game is already running.  The new params can be queried
	// with GetLaunchQueryParam.
	//---------------------------------------------------------------------------------
	struct NewLaunchQueryParameters_t
	{
		enum { k_iCallback = k_iSteamAppsCallbacks + 14 };
	};


	//-----------------------------------------------------------------------------
	// Purpose: response to RequestAppProofOfPurchaseKey/RequestAllProofOfPurchaseKeys
	// for supporting third-party CD keys, or other proof-of-purchase systems.
	//-----------------------------------------------------------------------------
	struct AppProofOfPurchaseKeyResponse_t
	{
		enum { k_iCallback = k_iSteamAppsCallbacks + 21 };
		unsigned int m_eResult;
		unsigned int	m_nAppID;
		unsigned int	m_cchKeyLength;
		char	m_rgchKey[k_cubAppProofOfPurchaseKeyMax];
	};


	//-----------------------------------------------------------------------------
	// Purpose: response to GetFileDetails
	//-----------------------------------------------------------------------------
	struct FileDetailsResult_t
	{
		enum { k_iCallback = k_iSteamAppsCallbacks + 23 };
		unsigned int		m_eResult;
		uint64		m_ulFileSize;	// original file size in bytes
		uint8		m_FileSHA[20];	// original file SHA1 hash
		unsigned int		m_unFlags;		// 
	};
}
