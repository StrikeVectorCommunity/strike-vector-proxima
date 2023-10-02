#include "pch.h"

STEAM_IGNORE_WARNINGS_START

namespace Steam
{
	const char *Friends::GetPersonaName()
	{
		return Proxima::Client::GetName();
	}

	SteamAPICall_t Friends::SetPersonaName(const char *pchPersonaName)
	{
		DUMP_FUNC_NAME();
		return 0;
	}

	EPersonaState Friends::GetPersonaState()
	{
		return EPersonaState::k_EPersonaStateOnline;
	}

	int Friends::GetFriendCount(int eFriendFlags)
	{
		DUMP_FUNC_NAME();
		return 0;
	}

	CSteamID Friends::GetFriendByIndex(int iFriend, int iFriendFlags)
	{
		return CSteamID();
	}

	EFriendRelationship Friends::GetFriendRelationship(CSteamID steamIDFriend)
	{
		return EFriendRelationship::k_EFriendRelationshipNone;
	}

	EPersonaState Friends::GetFriendPersonaState(CSteamID steamIDFriend)
	{
		return EPersonaState::k_EPersonaStateOnline;
	}

	const char *Friends::GetFriendPersonaName(CSteamID steamIDFriend)
	{
		return "";
	}

	bool Friends::GetFriendGamePlayed(CSteamID steamIDFriend, FriendGameInfo_t* pFriendGameInfo)
	{
		return false;
	}

	const char *Friends::GetFriendPersonaNameHistory(CSteamID steamIDFriend, int iPersonaName)
	{
		return "";
	}

	bool Friends::HasFriend(CSteamID steamIDFriend, int eFriendFlags)
	{
		return false;
	}

	int Friends::GetClanCount()
	{
		return 0;
	}

	CSteamID Friends::GetClanByIndex(int iClan)
	{
		return CSteamID();
	}

	const char *Friends::GetClanName(CSteamID steamIDClan)
	{
		return "VKTR";
	}

	const char* Friends::GetClanTag(CSteamID steamIDClan)
	{
		DUMP_FUNC_NAME();
		return nullptr;
	}

	bool Friends::GetClanActivityCounts(CSteamID steamID, int* pnOnline, int* pnInGame, int* pnChatting)
	{
		DUMP_FUNC_NAME();
		return false;
	}

	SteamAPICall_t Friends::DownloadClanActivityCounts(CSteamID groupIDs[], int nIds)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}

	int Friends::GetFriendCountFromSource(CSteamID steamIDSource)
	{
		DUMP_FUNC_NAME();
		return 0;
	}

	CSteamID Friends::GetFriendFromSourceByIndex(CSteamID steamIDSource, int iFriend)
	{
		DUMP_FUNC_NAME();
		return CSteamID();
	}

	bool Friends::IsUserInSource(CSteamID steamIDUser, CSteamID steamIDSource)
	{
		DUMP_FUNC_NAME();
		return false;
	}

	void Friends::SetInGameVoiceSpeaking(CSteamID steamIDUser, bool bSpeaking)
	{
		DUMP_FUNC_NAME();
	}

	void Friends::ActivateGameOverlay(const char *pchDialog)
	{
		DUMP_FUNC_NAME();
	}

	void Friends::ActivateGameOverlayToUser(const char *pchDialog, CSteamID steamID)
	{
		DUMP_FUNC_NAME();
	}

	void Friends::ActivateGameOverlayToWebPage(const char *pchURL)
	{
		DUMP_FUNC_NAME();
	}

	void Friends::ActivateGameOverlayToStore(AppId_t nAppID, EOverlayToStoreFlag eFlag)
	{
		DUMP_FUNC_NAME();
	}

	void Friends::SetPlayedWith(CSteamID steamIDUserPlayedWith)
	{
		DUMP_FUNC_NAME();
	}
	void Friends::ActivateGameOverlayInviteDialog(CSteamID steamIDLobby)
	{
		DUMP_FUNC_NAME();
	}
	int Friends::GetSmallFriendAvatar(CSteamID steamIDFriend)
	{
		DUMP_FUNC_NAME();
		return 0;
	}
	int Friends::GetMediumFriendAvatar(CSteamID steamIDFriend)
	{
		DUMP_FUNC_NAME();
		return 0;
	}
	int Friends::GetLargeFriendAvatar(CSteamID steamIDFriend)
	{
		DUMP_FUNC_NAME();
		return 0;
	}
	bool Friends::RequestUserInformation(CSteamID steamIDUser, bool bRequireNameOnly)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	SteamAPICall_t Friends::RequestClanOfficerList(CSteamID steamIDClan)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	CSteamID Friends::GetClanOwner(CSteamID steamIDClan)
	{
		DUMP_FUNC_NAME();
		return CSteamID();
	}
	int Friends::GetClanOfficerCount(CSteamID steamIDClan)
	{
		DUMP_FUNC_NAME();
		return 0;
	}
	CSteamID Friends::GetClanOfficerByIndex(CSteamID steamIDClan, int iOfficer)
	{
		DUMP_FUNC_NAME();
		return CSteamID();
	}
	EUserRestriction Friends::GetUserRestrictions_old()
	{
		DUMP_FUNC_NAME();
		return EUserRestriction();
	}
	bool Friends::SetRichPresence(const char* pchKey, const char* pchValue)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	void Friends::ClearRichPresence()
	{
		DUMP_FUNC_NAME();
	}
	const char* Friends::GetFriendRichPresence(CSteamID steamIDFriend, const char* pchKey)
	{
		DUMP_FUNC_NAME();
		return nullptr;
	}
	int Friends::GetFriendRichPresenceKeyCount(CSteamID steamIDFriend)
	{
		DUMP_FUNC_NAME();
		return 0;
	}
	const char* Friends::GetFriendRichPresenceKeyByIndex(CSteamID steamIDFriend, int iKey)
	{
		DUMP_FUNC_NAME();
		return nullptr;
	}
	void Friends::RequestFriendRichPresence(CSteamID steamIDFriend)
	{
		DUMP_FUNC_NAME();
	}
	bool Friends::InviteUserToGame(CSteamID steamIDFriend, const char* pchConnectString)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	int Friends::GetCoplayFriendCount()
	{
		DUMP_FUNC_NAME();
		return 0;
	}
	CSteamID Friends::GetCoplayFriend(int iCoplayFriend)
	{
		DUMP_FUNC_NAME();
		return CSteamID();
	}
	int Friends::GetFriendCoplayTime(CSteamID steamIDFriend)
	{
		DUMP_FUNC_NAME();
		return 0;
	}
	AppId_t Friends::GetFriendCoplayGame(CSteamID steamIDFriend)
	{
		DUMP_FUNC_NAME();
		return AppId_t();
	}
	SteamAPICall_t Friends::JoinClanChatRoom(CSteamID steamIDClan)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	bool Friends::LeaveClanChatRoom(CSteamID steamIDClan)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	int Friends::GetClanChatMemberCount(CSteamID steamIDClan)
	{
		DUMP_FUNC_NAME();
		return 0;
	}
	CSteamID Friends::GetChatMemberByIndex(CSteamID steamIDClan, int iUser)
	{
		DUMP_FUNC_NAME();
		return CSteamID();
	}
	bool Friends::SendClanChatMessage(CSteamID steamIDClanChat, const char* pchText)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	int Friends::GetClanChatMessage(CSteamID steamIDClanChat, int iMessage, void* prgchText, int cchTextMax, EChatEntryType* peChatEntryType, CSteamID* pSteamIDChatter)
	{
		DUMP_FUNC_NAME();
		return 0;
	}
	bool Friends::IsClanChatAdmin(CSteamID steamIDClanChat, CSteamID steamIDUser)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	bool Friends::IsClanChatWindowOpenInSteam(CSteamID steamIDClanChat)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	bool Friends::OpenClanChatWindowInSteam(CSteamID steamIDClanChat)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	bool Friends::CloseClanChatWindowInSteam(CSteamID steamIDClanChat)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	bool Friends::SetListenForFriendsMessages(bool bInterceptEnabled)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	bool Friends::ReplyToFriendMessage(CSteamID steamIDFriend, const char* pchMsgToSend)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	int Friends::GetFriendMessage(CSteamID steamIDFriend, int iMessageID, void* pvData, int cubData, EChatEntryType* peChatEntryType)
	{
		DUMP_FUNC_NAME();
		return 0;
	}
	SteamAPICall_t Friends::GetFollowerCount(CSteamID steamID)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	SteamAPICall_t Friends::IsFollowing(CSteamID steamID)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	SteamAPICall_t Friends::EnumerateFollowingList(uint32 unStartIndex)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
}

STEAM_IGNORE_WARNINGS_END
