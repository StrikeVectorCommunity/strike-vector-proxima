#pragma once

#define STEAM_EXPORT extern "C" __declspec(dllexport)
#define CALL_RESULT(RESULT_TYPE) CLANG_ATTR("callresult:" #RESULT_TYPE ";")

#define STEAM_IGNORE_WARNINGS_START __pragma(warning(push)) \
                                    __pragma(warning(disable: 4100))

#define STEAM_IGNORE_WARNINGS_END   __pragma(warning(pop))


#ifdef API_GEN
# define STEAM_CLANG_ATTR(ATTR) __attribute__((annotate( ATTR )))
#else
# define STEAM_CLANG_ATTR(ATTR)
#endif

#define STEAM_METHOD_DESC(DESC) STEAM_CLANG_ATTR( "desc:" #DESC ";" )
#define STEAM_IGNOREATTR() STEAM_CLANG_ATTR( "ignore" )
#define STEAM_OUT_STRUCT() STEAM_CLANG_ATTR( "out_struct: ;" )
#define STEAM_OUT_STRING() STEAM_CLANG_ATTR( "out_string: ;" )
#define STEAM_OUT_ARRAY_CALL(COUNTER,FUNCTION,PARAMS) STEAM_CLANG_ATTR( "out_array_call:" #COUNTER "," #FUNCTION "," #PARAMS ";" )
#define STEAM_OUT_ARRAY_COUNT(COUNTER, DESC) STEAM_CLANG_ATTR( "out_array_count:" #COUNTER  ";desc:" #DESC )
#define STEAM_ARRAY_COUNT(COUNTER) STEAM_CLANG_ATTR( "array_count:" #COUNTER ";" )
#define STEAM_ARRAY_COUNT_D(COUNTER, DESC) STEAM_CLANG_ATTR( "array_count:" #COUNTER ";desc:" #DESC )
#define STEAM_BUFFER_COUNT(COUNTER) STEAM_CLANG_ATTR( "buffer_count:" #COUNTER ";" )
#define STEAM_OUT_BUFFER_COUNT(COUNTER) STEAM_CLANG_ATTR( "out_buffer_count:" #COUNTER ";" )
#define STEAM_OUT_STRING_COUNT(COUNTER) STEAM_CLANG_ATTR( "out_string_count:" #COUNTER ";" )
#define STEAM_DESC(DESC) STEAM_CLANG_ATTR("desc:" #DESC ";")
#define STEAM_CALL_RESULT(RESULT_TYPE) STEAM_CLANG_ATTR("callresult:" #RESULT_TYPE ";")
#define STEAM_CALL_BACK(RESULT_TYPE) STEAM_CLANG_ATTR("callback:" #RESULT_TYPE ";")
#define STEAM_FLAT_NAME(NAME) STEAM_CLANG_ATTR("flat_name:" #NAME ";")

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef uint32 HServerListRequest;
typedef void* unknown_ret;
typedef uint32 AppId_t;
typedef uint32 DepotId_t;
typedef uint64 SteamAPICall_t;
typedef int32 HSteamPipe;
// handle to single instance of a steam user
typedef int32 HSteamUser;

typedef uint64 CGameID;
typedef uint64 UGCHandle_t;
typedef uint64 PublishedFileUpdateHandle_t;
typedef uint64 PublishedFileId_t;
const PublishedFileId_t k_PublishedFileIdInvalid = 0;
const UGCHandle_t k_UGCHandleInvalid = 0xffffffffffffffffull;
const PublishedFileUpdateHandle_t k_PublishedFileUpdateHandleInvalid = 0xffffffffffffffffull;

// return type of GetAuthSessionTicket
typedef uint32 HAuthTicket;
const HAuthTicket k_HAuthTicketInvalid = 0;
typedef int HServerQuery;

// results from BeginAuthSession
enum EBeginAuthSessionResult
{
	k_EBeginAuthSessionResultOK = 0,						// Ticket is valid for this game and this steamID.
	k_EBeginAuthSessionResultInvalidTicket = 1,				// Ticket is not valid.
	k_EBeginAuthSessionResultDuplicateRequest = 2,			// A ticket has already been submitted for this steamID
	k_EBeginAuthSessionResultInvalidVersion = 3,			// Ticket is from an incompatible interface version
	k_EBeginAuthSessionResultGameMismatch = 4,				// Ticket is not for this game
	k_EBeginAuthSessionResultExpiredTicket = 5,				// Ticket has expired
};

enum EUserHasLicenseForAppResult
{
	k_EUserHasLicenseResultHasLicense = 0,					// User has a license for specified app
	k_EUserHasLicenseResultDoesNotHaveLicense = 1,			// User does not have a license for the specified app
	k_EUserHasLicenseResultNoAuth = 2,						// User has not been authenticated
};

enum EVoiceResult
{
	k_EVoiceResultOK = 0,
	k_EVoiceResultNotInitialized = 1,
	k_EVoiceResultNotRecording = 2,
	k_EVoiceResultNoData = 3,
	k_EVoiceResultBufferTooSmall = 4,
	k_EVoiceResultDataCorrupted = 5,
	k_EVoiceResultRestricted = 6,
	k_EVoiceResultUnsupportedCodec = 7,
	k_EVoiceResultReceiverOutOfDate = 8,
	k_EVoiceResultReceiverDidNotAnswer = 9,

};

// Steam API call failure results
enum ESteamAPICallFailure
{
	k_ESteamAPICallFailureNone = -1,			// no failure
	k_ESteamAPICallFailureSteamGone = 0,		// the local Steam process has gone away
	k_ESteamAPICallFailureNetworkFailure = 1,	// the network connection to Steam has been broken, or was already broken
	// SteamServersDisconnected_t callback will be sent around the same time
	// SteamServersConnected_t will be sent when the client is able to talk to the Steam servers again
	k_ESteamAPICallFailureInvalidHandle = 2,	// the SteamAPICall_t handle passed in no longer exists
	k_ESteamAPICallFailureMismatchedCallback = 3,// GetAPICallResult() was called with the wrong callback type for this API call
};

enum ENotificationPosition
{
	k_EPositionTopLeft = 0,
	k_EPositionTopRight = 1,
	k_EPositionBottomLeft = 2,
	k_EPositionBottomRight = 3,
};

// Steam universes.  Each universe is a self-contained Steam instance.
enum EUniverse
{
	k_EUniverseInvalid = 0,
	k_EUniversePublic = 1,
	k_EUniverseBeta = 2,
	k_EUniverseInternal = 3,
	k_EUniverseDev = 4,
	// k_EUniverseRC = 5,				// no such universe anymore
	k_EUniverseMax
};

// Input modes for the Big Picture gamepad text entry
enum EGamepadTextInputMode
{
	k_EGamepadTextInputModeNormal = 0,
	k_EGamepadTextInputModePassword = 1
};


// Controls number of allowed lines for the Big Picture gamepad text entry
enum EGamepadTextInputLineMode
{
	k_EGamepadTextInputLineModeSingleLine = 0,
	k_EGamepadTextInputLineModeMultipleLines = 1
};

enum EAccountType
{
	k_EAccountTypeInvalid = 0,
	k_EAccountTypeIndividual = 1,		// single user account
	k_EAccountTypeMultiseat = 2,		// multiseat (e.g. cybercafe) account
	k_EAccountTypeGameServer = 3,		// game server account
	k_EAccountTypeAnonGameServer = 4,	// anonymous game server account
	k_EAccountTypePending = 5,			// pending
	k_EAccountTypeContentServer = 6,	// content server
	k_EAccountTypeClan = 7,
	k_EAccountTypeChat = 8,
	k_EAccountTypeConsoleUser = 9,		// Fake CSteamID for local PSN account on PS3 or Live account on 360, etc.
	k_EAccountTypeAnonUser = 10,

	// Max of 16 items in this field
	k_EAccountTypeMax
};

const uint32 k_nScreenshotMaxTaggedUsers = 32;
const uint32 k_nScreenshotMaxTaggedPublishedFiles = 32;
const int k_cubUFSTagTypeMax = 255;
const int k_cubUFSTagValueMax = 255;

// Required with of a thumbnail provided to AddScreenshotToLibrary.  If you do not provide a thumbnail
// one will be generated.
const int k_ScreenshotThumbWidth = 200;

// Handle is valid for the lifetime of your process and no longer
typedef uint32 ScreenshotHandle; 
#define INVALID_SCREENSHOT_HANDLE 0

enum EVRScreenshotType
{
	k_EVRScreenshotType_None			= 0,
	k_EVRScreenshotType_Mono			= 1,
	k_EVRScreenshotType_Stereo			= 2,
	k_EVRScreenshotType_MonoCubemap		= 3,
	k_EVRScreenshotType_MonoPanorama	= 4,
	k_EVRScreenshotType_StereoPanorama	= 5
};

extern "C" typedef void(__cdecl* SteamAPIWarningMessageHook_t)(int, const char*);

enum EServerMode
{
	eServerModeInvalid = 0, // DO NOT USE		
	eServerModeNoAuthentication = 1, // Don't authenticate user logins and don't list on the server list
	eServerModeAuthentication = 2, // Authenticate users, list on the server list, don't run VAC on clients that connect
	eServerModeAuthenticationAndSecure = 3, // Authenticate users, list on the server list and VAC protect clients
};

struct SteamIDComponent_t
{
	uint32				m_unAccountID : 32;			// unique account identifier
	unsigned int		m_unAccountInstance : 20;	// dynamic instance ID
	unsigned int		m_EAccountType : 4;			// type of account - can't show as EAccountType, due to signed / unsigned difference
	EUniverse			m_EUniverse : 8;	// universe this account belongs to
};

union CSteamID
{
	SteamIDComponent_t m_comp;
	uint64 m_unAll64Bits;
};

#include "servernetadr_t.hpp"

const int k_cbMaxGameServerGameDir = 32;
const int k_cbMaxGameServerMapName = 32;
const int k_cbMaxGameServerGameDescription = 64;
const int k_cbMaxGameServerName = 64;
const int k_cbMaxGameServerTags = 128;
const int k_cbMaxGameServerGameData = 2048;

class gameserveritem_t
{
public:
	servernetadr_t m_NetAdr;									///< IP/Query Port/Connection Port for this server
	int m_nPing;												///< current ping time in milliseconds
	bool m_bHadSuccessfulResponse;								///< server has responded successfully in the past
	bool m_bDoNotRefresh;										///< server is marked as not responding and should no longer be refreshed
	char m_szGameDir[k_cbMaxGameServerGameDir];					///< current game directory
	char m_szMap[k_cbMaxGameServerMapName];						///< current map
	char m_szGameDescription[k_cbMaxGameServerGameDescription];	///< game description
	uint32 m_nAppID;											///< Steam App ID of this server
	int m_nPlayers;												///< total number of players currently on the server.  INCLUDES BOTS!!
	int m_nMaxPlayers;											///< Maximum players that can join this server
	int m_nBotPlayers;											///< Number of bots (i.e simulated players) on this server
	bool m_bPassword;											///< true if this server needs a password to join
	bool m_bSecure;												///< Is this server protected by VAC
	uint32 m_ulTimeLastPlayed;									///< time (in unix time) when this server was last played on (for favorite/history servers)
	int	m_nServerVersion;										///< server version as reported to Steam
	
private:

	/// Game server name
	char m_szServerName[k_cbMaxGameServerName];
		
	// For data added after SteamMatchMaking001 add it here
public:
	/// the tags this server exposes
	char m_szGameTags[k_cbMaxGameServerTags];

	/// steamID of the game server - invalid if it's doesn't have one (old server, or not connected to Steam)
	CSteamID m_steamID;

	inline gameserveritem_t()
	{
		m_szGameDir[0] = m_szMap[0] = m_szGameDescription[0] = m_szServerName[0] = 0;
		m_bHadSuccessfulResponse = m_bDoNotRefresh = m_bPassword = m_bSecure = false;
		m_nPing = m_nAppID = m_nPlayers = m_nMaxPlayers = m_nBotPlayers = m_ulTimeLastPlayed = m_nServerVersion = 0;
		m_szGameTags[0] = 0;
	}

	inline const char* GetName() const
	{
		// Use the IP address as the name if nothing is set yet.
		if ( m_szServerName[0] == 0 )
			return m_NetAdr.GetConnectionAddressString();
		else
			return m_szServerName;
	};

	inline void SetName( const char *pName )
	{
		strncpy( m_szServerName, pName, sizeof( m_szServerName ) );
		m_szServerName[ sizeof( m_szServerName ) - 1 ] = '\0';
	};
};


enum EResult
{
	k_EResultNone = 0,							// no result
	k_EResultOK	= 1,							// success
	k_EResultFail = 2							// generic failure 
	// ...
};

struct GSStatsReceived_t
{
	enum { k_iCallback = 1800 };
	EResult		m_eResult;		// Success / error fetching the stats
	CSteamID	m_steamIDUser;	// The user for whom the stats are retrieved for
};

struct GSStatsStored_t
{
	enum { k_iCallback = 1800 + 1 };
	EResult		m_eResult;		// success / error
	CSteamID	m_steamIDUser;	// The user for whom the stats were stored
};

struct UserStatsReceived_t
{
	enum { k_iCallback = 1100 + 1 };
	uint64		m_nGameID;		// Game these stats are for
	EResult		m_eResult;		// Success / error fetching the stats
	CSteamID	m_steamIDUser;	// The user for whom the stats are retrieved for
};

struct UserStatsStored_t
{
	enum { k_iCallback = 1100 + 2 };
	uint64		m_nGameID;		// Game these stats are for
	EResult		m_eResult;		// success / error
};

#include "Interfaces/SteamUser.hpp"
#include "Interfaces/SteamUserStats.hpp"
#include "Interfaces/SteamUtils.hpp"
#include "Interfaces/SteamFriends.hpp"
#include "Interfaces/SteamGameServer.hpp"
#include "Interfaces/SteamNetworking.hpp"
#include "Interfaces/SteamMatchmaking.hpp"
#include "Interfaces/SteamScreenshots.hpp"
#include "Interfaces/SteamMatchmakingServers.hpp"
#include "Interfaces/SteamRemoteStorage.hpp"
#include "Interfaces/SteamApps.hpp"
#include "Interfaces/SteamMatchmakingServers.hpp"
#include "Interfaces/SteamGameServerStats.hpp"
#include "Interfaces/SteamClient.hpp"

namespace Steam
{
	class Callbacks
	{
	public:
		class Base
		{
		public:
			Base() : Flags(0), Callback(0) {};

			virtual void Run(void* pvParam) = 0;
			virtual void Run(void* pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall) = 0;
			virtual int GetCallbackSizeBytes() = 0;

			int GetICallback() { return Callback; }
			void SetICallback(int iCallback) { Callback = iCallback; }

		protected:
			~Base() = default;

			unsigned char Flags;
			int Callback;
		};

		struct Result
		{
			void* data;
			int size;
			int type;
			SteamAPICall_t call;
		};

		static SteamAPICall_t RegisterCall();
		static void RegisterCallback(Base* handler, int callback);

		/// <summary>
		/// addCallBack
		/// </summary>
		/// <param name="call"></param>
		/// <param name="result"></param>
		static void RegisterCallResult(SteamAPICall_t call, Base* result);
		static void ReturnCall(void* data, int size, int type, SteamAPICall_t call);
		static void RunCallbacks();

		static void RunCallback(int32_t callback, void* data);

		static void Uninitialize();

	private:
		static SteamAPICall_t CallID;
		static std::map<SteamAPICall_t, bool> Calls;
		static std::map<SteamAPICall_t, Base*> ResultHandlers;
		static std::vector<Result> Results;
		static std::vector<Base*> CallbackList;
		static std::recursive_mutex Mutex;
	};

	bool Enabled();

	STEAM_EXPORT bool SteamAPI_Init();
	STEAM_EXPORT void SteamAPI_RegisterCallResult(Callbacks::Base* result, SteamAPICall_t call);
	STEAM_EXPORT void SteamAPI_RegisterCallback(Callbacks::Base* handler, int callback);
	STEAM_EXPORT void SteamAPI_RunCallbacks();
	STEAM_EXPORT void SteamAPI_Shutdown();
	STEAM_EXPORT void SteamAPI_UnregisterCallResult(Callbacks::Base* result, SteamAPICall_t call);
	STEAM_EXPORT void SteamAPI_UnregisterCallback(Callbacks::Base* result);

	STEAM_EXPORT bool SteamGameServer_Init(uint32 unIP, uint16 usSteamPort, uint16 usGamePort, uint16 usQueryPort, EServerMode eServerMode, const char* pchVersionString);
	STEAM_EXPORT void SteamGameServer_RunCallbacks();
	STEAM_EXPORT void SteamGameServer_Shutdown();

	// Added for SV
	STEAM_EXPORT bool SteamGameServer_BSecure();
	STEAM_EXPORT uint64 SteamGameServer_GetSteamID();

	STEAM_EXPORT Steam::Friends* SteamFriends();
	STEAM_EXPORT Steam::Matchmaking* SteamMatchmaking();
	STEAM_EXPORT Steam::GameServer* SteamGameServer();
	STEAM_EXPORT Steam::Networking* SteamNetworking();
	STEAM_EXPORT Steam::RemoteStorage* SteamRemoteStorage();
	STEAM_EXPORT Steam::User* SteamUser();
	STEAM_EXPORT Steam::Utils* SteamUtils();
	STEAM_EXPORT Steam::Apps* SteamApps();
	STEAM_EXPORT Steam::MatchmakingServers* SteamMatchmakingServers();
	STEAM_EXPORT Steam::UserStats* SteamUserStats();
	STEAM_EXPORT Steam::GameServerStats* SteamGameServerStats();
	STEAM_EXPORT Steam::Networking* SteamGameServerNetworking();
	STEAM_EXPORT void* SteamGameServerUtils() { return nullptr; };

	// Added for AOA
	STEAM_EXPORT void SteamAPI_WriteMiniDump(uint32 uStructuredExceptionCode, void* pvExceptionInfo, uint32 uBuildID) {};
	STEAM_EXPORT void SteamAPI_SetMiniDumpComment(const char* pchMsg) {};
	STEAM_EXPORT bool SteamAPI_RestartAppIfNecessary(uint32 unOwnAppID) { return false; };

	STEAM_EXPORT Steam::Client* SteamClient();

	STEAM_EXPORT HSteamPipe SteamAPI_GetHSteamPipe();
	STEAM_EXPORT HSteamUser SteamAPI_GetHSteamUser();
	STEAM_EXPORT bool SteamAPI_InitSafe() { return true; };
	STEAM_EXPORT bool SteamAPI_IsSteamRunning() { return true; };

}
