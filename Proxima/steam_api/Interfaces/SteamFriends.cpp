#include "pch.h"
#include "SteamFriends.hpp"

STEAM_IGNORE_WARNINGS_START

namespace Steam
{
	const char *Friends::GetPersonaName()
	{
		return "PERSONA_NAME";
	}

	SteamAPICall_t Friends::SetPersonaName(const char *pchPersonaName)
	{
		return 0;
	}

	EPersonaState Friends::GetPersonaState()
	{
		return EPersonaState::k_EPersonaStateOnline;
	}

	int Friends::GetFriendCount(int eFriendFlags)
	{
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
		return "3arc";
	}

	const char* Friends::GetClanTag(CSteamID steamIDClan)
	{
		return nullptr;
	}

	bool Friends::GetClanActivityCounts(CSteamID steamID, int* pnOnline, int* pnInGame, int* pnChatting)
	{
		return false;
	}

	SteamAPICall_t Friends::DownloadClanActivityCounts(CSteamID groupIDs[], int nIds)
	{
		return SteamAPICall_t();
	}

	int Friends::GetFriendCountFromSource(CSteamID steamIDSource)
	{
		return 0;
	}

	CSteamID Friends::GetFriendFromSourceByIndex(CSteamID steamIDSource, int iFriend)
	{
		return CSteamID();
	}

	bool Friends::IsUserInSource(CSteamID steamIDUser, CSteamID steamIDSource)
	{
		return false;
	}

	void Friends::SetInGameVoiceSpeaking(CSteamID steamIDUser, bool bSpeaking)
	{
	}

	void Friends::ActivateGameOverlay(const char *pchDialog)
	{
	}

	void Friends::ActivateGameOverlayToUser(const char *pchDialog, CSteamID steamID)
	{
	}

	void Friends::ActivateGameOverlayToWebPage(const char *pchURL)
	{
	}

	void Friends::ActivateGameOverlayToStore(AppId_t nAppID, EOverlayToStoreFlag eFlag)
	{
	}

	void Friends::SetPlayedWith(CSteamID steamIDUserPlayedWith)
	{
	}
	void Friends::ActivateGameOverlayInviteDialog(CSteamID steamIDLobby)
	{
	}
	int Friends::GetSmallFriendAvatar(CSteamID steamIDFriend)
	{
		return 0;
	}
	int Friends::GetMediumFriendAvatar(CSteamID steamIDFriend)
	{
		return 0;
	}
	int Friends::GetLargeFriendAvatar(CSteamID steamIDFriend)
	{
		return 0;
	}
	bool Friends::RequestUserInformation(CSteamID steamIDUser, bool bRequireNameOnly)
	{
		return false;
	}
	SteamAPICall_t Friends::RequestClanOfficerList(CSteamID steamIDClan)
	{
		return SteamAPICall_t();
	}
	CSteamID Friends::GetClanOwner(CSteamID steamIDClan)
	{
		return CSteamID();
	}
	int Friends::GetClanOfficerCount(CSteamID steamIDClan)
	{
		return 0;
	}
	CSteamID Friends::GetClanOfficerByIndex(CSteamID steamIDClan, int iOfficer)
	{
		return CSteamID();
	}
	EUserRestriction Friends::GetUserRestrictions_old()
	{
		return EUserRestriction();
	}
	bool Friends::SetRichPresence(const char* pchKey, const char* pchValue)
	{
		return false;
	}
	void Friends::ClearRichPresence()
	{
	}
	const char* Friends::GetFriendRichPresence(CSteamID steamIDFriend, const char* pchKey)
	{
		return nullptr;
	}
	int Friends::GetFriendRichPresenceKeyCount(CSteamID steamIDFriend)
	{
		return 0;
	}
	const char* Friends::GetFriendRichPresenceKeyByIndex(CSteamID steamIDFriend, int iKey)
	{
		return nullptr;
	}
	void Friends::RequestFriendRichPresence(CSteamID steamIDFriend)
	{
	}
	bool Friends::InviteUserToGame(CSteamID steamIDFriend, const char* pchConnectString)
	{
		return false;
	}
	int Friends::GetCoplayFriendCount()
	{
		return 0;
	}
	CSteamID Friends::GetCoplayFriend(int iCoplayFriend)
	{
		return CSteamID();
	}
	int Friends::GetFriendCoplayTime(CSteamID steamIDFriend)
	{
		return 0;
	}
	AppId_t Friends::GetFriendCoplayGame(CSteamID steamIDFriend)
	{
		return AppId_t();
	}
	SteamAPICall_t Friends::JoinClanChatRoom(CSteamID steamIDClan)
	{
		return SteamAPICall_t();
	}
	bool Friends::LeaveClanChatRoom(CSteamID steamIDClan)
	{
		return false;
	}
	int Friends::GetClanChatMemberCount(CSteamID steamIDClan)
	{
		return 0;
	}
	CSteamID Friends::GetChatMemberByIndex(CSteamID steamIDClan, int iUser)
	{
		return CSteamID();
	}
	bool Friends::SendClanChatMessage(CSteamID steamIDClanChat, const char* pchText)
	{
		return false;
	}
	int Friends::GetClanChatMessage(CSteamID steamIDClanChat, int iMessage, void* prgchText, int cchTextMax, EChatEntryType* peChatEntryType, CSteamID* pSteamIDChatter)
	{
		return 0;
	}
	bool Friends::IsClanChatAdmin(CSteamID steamIDClanChat, CSteamID steamIDUser)
	{
		return false;
	}
	bool Friends::IsClanChatWindowOpenInSteam(CSteamID steamIDClanChat)
	{
		return false;
	}
	bool Friends::OpenClanChatWindowInSteam(CSteamID steamIDClanChat)
	{
		return false;
	}
	bool Friends::CloseClanChatWindowInSteam(CSteamID steamIDClanChat)
	{
		return false;
	}
	bool Friends::SetListenForFriendsMessages(bool bInterceptEnabled)
	{
		return false;
	}
	bool Friends::ReplyToFriendMessage(CSteamID steamIDFriend, const char* pchMsgToSend)
	{
		return false;
	}
	int Friends::GetFriendMessage(CSteamID steamIDFriend, int iMessageID, void* pvData, int cubData, EChatEntryType* peChatEntryType)
	{
		return 0;
	}
	SteamAPICall_t Friends::GetFollowerCount(CSteamID steamID)
	{
		return SteamAPICall_t();
	}
	SteamAPICall_t Friends::IsFollowing(CSteamID steamID)
	{
		return SteamAPICall_t();
	}
	SteamAPICall_t Friends::EnumerateFollowingList(uint32 unStartIndex)
	{
		return SteamAPICall_t();
	}
}

STEAM_IGNORE_WARNINGS_END
