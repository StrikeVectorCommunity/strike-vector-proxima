#pragma once

namespace Steam
{
	enum EMatchMakingServerResponse
	{
		eServerResponded = 0,
		eServerFailedToRespond,
		eNoServersListedOnMasterServer // for the Internet query type, returned in response callback if no servers of this type match
	};

	// lobby type description
	enum ELobbyType
	{
		k_ELobbyTypePrivate = 0,		// only way to join the lobby is to invite to someone else
		k_ELobbyTypeFriendsOnly = 1,	// shows for friends or invitees, but not in lobby list
		k_ELobbyTypePublic = 2,			// visible for friends and in lobby list
		k_ELobbyTypeInvisible = 3,		// returned by search, but not visible to other friends 
										//    useful if you want a user in two lobbies, for example matching groups together
										//	  a user can be in only one regular lobby, and up to two invisible lobbies
										k_ELobbyTypePrivateUnique = 4,	// private, unique and does not delete when empty - only one of these may exist per unique keypair set
																		// can only create from webapi
	};

	// lobby search filter tools
	enum ELobbyComparison
	{
		k_ELobbyComparisonEqualToOrLessThan = -2,
		k_ELobbyComparisonLessThan = -1,
		k_ELobbyComparisonEqual = 0,
		k_ELobbyComparisonGreaterThan = 1,
		k_ELobbyComparisonEqualToOrGreaterThan = 2,
		k_ELobbyComparisonNotEqual = 3,
	};

	// lobby search distance. Lobby results are sorted from closest to farthest.
	enum ELobbyDistanceFilter
	{
		k_ELobbyDistanceFilterClose,		// only lobbies in the same immediate region will be returned
		k_ELobbyDistanceFilterDefault,		// only lobbies in the same region or near by regions
		k_ELobbyDistanceFilterFar,			// for games that don't have many latency requirements, will return lobbies about half-way around the globe
		k_ELobbyDistanceFilterWorldwide,	// no filtering, will match lobbies as far as India to NY (not recommended, expect multiple seconds of latency between the clients)
	};

	// maximum number of characters a lobby metadata key can be
#define k_nMaxLobbyKeyLength 255

	struct LobbyCreated
	{
		enum { CallbackID = 513 };

		int m_eResult;
		int m_pad;
		CSteamID m_ulSteamIDLobby;
	};

	struct LobbyEnter
	{
		enum { CallbackID = 504 };

		CSteamID m_ulSteamIDLobby;
		int m_rgfChatPermissions;
		bool m_bLocked;
		int m_EChatRoomEnterResponse;
	};


	//-----------------------------------------------------------------------------
	// Purpose: Callback interface for receiving responses after pinging an individual server 
	//
	// These callbacks all occur in response to querying an individual server
	// via the ISteamMatchmakingServers()->PingServer() call below.  If you are 
	// destructing an object that implements this interface then you should call 
	// ISteamMatchmakingServers()->CancelServerQuery() passing in the handle to the query
	// which is in progress.  Failure to cancel in progress queries when destructing
	// a callback handler may result in a crash when a callback later occurs.
	//-----------------------------------------------------------------------------
	class ISteamMatchmakingPingResponse
	{
	public:
		// Server has responded successfully and has updated data
		virtual void ServerResponded(gameserveritem_t& server) = 0;

		// Server failed to respond to the ping request
		virtual void ServerFailedToRespond() = 0;
	};


	//-----------------------------------------------------------------------------
	// Purpose: Callback interface for receiving responses after requesting details on
	// who is playing on a particular server.
	//
	// These callbacks all occur in response to querying an individual server
	// via the ISteamMatchmakingServers()->PlayerDetails() call below.  If you are 
	// destructing an object that implements this interface then you should call 
	// ISteamMatchmakingServers()->CancelServerQuery() passing in the handle to the query
	// which is in progress.  Failure to cancel in progress queries when destructing
	// a callback handler may result in a crash when a callback later occurs.
	//-----------------------------------------------------------------------------
	class ISteamMatchmakingPlayersResponse
	{
	public:
		// Got data on a new player on the server -- you'll get this callback once per player
		// on the server which you have requested player data on.
		virtual void AddPlayerToList(const char* pchName, int nScore, float flTimePlayed) = 0;

		// The server failed to respond to the request for player details
		virtual void PlayersFailedToRespond() = 0;

		// The server has finished responding to the player details request 
		// (ie, you won't get anymore AddPlayerToList callbacks)
		virtual void PlayersRefreshComplete() = 0;
	};


	//-----------------------------------------------------------------------------
	// Purpose: Callback interface for receiving responses after requesting rules
	// details on a particular server.
	//
	// These callbacks all occur in response to querying an individual server
	// via the ISteamMatchmakingServers()->ServerRules() call below.  If you are 
	// destructing an object that implements this interface then you should call 
	// ISteamMatchmakingServers()->CancelServerQuery() passing in the handle to the query
	// which is in progress.  Failure to cancel in progress queries when destructing
	// a callback handler may result in a crash when a callback later occurs.
	//-----------------------------------------------------------------------------
	class ISteamMatchmakingRulesResponse
	{
	public:
		// Got data on a rule on the server -- you'll get one of these per rule defined on
		// the server you are querying
		virtual void RulesResponded(const char* pchRule, const char* pchValue) = 0;

		// The server failed to respond to the request for rule details
		virtual void RulesFailedToRespond() = 0;

		// The server has finished responding to the rule details request 
		// (ie, you won't get anymore RulesResponded callbacks)
		virtual void RulesRefreshComplete() = 0;
	};

	class ISteamMatchmakingServerListResponse
	{
	public:
		// Server has responded ok with updated data
		virtual void ServerResponded(HServerListRequest hRequest, int iServer) {};

		// Server has failed to respond
		virtual void ServerFailedToRespond(HServerListRequest hRequest, int iServer) {};

		// A list refresh you had initiated is now 100% completed
		virtual void RefreshComplete(HServerListRequest hRequest, EMatchMakingServerResponse response) {};
	};

	struct Steam_Matchmaking_Servers_Direct_IP_Request {
		HServerQuery id;
		uint32 ip;
		uint16 port;

		std::chrono::high_resolution_clock::time_point created;
		ISteamMatchmakingRulesResponse* rules_response = NULL;
		ISteamMatchmakingPlayersResponse* players_response = NULL;
		ISteamMatchmakingPingResponse* ping_response = NULL;
	};

	struct Gameserver
	{
		uint64 id;
		uint32 ip;
		uint32 port;
		uint32 num_update;
	};

	struct Steam_Matchmaking_Servers_Gameserver {
		Gameserver server;
		std::chrono::high_resolution_clock::time_point last_recv;
	};

	struct Steam_Matchmaking_Request {
		AppId_t appid;
		HServerListRequest id;
		ISteamMatchmakingServerListResponse* callbacks;
		bool completed, cancelled, released;
		std::vector <Steam_Matchmaking_Servers_Gameserver> gameservers_filtered;
	};


	class Matchmaking
	{
	public:
		// game server favorites storage
	// saves basic details about a multiplayer game server locally

	// returns the number of favorites servers the user has stored
		virtual int GetFavoriteGameCount();

		// returns the details of the game server
		// iGame is of range [0,GetFavoriteGameCount())
		// *pnIP, *pnConnPort are filled in the with IP:port of the game server
		// *punFlags specify whether the game server was stored as an explicit favorite or in the history of connections
		// *pRTime32LastPlayedOnServer is filled in the with the Unix time the favorite was added
		virtual bool GetFavoriteGame(int iGame, AppId_t* pnAppID, uint32* pnIP, uint16* pnConnPort, uint16* pnQueryPort, uint32* punFlags, uint32* pRTime32LastPlayedOnServer);

		// adds the game server to the local list; updates the time played of the server if it already exists in the list
		virtual int AddFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer);

		// removes the game server from the local storage; returns true if one was removed
		virtual bool RemoveFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags);

		///////
		// Game lobby functions

		// Get a list of relevant lobbies
		// this is an asynchronous request
		// results will be returned by LobbyMatchList_t callback & call result, with the number of lobbies found
		// this will never return lobbies that are full
		// to add more filter, the filter calls below need to be call before each and every RequestLobbyList() call
		// use the CCallResult<> object in steam_api.h to match the SteamAPICall_t call result to a function in an object, e.g.
		/*
			class CMyLobbyListManager
			{
				CCallResult<CMyLobbyListManager, LobbyMatchList_t> m_CallResultLobbyMatchList;
				void FindLobbies()
				{
					// SteamMatchmaking()->AddRequestLobbyListFilter*() functions would be called here, before RequestLobbyList()
					SteamAPICall_t hSteamAPICall = SteamMatchmaking()->RequestLobbyList();
					m_CallResultLobbyMatchList.Set( hSteamAPICall, this, &CMyLobbyListManager::OnLobbyMatchList );
				}

				void OnLobbyMatchList( LobbyMatchList_t *pLobbyMatchList, bool bIOFailure )
				{
					// lobby list has be retrieved from Steam back-end, use results
				}
			}
		*/
		// 
		STEAM_CALL_RESULT(LobbyMatchList_t)
			virtual SteamAPICall_t RequestLobbyList();
		// filters for lobbies
		// this needs to be called before RequestLobbyList() to take effect
		// these are cleared on each call to RequestLobbyList()
		virtual void AddRequestLobbyListStringFilter(const char* pchKeyToMatch, const char* pchValueToMatch, ELobbyComparison eComparisonType);
		// numerical comparison
		virtual void AddRequestLobbyListNumericalFilter(const char* pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType);
		// returns results closest to the specified value. Multiple near filters can be added, with early filters taking precedence
		virtual void AddRequestLobbyListNearValueFilter(const char* pchKeyToMatch, int nValueToBeCloseTo);
		// returns only lobbies with the specified number of slots available
		virtual void AddRequestLobbyListFilterSlotsAvailable(int nSlotsAvailable);
		// sets the distance for which we should search for lobbies (based on users IP address to location map on the Steam backed)
		virtual void AddRequestLobbyListDistanceFilter(ELobbyDistanceFilter eLobbyDistanceFilter);
		// sets how many results to return, the lower the count the faster it is to download the lobby results & details to the client
		virtual void AddRequestLobbyListResultCountFilter(int cMaxResults);

		virtual void AddRequestLobbyListCompatibleMembersFilter(CSteamID steamIDLobby);

		// returns the CSteamID of a lobby, as retrieved by a RequestLobbyList call
		// should only be called after a LobbyMatchList_t callback is received
		// iLobby is of the range [0, LobbyMatchList_t::m_nLobbiesMatching)
		// the returned CSteamID::IsValid() will be false if iLobby is out of range
		virtual CSteamID GetLobbyByIndex(int iLobby);

		// Create a lobby on the Steam servers.
		// If private, then the lobby will not be returned by any RequestLobbyList() call; the CSteamID
		// of the lobby will need to be communicated via game channels or via InviteUserToLobby()
		// this is an asynchronous request
		// results will be returned by LobbyCreated_t callback and call result; lobby is joined & ready to use at this point
		// a LobbyEnter_t callback will also be received (since the local user is joining their own lobby)
		STEAM_CALL_RESULT(LobbyCreated_t)
			virtual SteamAPICall_t CreateLobby(ELobbyType eLobbyType, int cMaxMembers);

		// Joins an existing lobby
		// this is an asynchronous request
		// results will be returned by LobbyEnter_t callback & call result, check m_EChatRoomEnterResponse to see if was successful
		// lobby metadata is available to use immediately on this call completing
		STEAM_CALL_RESULT(LobbyEnter_t)
			virtual SteamAPICall_t JoinLobby(CSteamID steamIDLobby);

		// Leave a lobby; this will take effect immediately on the client side
		// other users in the lobby will be notified by a LobbyChatUpdate_t callback
		virtual void LeaveLobby(CSteamID steamIDLobby);

		// Invite another user to the lobby
		// the target user will receive a LobbyInvite_t callback
		// will return true if the invite is successfully sent, whether or not the target responds
		// returns false if the local user is not connected to the Steam servers
		// if the other user clicks the join link, a GameLobbyJoinRequested_t will be posted if the user is in-game,
		// or if the game isn't running yet the game will be launched with the parameter +connect_lobby <64-bit lobby id>
		virtual bool InviteUserToLobby(CSteamID steamIDLobby, CSteamID steamIDInvitee);

		// Lobby iteration, for viewing details of users in a lobby
		// only accessible if the lobby user is a member of the specified lobby
		// persona information for other lobby members (name, avatar, etc.) will be asynchronously received
		// and accessible via ISteamFriends interface

		// returns the number of users in the specified lobby
		virtual int GetNumLobbyMembers(CSteamID steamIDLobby);
		// returns the CSteamID of a user in the lobby
		// iMember is of range [0,GetNumLobbyMembers())
		// note that the current user must be in a lobby to retrieve CSteamIDs of other users in that lobby
		virtual CSteamID GetLobbyMemberByIndex(CSteamID steamIDLobby, int iMember);

		// Get data associated with this lobby
		// takes a simple key, and returns the string associated with it
		// "" will be returned if no value is set, or if steamIDLobby is invalid
		virtual const char* GetLobbyData(CSteamID steamIDLobby, const char* pchKey);
		// Sets a key/value pair in the lobby metadata
		// each user in the lobby will be broadcast this new value, and any new users joining will receive any existing data
		// this can be used to set lobby names, map, etc.
		// to reset a key, just set it to ""
		// other users in the lobby will receive notification of the lobby data change via a LobbyDataUpdate_t callback
		virtual bool SetLobbyData(CSteamID steamIDLobby, const char* pchKey, const char* pchValue);

		// returns the number of metadata keys set on the specified lobby
		virtual int GetLobbyDataCount(CSteamID steamIDLobby);

		// returns a lobby metadata key/values pair by index, of range [0, GetLobbyDataCount())
		virtual bool GetLobbyDataByIndex(CSteamID steamIDLobby, int iLobbyData, char* pchKey, int cchKeyBufferSize, char* pchValue, int cchValueBufferSize);

		// removes a metadata key from the lobby
		virtual bool DeleteLobbyData(CSteamID steamIDLobby, const char* pchKey);

		// Gets per-user metadata for someone in this lobby
		virtual const char* GetLobbyMemberData(CSteamID steamIDLobby, CSteamID steamIDUser, const char* pchKey);
		// Sets per-user metadata (for the local user implicitly)
		virtual void SetLobbyMemberData(CSteamID steamIDLobby, const char* pchKey, const char* pchValue);

		// Broadcasts a chat message to the all the users in the lobby
		// users in the lobby (including the local user) will receive a LobbyChatMsg_t callback
		// returns true if the message is successfully sent
		// pvMsgBody can be binary or text data, up to 4k
		// if pvMsgBody is text, cubMsgBody should be strlen( text ) + 1, to include the null terminator
		virtual bool SendLobbyChatMsg(CSteamID steamIDLobby, const void* pvMsgBody, int cubMsgBody);
		// Get a chat message as specified in a LobbyChatMsg_t callback
		// iChatID is the LobbyChatMsg_t::m_iChatID value in the callback
		// *pSteamIDUser is filled in with the CSteamID of the member
		// *pvData is filled in with the message itself
		// return value is the number of bytes written into the buffer
		virtual int GetLobbyChatEntry(CSteamID steamIDLobby, int iChatID, CSteamID* pSteamIDUser, void* pvData, int cubData, EChatEntryType* peChatEntryType);

		// Refreshes metadata for a lobby you're not necessarily in right now
		// you never do this for lobbies you're a member of, only if your
		// this will send down all the metadata associated with a lobby
		// this is an asynchronous call
		// returns false if the local user is not connected to the Steam servers
		// results will be returned by a LobbyDataUpdate_t callback
		// if the specified lobby doesn't exist, LobbyDataUpdate_t::m_bSuccess will be set to false
		virtual bool RequestLobbyData(CSteamID steamIDLobby);

		// sets the game server associated with the lobby
		// usually at this point, the users will join the specified game server
		// either the IP/Port or the steamID of the game server has to be valid, depending on how you want the clients to be able to connect
		virtual void SetLobbyGameServer(CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer);
		// returns the details of a game server set in a lobby - returns false if there is no game server set, or that lobby doesn't exist
		virtual bool GetLobbyGameServer(CSteamID steamIDLobby, uint32* punGameServerIP, uint16* punGameServerPort, STEAM_OUT_STRUCT() CSteamID* psteamIDGameServer);

		// set the limit on the # of users who can join the lobby
		virtual bool SetLobbyMemberLimit(CSteamID steamIDLobby, int cMaxMembers);
		// returns the current limit on the # of users who can join the lobby; returns 0 if no limit is defined
		virtual int GetLobbyMemberLimit(CSteamID steamIDLobby);

		// updates which type of lobby it is
		// only lobbies that are k_ELobbyTypePublic or k_ELobbyTypeInvisible, and are set to joinable, will be returned by RequestLobbyList() calls
		virtual bool SetLobbyType(CSteamID steamIDLobby, ELobbyType eLobbyType);

		// sets whether or not a lobby is joinable - defaults to true for a new lobby
		// if set to false, no user can join, even if they are a friend or have been invited
		virtual bool SetLobbyJoinable(CSteamID steamIDLobby, bool bLobbyJoinable);

		// returns the current lobby owner
		// you must be a member of the lobby to access this
		// there always one lobby owner - if the current owner leaves, another user will become the owner
		// it is possible (bur rare) to join a lobby just as the owner is leaving, thus entering a lobby with self as the owner
		virtual CSteamID GetLobbyOwner(CSteamID steamIDLobby);

		// changes who the lobby owner is
		// you must be the lobby owner for this to succeed, and steamIDNewOwner must be in the lobby
		// after completion, the local user will no longer be the owner
		virtual bool SetLobbyOwner(CSteamID steamIDLobby, CSteamID steamIDNewOwner);

		// link two lobbies for the purposes of checking player compatibility
		// you must be the lobby owner of both lobbies
		virtual bool SetLinkedLobby(CSteamID steamIDLobby, CSteamID steamIDLobbyDependent);

#ifdef _PS3
		// changes who the lobby owner is
		// you must be the lobby owner for this to succeed, and steamIDNewOwner must be in the lobby
		// after completion, the local user will no longer be the owner
		virtual void CheckForPSNGameBootInvite(unsigned int iGameBootAttributes);
#endif
	};
}
