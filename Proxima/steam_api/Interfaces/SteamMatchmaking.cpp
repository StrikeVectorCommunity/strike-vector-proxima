#include "pch.h"
#include "SteamMatchmaking.hpp"

STEAM_IGNORE_WARNINGS_START

namespace Steam
{
	int Matchmaking::GetFavoriteGameCount()
	{
		DUMP_FUNC_NAME();
		return 0;
	}

	bool Matchmaking::GetFavoriteGame( int iGame, AppId_t *pnAppID, uint32 *pnIP, uint16 *pnConnPort, uint16 *pnQueryPort, uint32 *punFlags, uint32 *pRTime32LastPlayedOnServer )
	{
		DUMP_FUNC_NAME();
		return false;
	}

	int Matchmaking::AddFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer )
	{
		DUMP_FUNC_NAME();
		return 0;
	}

	bool Matchmaking::RemoveFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags )
	{
		DUMP_FUNC_NAME();
		return false;
	}

	unsigned __int64 Matchmaking::RequestLobbyList()
	{
		DUMP_FUNC_NAME();
		return 0;
	}

	void Matchmaking::AddRequestLobbyListStringFilter(const char* pchKeyToMatch, const char* pchValueToMatch, ELobbyComparison eComparisonType)
	{
		DUMP_FUNC_NAME();
	}

	void Matchmaking::AddRequestLobbyListNumericalFilter(const char* pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType)
	{
		DUMP_FUNC_NAME();
	}

	void Matchmaking::AddRequestLobbyListNearValueFilter(const char* pchKeyToMatch, int nValueToBeCloseTo)
	{
		DUMP_FUNC_NAME();
	}

	void Matchmaking::AddRequestLobbyListFilterSlotsAvailable(int nSlotsAvailable)
	{
		DUMP_FUNC_NAME();
	}

	void Matchmaking::AddRequestLobbyListDistanceFilter(ELobbyDistanceFilter eLobbyDistanceFilter)
	{
		DUMP_FUNC_NAME();
	}

	void Matchmaking::AddRequestLobbyListResultCountFilter(int cMaxResults)
	{
		DUMP_FUNC_NAME();
	}

	void Matchmaking::AddRequestLobbyListCompatibleMembersFilter(CSteamID steamIDLobby)
	{
		DUMP_FUNC_NAME();
	}

	CSteamID Matchmaking::GetLobbyByIndex(int iLobby)
	{
		DUMP_FUNC_NAME();
		return CSteamID();
	}

	SteamAPICall_t Matchmaking::CreateLobby( ELobbyType eLobbyType, int cMaxMembers )
	{
		DUMP_FUNC_NAME();
	/*	uint64_t result = Callbacks::RegisterCall();
		LobbyCreated* retvals = ::Utils::Memory::Allocate<LobbyCreated>();
		CSteamID id;

		id.accountID = 1337132;
		id.universe = 1;
		id.accountType = 8;
		id.accountInstance = 0x40000;

		retvals->m_eResult = 1;
		retvals->m_ulSteamIDLobby = id;

		Callbacks::ReturnCall(retvals, sizeof(LobbyCreated), LobbyCreated::CallbackID, result);*/

		//Matchmaking::JoinLobby(id);

		return 0;
	}

	SteamAPICall_t Matchmaking::JoinLobby(CSteamID steamIDLobby)
	{
		DUMP_FUNC_NAME();
		//uint64_t result = Callbacks::RegisterCall();
		//LobbyEnter* retvals = ::Utils::Memory::Allocate<LobbyEnter>();
		//retvals->m_bLocked = false;
		//retvals->m_EChatRoomEnterResponse = 1;
		//retvals->m_rgfChatPermissions = 0xFFFFFFFF;
		//retvals->m_ulSteamIDLobby = steamIDLobby;

		//Callbacks::ReturnCall(retvals, sizeof(LobbyEnter), LobbyEnter::CallbackID, result);

		return 0;
	}

	void Matchmaking::LeaveLobby(CSteamID steamIDLobby)
	{
		DUMP_FUNC_NAME();
		//Components::Party::RemoveLobby(steamIDLobby);
	}

	bool Matchmaking::InviteUserToLobby(CSteamID steamIDLobby, CSteamID steamIDInvitee)
	{
		DUMP_FUNC_NAME();
		return true;
	}

	int Matchmaking::GetNumLobbyMembers(CSteamID steamIDLobby)
	{
		DUMP_FUNC_NAME();
		return 1;
	}

	CSteamID Matchmaking::GetLobbyMemberByIndex(CSteamID steamIDLobby, int iMember)
	{
		DUMP_FUNC_NAME();
		return SteamUser()->GetSteamID();
	}

	const char *Matchmaking::GetLobbyData(CSteamID steamIDLobby, const char *pchKey)
	{
		DUMP_FUNC_NAME();
		DUMP_FUNC_NAME();
		return nullptr;
		//return Components::Party::GetLobbyInfo(steamIDLobby, pchKey);
	}

	bool Matchmaking::SetLobbyData(CSteamID steamIDLobby, const char *pchKey, const char *pchValue)
	{
		DUMP_FUNC_NAME();
		return true;
	}

	int Matchmaking::GetLobbyDataCount(CSteamID steamIDLobby)
	{
		DUMP_FUNC_NAME();
		return 0;
	}

	bool Matchmaking::GetLobbyDataByIndex(CSteamID steamIDLobby, int iLobbyData, char *pchKey, int cchKeyBufferSize, char *pchValue, int cchValueBufferSize)
	{
		DUMP_FUNC_NAME();
		return false;
	}

	bool Matchmaking::DeleteLobbyData(CSteamID steamIDLobby, const char *pchKey)
	{
		DUMP_FUNC_NAME();
		return false;
	}

	const char *Matchmaking::GetLobbyMemberData(CSteamID steamIDLobby, CSteamID steamIDUser, const char *pchKey)
	{
		DUMP_FUNC_NAME();
		return "";
	}

	void Matchmaking::SetLobbyMemberData(CSteamID steamIDLobby, const char *pchKey, const char *pchValue)
	{
		DUMP_FUNC_NAME();
	}

	bool Matchmaking::SendLobbyChatMsg(CSteamID steamIDLobby, const void *pvMsgBody, int cubMsgBody)
	{
		DUMP_FUNC_NAME();
		return true;
	}

	int Matchmaking::GetLobbyChatEntry(CSteamID steamIDLobby, int iChatID, CSteamID *pSteamIDUser, void *pvData, int cubData, EChatEntryType *peChatEntryType )
	{
		DUMP_FUNC_NAME();
		return 0;
	}

	bool Matchmaking::RequestLobbyData(CSteamID steamIDLobby)
	{
		DUMP_FUNC_NAME();
		return false;
	}

	void Matchmaking::SetLobbyGameServer(CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer)
	{
		DUMP_FUNC_NAME();
	}

	bool Matchmaking::GetLobbyGameServer(CSteamID steamIDLobby, uint32 * punGameServerIP, uint16 * punGameServerPort, CSteamID * psteamIDGameServer)
	{
		DUMP_FUNC_NAME();
		return false;
	}

	bool Matchmaking::SetLobbyMemberLimit(CSteamID steamIDLobby, int cMaxMembers)
	{
		DUMP_FUNC_NAME();
		return true;
	}

	int Matchmaking::GetLobbyMemberLimit(CSteamID steamIDLobby)
	{
		DUMP_FUNC_NAME();
		return 0;
	}

	bool Matchmaking::SetLobbyType(CSteamID steamIDLobby, ELobbyType eLobbyType)
	{
		DUMP_FUNC_NAME();
		return true;
	}

	bool Matchmaking::SetLobbyJoinable(CSteamID steamIDLobby, bool bLobbyJoinable)
	{
		DUMP_FUNC_NAME();
		return true;
	}

	CSteamID Matchmaking::GetLobbyOwner(CSteamID steamIDLobby)
	{
		DUMP_FUNC_NAME();
		return SteamUser()->GetSteamID();
	}

	bool Matchmaking::SetLobbyOwner(CSteamID steamIDLobby, CSteamID steamIDNewOwner)
	{
		DUMP_FUNC_NAME();
		return true;
	}
	bool Matchmaking::SetLinkedLobby(CSteamID steamIDLobby, CSteamID steamIDLobbyDependent)
	{
		DUMP_FUNC_NAME();
		return false;
	}
}

STEAM_IGNORE_WARNINGS_END
