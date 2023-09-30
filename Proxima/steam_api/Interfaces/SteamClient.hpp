#pragma once

namespace Steam
{
	// SteamClient012

	class Client
	{
	public:
	// Creates a communication pipe to the Steam client
	 HSteamPipe CreateSteamPipe();

	// Releases a previously created communications pipe
	 bool BReleaseSteamPipe( HSteamPipe hSteamPipe );

	// connects to an existing global user, failing if none exists
	// used by the game to coordinate with the steamUI
	 HSteamUser ConnectToGlobalUser( HSteamPipe hSteamPipe );

	// used by game servers, create a steam user that won't be shared with anyone else
	 HSteamUser CreateLocalUser( HSteamPipe *phSteamPipe, EAccountType eAccountType );

	// removes an allocated user
	 void ReleaseUser( HSteamPipe hSteamPipe, HSteamUser hUser );

	// retrieves the Steam::User interface associated with the handle
	 Steam::User *GetISteamUser( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// retrieves the Steam::GameServer interface associated with the handle
	 Steam::GameServer *GetISteamGameServer( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// set the local IP and Port to bind to
	// this must be set before CreateLocalUser()
	 void SetLocalIPBinding( uint32 unIP, uint16 usPort ); 

	// returns the Steam::Friends interface
	 Steam::Friends *GetISteamFriends( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// returns the Steam::Utils interface
	 Steam::Utils *GetISteamUtils( HSteamPipe hSteamPipe, const char *pchVersion );

	// returns the Steam::Matchmaking interface
	 Steam::Matchmaking *GetISteamMatchmaking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// returns the Steam::MatchmakingServers interface
	 Steam::MatchmakingServers *GetISteamMatchmakingServers( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// returns the a generic interface
	 void *GetISteamGenericInterface( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// returns the Steam::UserStats interface
	 Steam::UserStats *GetISteamUserStats( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// returns the Steam::GameServerStats interface
	 Steam::GameServerStats *GetISteamGameServerStats( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion );

	// returns apps interface
	 Steam::Apps *GetISteamApps( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// networking
	 Steam::Networking *GetISteamNetworking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	// remote storage
	 Steam::RemoteStorage *GetISteamRemoteStorage( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion );

	// user screenshots
	 Steam::Screenshots *GetISteamScreenshots( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion );


	// this needs to be called every frame to process matchmaking results
	// redundant if you're already calling SteamAPI_RunCallbacks()
	 void RunFrame();

	// returns the number of IPC calls made since the last time this function was called
	// Used for perf debugging so you can understand how many IPC calls your game makes per frame
	// Every IPC call is at minimum a thread context switch if not a process one so you want to rate
	// control how often you do them.
	 uint32 GetIPCCallCount();

	// API warning handling
	// 'int' is the severity; 0 for msg, 1 for warning
	// 'const char *' is the text of the message
	// callbacks will occur directly after the API function is called that generated the warning or message
	 void SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction );

	// Trigger global shutdown for the DLL
	 bool BShutdownIfAllPipesClosed();

	//// Expose HTTP interface
	// Steam::HTTP *GetISteamHTTP( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion );

	//// Exposes the Steam::UnifiedMessages interface
	// Steam::UnifiedMessages *GetISteamUnifiedMessages( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion );

	//// Exposes the Steam::Controller interface
	// Steam::Controller *GetISteamController( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );

	//// Exposes the Steam::UGC interface
	// Steam::UGC *GetISteamUGC( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion );
	};
}
