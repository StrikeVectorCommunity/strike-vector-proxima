#pragma once


namespace Steam
{
	struct FriendSessionStateInfo
	{
		uint32_t m_uiOnlineSessionInstances;
		uint8_t m_uiPublishedToFriendsSessionInstance;
	};

	struct FriendGameInfo
	{
		CGameID m_gameID;
		uint32_t m_unGameIP;
		uint16_t m_usGamePort;
		uint16_t m_usQueryPort;
		CSteamID m_steamIDLobby;
	};

	enum EChatEntryType
	{
		k_EChatEntryTypeInvalid = 0,
		k_EChatEntryTypeChatMsg = 1,		// Normal text message from another user
		k_EChatEntryTypeTyping = 2,			// Another user is typing (not used in multi-user chat)
		k_EChatEntryTypeInviteGame = 3,		// Invite from other user into that users current game
		k_EChatEntryTypeEmote = 4,			// text emote message (deprecated, should be treated as ChatMsg)
		//k_EChatEntryTypeLobbyGameStart = 5,	// lobby game is starting (dead - listen for LobbyGameCreated_t callback instead)
		k_EChatEntryTypeLeftConversation = 6, // user has left the conversation ( closed chat window )
		// Above are previous FriendMsgType entries, now merged into more generic chat entry types
		k_EChatEntryTypeEntered = 7,		// user has entered the conversation (used in multi-user chat and group chat)
		k_EChatEntryTypeWasKicked = 8,		// user was kicked (data: 64-bit steamid of actor performing the kick)
		k_EChatEntryTypeWasBanned = 9,		// user was banned (data: 64-bit steamid of actor performing the ban)
		k_EChatEntryTypeDisconnected = 10,	// user disconnected
		k_EChatEntryTypeHistoricalChat = 11,	// a chat message from user's chat history or offilne message
		//k_EChatEntryTypeReserved1 = 12, // No longer used
		//k_EChatEntryTypeReserved2 = 13, // No longer used
		k_EChatEntryTypeLinkBlocked = 14, // a link was removed by the chat filter.
	};

	//-----------------------------------------------------------------------------
// Purpose: list of states a friend can be in
//-----------------------------------------------------------------------------
	enum EPersonaState
	{
		k_EPersonaStateOffline = 0,			// friend is not currently logged on
		k_EPersonaStateOnline = 1,			// friend is logged on
		k_EPersonaStateBusy = 2,			// user is on, but busy
		k_EPersonaStateAway = 3,			// auto-away feature
		k_EPersonaStateSnooze = 4,			// auto-away for a long time
		k_EPersonaStateLookingToTrade = 5,	// Online, trading
		k_EPersonaStateLookingToPlay = 6,	// Online, wanting to play
		k_EPersonaStateInvisible = 7,		// Online, but appears offline to friends.  This status is never published to clients.
		k_EPersonaStateMax,
	};
	enum EFriendRelationship
	{
		k_EFriendRelationshipNone = 0,
		k_EFriendRelationshipBlocked = 1,			// this doesn't get stored; the user has just done an Ignore on an friendship invite
		k_EFriendRelationshipRequestRecipient = 2,
		k_EFriendRelationshipFriend = 3,
		k_EFriendRelationshipRequestInitiator = 4,
		k_EFriendRelationshipIgnored = 5,			// this is stored; the user has explicit blocked this other user from comments/chat/etc
		k_EFriendRelationshipIgnoredFriend = 6,
		k_EFriendRelationshipSuggested_DEPRECATED = 7,		// was used by the original implementation of the facebook linking feature, but now unused.

		// keep this updated
		k_EFriendRelationshipMax = 8,
	};

	enum EOverlayToStoreFlag
	{
		k_EOverlayToStoreFlag_None = 0,
		k_EOverlayToStoreFlag_AddToCart = 1,
		k_EOverlayToStoreFlag_AddToCartAndShow = 2,
	};

	struct FriendGameInfo_t
	{
		CGameID m_gameID;
		uint32 m_unGameIP;
		uint16 m_usGamePort;
		uint16 m_usQueryPort;
		CSteamID m_steamIDLobby;
	};
	enum EUserRestriction
	{
		k_nUserRestrictionNone = 0,	// no known chat/content restriction
		k_nUserRestrictionUnknown = 1,	// we don't know yet (user offline)
		k_nUserRestrictionAnyChat = 2,	// user is not allowed to (or can't) send/recv any chat
		k_nUserRestrictionVoiceChat = 4,	// user is not allowed to (or can't) send/recv voice chat
		k_nUserRestrictionGroupChat = 8,	// user is not allowed to (or can't) send/recv group chat
		k_nUserRestrictionRating = 16,	// user is too young according to rating in current region
		k_nUserRestrictionGameInvites = 32,	// user cannot send or recv game invites (e.g. mobile)
		k_nUserRestrictionTrading = 64,	// user cannot participate in trading (console, mobile)
	};

	class Friends
	{
	public:
		// returns the local players name - guaranteed to not be NULL.
// this is the same name as on the users community profile page
// this is stored in UTF-8 format
// like all the other interface functions that return a char *, it's important that this pointer is not saved
// off; it will eventually be free'd or re-allocated
		virtual const char* GetPersonaName();

		// sets the player name, stores it on the server and publishes the changes to all friends who are online
		virtual SteamAPICall_t SetPersonaName(const char* pchPersonaName);

		// gets the status of the current user
		virtual EPersonaState GetPersonaState();

		// friend iteration
		// takes a set of k_EFriendFlags, and returns the number of users the client knows about who meet that criteria
		// then GetFriendByIndex() can then be used to return the id's of each of those users
		virtual int GetFriendCount(int iFriendFlags);

		// returns the steamID of a user
		// iFriend is a index of range [0, GetFriendCount())
		// iFriendsFlags must be the same value as used in GetFriendCount()
		// the returned CSteamID can then be used by all the functions below to access details about the user
		virtual CSteamID GetFriendByIndex(int iFriend, int iFriendFlags);

		// returns a relationship to a user
		virtual EFriendRelationship GetFriendRelationship(CSteamID steamIDFriend);

		// returns the current status of the specified user
		// this will only be known by the local user if steamIDFriend is in their friends list; on the same game server; in a chat room or lobby; or in a small group with the local user
		virtual EPersonaState GetFriendPersonaState(CSteamID steamIDFriend);

		// returns the name another user - guaranteed to not be NULL.
		// same rules as GetFriendPersonaState() apply as to whether or not the user knowns the name of the other user
		// note that on first joining a lobby, chat room or game server the local user will not known the name of the other users automatically; that information will arrive asyncronously
		// 
		virtual const char* GetFriendPersonaName(CSteamID steamIDFriend);

		// returns true if the friend is actually in a game, and fills in pFriendGameInfo with an extra details 
		virtual bool GetFriendGamePlayed(CSteamID steamIDFriend, FriendGameInfo_t* pFriendGameInfo);
		// accesses old friends names - returns an empty string when their are no more items in the history
		virtual const char* GetFriendPersonaNameHistory(CSteamID steamIDFriend, int iPersonaName);

		// returns true if the specified user meets any of the criteria specified in iFriendFlags
		// iFriendFlags can be the union (binary or, |) of one or more k_EFriendFlags values
		virtual bool HasFriend(CSteamID steamIDFriend, int iFriendFlags);

		// clan (group) iteration and access functions
		virtual int GetClanCount();
		virtual CSteamID GetClanByIndex(int iClan);
		virtual const char* GetClanName(CSteamID steamIDClan);
		virtual const char* GetClanTag(CSteamID steamIDClan);

		virtual bool GetClanActivityCounts(CSteamID steamID, int* pnOnline, int* pnInGame, int* pnChatting);
		virtual SteamAPICall_t DownloadClanActivityCounts(CSteamID groupIDs[], int nIds);

		// iterators for getting users in a chat room, lobby, game server or clan
		// note that large clans that cannot be iterated by the local user
		// steamIDSource can be the steamID of a group, game server, lobby or chat room
		virtual int GetFriendCountFromSource(CSteamID steamIDSource);
		virtual CSteamID GetFriendFromSourceByIndex(CSteamID steamIDSource, int iFriend);

		// returns true if the local user can see that steamIDUser is a member or in steamIDSource
		virtual bool IsUserInSource(CSteamID steamIDUser, CSteamID steamIDSource);

		// User is in a game pressing the talk button (will suppress the microphone for all voice comms from the Steam friends UI)
		virtual void SetInGameVoiceSpeaking(CSteamID steamIDUser, bool bSpeaking);

		// activates the game overlay, with an optional dialog to open 
		// valid options are "Friends", "Community", "Players", "Settings", "LobbyInvite", "OfficialGameGroup", "Stats", "Achievements"
		virtual void ActivateGameOverlay(const char* pchDialog);

		// activates game overlay to a specific place
		// valid options are
		//		"steamid" - opens the overlay web browser to the specified user or groups profile
		//		"chat" - opens a chat window to the specified user, or joins the group chat 
		//		"stats" - opens the overlay web browser to the specified user's stats
		//		"achievements" - opens the overlay web browser to the specified user's achievements
		virtual void ActivateGameOverlayToUser(const char* pchDialog, CSteamID steamID);

		// activates game overlay web browser directly to the specified URL
		// full address with protocol type is required, e.g. http://www.steamgames.com/
		virtual void ActivateGameOverlayToWebPage(const char* pchURL);

		// activates game overlay to store page for app
		virtual void ActivateGameOverlayToStore(AppId_t nAppID, EOverlayToStoreFlag eFlag);

		// Mark a target user as 'played with'. This is a client-side only feature that requires that the calling user is 
		// in game 
		virtual void SetPlayedWith(CSteamID steamIDUserPlayedWith);

		// activates game overlay to open the invite dialog. Invitations will be sent for the provided lobby.
		// You can also use ActivateGameOverlay( "LobbyInvite" ) to allow the user to create invitations for their current public lobby.
		virtual void ActivateGameOverlayInviteDialog(CSteamID steamIDLobby);

		// gets the small (32x32) avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
		virtual int GetSmallFriendAvatar(CSteamID steamIDFriend);

		// gets the medium (64x64) avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
		virtual int GetMediumFriendAvatar(CSteamID steamIDFriend);

		// gets the large (184x184) avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
		// returns -1 if this image has yet to be loaded, in this case wait for a AvatarImageLoaded_t callback and then call this again
		virtual int GetLargeFriendAvatar(CSteamID steamIDFriend);

		// requests information about a user - persona name & avatar
		// if bRequireNameOnly is set, then the avatar of a user isn't downloaded 
		// - it's a lot slower to download avatars and churns the local cache, so if you don't need avatars, don't request them
		// if returns true, it means that data is being requested, and a PersonaStateChanged_t callback will be posted when it's retrieved
		// if returns false, it means that we already have all the details about that user, and functions can be called immediately
		virtual bool RequestUserInformation(CSteamID steamIDUser, bool bRequireNameOnly);

		// requests information about a clan officer list
		// when complete, data is returned in ClanOfficerListResponse_t call result
		// this makes available the calls below
		// you can only ask about clans that a user is a member of
		// note that this won't download avatars automatically; if you get an officer,
		// and no avatar image is available, call RequestUserInformation( steamID, false ) to download the avatar
		virtual SteamAPICall_t RequestClanOfficerList(CSteamID steamIDClan);

		// iteration of clan officers - can only be done when a RequestClanOfficerList() call has completed

		// returns the steamID of the clan owner
		virtual CSteamID GetClanOwner( CSteamID steamIDClan ) ;
		// returns the number of officers in a clan (including the owner)
			virtual int GetClanOfficerCount(CSteamID steamIDClan);
		// returns the steamID of a clan officer, by index, of range [0,GetClanOfficerCount)
		virtual CSteamID GetClanOfficerByIndex(CSteamID steamIDClan, int iOfficer);
		// if current user is chat restricted, he can't send or receive any text/voice chat messages.
		// the user can't see custom avatars. But the user can be online and send/recv game invites.
		// a chat restricted user can't add friends or join any groups.
		virtual EUserRestriction GetUserRestrictions_old();

		// Rich Presence data is automatically shared between friends who are in the same game
		// Each user has a set of Key/Value pairs
		// Up to 20 different keys can be set
		// There are two magic keys:
		//		"status"  - a UTF-8 string that will show up in the 'view game info' dialog in the Steam friends list
		//		"connect" - a UTF-8 string that contains the command-line for how a friend can connect to a game
		// GetFriendRichPresence() returns an empty string "" if no value is set
		// SetRichPresence() to a NULL or an empty string deletes the key
		// You can iterate the current set of keys for a friend with GetFriendRichPresenceKeyCount()
		// and GetFriendRichPresenceKeyByIndex() (typically only used for debugging)
		virtual bool SetRichPresence(const char* pchKey, const char* pchValue);
		virtual void ClearRichPresence();
		virtual const char* GetFriendRichPresence(CSteamID steamIDFriend, const char* pchKey);
		virtual int GetFriendRichPresenceKeyCount(CSteamID steamIDFriend);
		virtual const char* GetFriendRichPresenceKeyByIndex(CSteamID steamIDFriend, int iKey);
		virtual void RequestFriendRichPresence(CSteamID steamIDFriend);

		// rich invite support
		// if the target accepts the invite, the pchConnectString gets added to the command-line for launching the game
		// if the game is already running, a GameRichPresenceJoinRequested_t callback is posted containing the connect string
		// invites can only be sent to friends
		virtual bool InviteUserToGame(CSteamID steamIDFriend, const char* pchConnectString);

		// recently-played-with friends iteration
		// this iterates the entire list of users recently played with, across games
		// GetFriendCoplayTime() returns as a unix time
		virtual int GetCoplayFriendCount();
		virtual CSteamID GetCoplayFriend( int iCoplayFriend ) ;
			virtual int GetFriendCoplayTime(CSteamID steamIDFriend);
		virtual AppId_t GetFriendCoplayGame(CSteamID steamIDFriend);

		// chat interface for games
		// this allows in-game access to group (clan) chats from in the game
		// the behavior is somewhat sophisticated, because the user may or may not be already in the group chat from outside the game or in the overlay
		// use ActivateGameOverlayToUser( "chat", steamIDClan ) to open the in-game overlay version of the chat
		virtual SteamAPICall_t JoinClanChatRoom(CSteamID steamIDClan);
		virtual bool LeaveClanChatRoom(CSteamID steamIDClan);
		virtual int GetClanChatMemberCount(CSteamID steamIDClan);
		virtual CSteamID GetChatMemberByIndex( CSteamID steamIDClan, int iUser ) ;
			virtual bool SendClanChatMessage(CSteamID steamIDClanChat, const char* pchText);
		virtual int GetClanChatMessage(CSteamID steamIDClanChat, int iMessage, void* prgchText, int cchTextMax, EChatEntryType* peChatEntryType, CSteamID* pSteamIDChatter);
		virtual bool IsClanChatAdmin(CSteamID steamIDClanChat, CSteamID steamIDUser);

		// interact with the Steam (game overlay / desktop)
		virtual bool IsClanChatWindowOpenInSteam(CSteamID steamIDClanChat);
		virtual bool OpenClanChatWindowInSteam(CSteamID steamIDClanChat);
		virtual bool CloseClanChatWindowInSteam(CSteamID steamIDClanChat);

		// peer-to-peer chat interception
		// this is so you can show P2P chats inline in the game
		virtual bool SetListenForFriendsMessages(bool bInterceptEnabled);
		virtual bool ReplyToFriendMessage(CSteamID steamIDFriend, const char* pchMsgToSend);
		virtual int GetFriendMessage(CSteamID steamIDFriend, int iMessageID, void* pvData, int cubData, EChatEntryType* peChatEntryType);

		// following apis
		virtual SteamAPICall_t GetFollowerCount(CSteamID steamID);
		virtual SteamAPICall_t IsFollowing(CSteamID steamID);
		virtual SteamAPICall_t EnumerateFollowingList(uint32 unStartIndex);
	};
}
