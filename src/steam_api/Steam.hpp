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


//-----------------------------------------------------------------------------
// Purpose: Base values for callback identifiers, each callback must
//			have a unique ID.
//-----------------------------------------------------------------------------
enum { k_iSteamUserCallbacks = 100 };
enum { k_iSteamGameServerCallbacks = 200 };
enum { k_iSteamFriendsCallbacks = 300 };
enum { k_iSteamBillingCallbacks = 400 };
enum { k_iSteamMatchmakingCallbacks = 500 };
enum { k_iSteamContentServerCallbacks = 600 };
enum { k_iSteamUtilsCallbacks = 700 };
enum { k_iClientFriendsCallbacks = 800 };
enum { k_iClientUserCallbacks = 900 };
enum { k_iSteamAppsCallbacks = 1000 };
enum { k_iSteamUserStatsCallbacks = 1100 };
enum { k_iSteamNetworkingCallbacks = 1200 };
enum { k_iSteamNetworkingSocketsCallbacks = 1220 };
enum { k_iSteamNetworkingMessagesCallbacks = 1250 };
enum { k_iSteamNetworkingUtilsCallbacks = 1280 };
enum { k_iClientRemoteStorageCallbacks = 1300 };
enum { k_iSteamRemoteStorageCallbacks = 1300 };
enum { k_iClientDepotBuilderCallbacks = 1400 };
enum { k_iSteamGameServerItemsCallbacks = 1500 };
enum { k_iClientUtilsCallbacks = 1600 };
enum { k_iSteamGameCoordinatorCallbacks = 1700 };
enum { k_iSteamGameServerStatsCallbacks = 1800 };
enum { k_iSteam2AsyncCallbacks = 1900 };
enum { k_iSteamGameStatsCallbacks = 2000 };
enum { k_iClientHTTPCallbacks = 2100 };
enum { k_iSteamHTTPCallbacks = 2100 };
enum { k_iClientScreenshotsCallbacks = 2200 };
enum { k_iSteamScreenshotsCallbacks = 2300 };
enum { k_iClientAudioCallbacks = 2400 };
enum { k_iClientUnifiedMessagesCallbacks = 2500 };
enum { k_iSteamStreamLauncherCallbacks = 2600 };
enum { k_iClientControllerCallbacks = 2700 };
enum { k_iSteamControllerCallbacks = 2800 };
enum { k_iClientParentalSettingsCallbacks = 2900 };
enum { k_iClientDeviceAuthCallbacks = 3000 };
enum { k_iClientNetworkDeviceManagerCallbacks = 3100 };
enum { k_iClientMusicCallbacks = 3200 };
enum { k_iClientRemoteClientManagerCallbacks = 3300 };
enum { k_iClientUGCCallbacks = 3400 };
enum { k_iSteamUGCCallbacks = 3400 };
enum { k_iSteamStreamClientCallbacks = 3500 };
enum { k_IClientProductBuilderCallbacks = 3600 };
enum { k_iClientShortcutsCallbacks = 3700 };
enum { k_iClientRemoteControlManagerCallbacks = 3800 };
enum { k_iSteamAppListCallbacks = 3900 };
enum { k_iSteamMusicCallbacks = 4000 };
enum { k_iSteamMusicRemoteCallbacks = 4100 };
enum { k_iClientVRCallbacks = 4200 };
enum { k_iClientGameNotificationCallbacks = 4300 };
enum { k_iSteamGameNotificationCallbacks = 4400 };
enum { k_iSteamHTMLSurfaceCallbacks = 4500 };
enum { k_iClientVideoCallbacks = 4600 };
enum { k_iSteamVideoCallbacks = 4600 };
enum { k_iClientInventoryCallbacks = 4700 };
enum { k_iSteamInventoryCallbacks = 4700 };
enum { k_iClientBluetoothManagerCallbacks = 4800 };
enum { k_iClientSharedConnectionCallbacks = 4900 };
enum { k_ISteamParentalSettingsCallbacks = 5000 };
enum { k_iClientShaderCallbacks = 5100 };
enum { k_iSteamGameSearchCallbacks = 5200 };
enum { k_iSteamPartiesCallbacks = 5300 };
enum { k_iClientPartiesCallbacks = 5400 };
enum { k_iSteamSTARCallbacks = 5500 };
enum { k_iClientSTARCallbacks = 5600 };
enum { k_iSteamRemotePlayCallbacks = 5700 };
enum { k_iClientCompatCallbacks = 5800 };
enum { k_iSteamChatCallbacks = 5900 };
enum { k_iClientNetworkingUtilsCallbacks = 6000 };
enum { k_iClientSystemManagerCallbacks = 6100 };
enum { k_iClientStorageDeviceManagerCallbacks = 6200 };


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
const SteamAPICall_t k_uAPICallInvalid = 0x0;
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
	k_EVRScreenshotType_None = 0,
	k_EVRScreenshotType_Mono = 1,
	k_EVRScreenshotType_Stereo = 2,
	k_EVRScreenshotType_MonoCubemap = 3,
	k_EVRScreenshotType_MonoPanorama = 4,
	k_EVRScreenshotType_StereoPanorama = 5
};

extern "C" typedef void(__cdecl* SteamAPIWarningMessageHook_t)(int, const char*);

enum EServerMode
{
	eServerModeInvalid = 0, // DO NOT USE		
	eServerModeNoAuthentication = 1, // Don't authenticate user logins and don't list on the server list
	eServerModeAuthentication = 2, // Authenticate users, list on the server list, don't run VAC on clients that connect
	eServerModeAuthenticationAndSecure = 3, // Authenticate users, list on the server list and VAC protect clients
};

// Callback values for callback ValidateAuthTicketResponse_t which is a response to BeginAuthSession
enum EAuthSessionResponse
{
	k_EAuthSessionResponseOK = 0,							// Steam has verified the user is online, the ticket is valid and ticket has not been reused.
	k_EAuthSessionResponseUserNotConnectedToSteam = 1,		// The user in question is not connected to steam
	k_EAuthSessionResponseNoLicenseOrExpired = 2,			// The license has expired.
	k_EAuthSessionResponseVACBanned = 3,					// The user is VAC banned for this game.
	k_EAuthSessionResponseLoggedInElseWhere = 4,			// The user account has logged in elsewhere and the session containing the game instance has been disconnected.
	k_EAuthSessionResponseVACCheckTimedOut = 5,				// VAC has been unable to perform anti-cheat checks on this user
	k_EAuthSessionResponseAuthTicketCanceled = 6,			// The ticket has been canceled by the issuer
	k_EAuthSessionResponseAuthTicketInvalidAlreadyUsed = 7,	// This ticket has already been used, it is not valid.
	k_EAuthSessionResponseAuthTicketInvalid = 8,			// This ticket is not from a user instance currently connected to steam.
	k_EAuthSessionResponsePublisherIssuedBan = 9,			// The user is banned for this game. The ban came via the web api and not VAC
	k_EAuthSessionResponseAuthTicketNetworkIdentityFailure = 10,	// The network identity in the ticket does not match the server authenticating the ticket
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

	bool operator==(const CSteamID& other) const
	{
		return (m_unAll64Bits == other.m_unAll64Bits);
	}
	bool operator!=(const CSteamID& other) const
	{
		return !operator==(other);
	}
};

#include "servernetadr_t.hpp"
#include "gameserveritem_t.hpp"

enum EResult
{
	k_EResultNone = 0,							// no result
	k_EResultOK = 1,							// success
	k_EResultFail = 2							// generic failure 
	// ...
};

#pragma pack( push, 8 )
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

struct Auth_Ticket_Data {
	CSteamID id;
	uint64 number;
	std::chrono::high_resolution_clock::time_point created;
};

struct ValidateAuthTicketResponse_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 43 };
	CSteamID m_SteamID;
	EAuthSessionResponse m_eAuthSessionResponse;
	CSteamID m_OwnerSteamID; // different from m_SteamID if borrowed
};

#pragma pack( pop )

namespace Steam
{
	struct Callbacks
	{
		Callbacks();

		class SteamCallResults* GetResultsServer() const { return resultsServer; };
		class SteamCallResults* GetResultsClient() const { return resultsClient; };
		class SteamCallBacks* GetServer() const { return callbacksServer; };
		class SteamCallBacks* GetClient() const { return callbacksClient; }

	private:
		class SteamCallResults* resultsClient, *resultsServer;
		class SteamCallBacks* callbacksClient, *callbacksServer;
	};

	extern Callbacks* callbacks;
}

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
	STEAM_EXPORT bool SteamAPI_Init();
	STEAM_EXPORT void SteamAPI_RegisterCallResult(class CCallbackBase* result, SteamAPICall_t call);
	STEAM_EXPORT void SteamAPI_RegisterCallback(class CCallbackBase* handler, int callback);
	STEAM_EXPORT void SteamAPI_RunCallbacks();
	STEAM_EXPORT void SteamAPI_Shutdown();
	STEAM_EXPORT void SteamAPI_UnregisterCallResult(class CCallbackBase* result, SteamAPICall_t call);
	STEAM_EXPORT void SteamAPI_UnregisterCallback(class CCallbackBase* result);

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
