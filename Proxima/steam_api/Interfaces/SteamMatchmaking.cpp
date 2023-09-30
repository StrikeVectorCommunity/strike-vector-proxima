#include "pch.h"
#include "SteamMatchmaking.hpp"

STEAM_IGNORE_WARNINGS_START

namespace Steam
{
	int Matchmaking::GetFavoriteGameCount()
	{
		return 0;
	}

	bool Matchmaking::GetFavoriteGame( int iGame, AppId_t *pnAppID, uint32 *pnIP, uint16 *pnConnPort, uint16 *pnQueryPort, uint32 *punFlags, uint32 *pRTime32LastPlayedOnServer )
	{
		return false;
	}

	int Matchmaking::AddFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer )
	{
		return 0;
	}

	bool Matchmaking::RemoveFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags )
	{
		return false;
	}

	unsigned __int64 Matchmaking::RequestLobbyList()
	{
		DUMP_FUNC_NAME();
		return 0;
	}

	void Matchmaking::AddRequestLobbyListStringFilter(const char* pchKeyToMatch, const char* pchValueToMatch, ELobbyComparison eComparisonType)
	{
	}

	void Matchmaking::AddRequestLobbyListNumericalFilter(const char* pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType)
	{
	}

	void Matchmaking::AddRequestLobbyListNearValueFilter(const char* pchKeyToMatch, int nValueToBeCloseTo)
	{
	}

	void Matchmaking::AddRequestLobbyListFilterSlotsAvailable(int nSlotsAvailable)
	{
	}

	void Matchmaking::AddRequestLobbyListDistanceFilter(ELobbyDistanceFilter eLobbyDistanceFilter)
	{
	}

	void Matchmaking::AddRequestLobbyListResultCountFilter(int cMaxResults)
	{
	}

	void Matchmaking::AddRequestLobbyListCompatibleMembersFilter(CSteamID steamIDLobby)
	{
	}

	CSteamID Matchmaking::GetLobbyByIndex(int iLobby)
	{
		return CSteamID();
	}

	SteamAPICall_t Matchmaking::CreateLobby( ELobbyType eLobbyType, int cMaxMembers )
	{
		uint64_t result = Callbacks::RegisterCall();
		//LobbyCreated* retvals = ::Utils::Memory::Allocate<LobbyCreated>();
		//CSteamID id;

		//id.accountID = 1337132;
		//id.universe = 1;
		//id.accountType = 8;
		//id.accountInstance = 0x40000;

		//retvals->m_eResult = 1;
		//retvals->m_ulSteamIDLobby = id;

		//Callbacks::ReturnCall(retvals, sizeof(LobbyCreated), LobbyCreated::CallbackID, result);

		//Matchmaking::JoinLobby(id);

		return result;
	}

	SteamAPICall_t Matchmaking::JoinLobby(CSteamID steamIDLobby)
	{
		uint64_t result = Callbacks::RegisterCall();
		//LobbyEnter* retvals = ::Utils::Memory::Allocate<LobbyEnter>();
		//retvals->m_bLocked = false;
		//retvals->m_EChatRoomEnterResponse = 1;
		//retvals->m_rgfChatPermissions = 0xFFFFFFFF;
		//retvals->m_ulSteamIDLobby = steamIDLobby;

		//Callbacks::ReturnCall(retvals, sizeof(LobbyEnter), LobbyEnter::CallbackID, result);

		return result;
	}

	void Matchmaking::LeaveLobby(CSteamID steamIDLobby)
	{
		//Components::Party::RemoveLobby(steamIDLobby);
	}

	bool Matchmaking::InviteUserToLobby(CSteamID steamIDLobby, CSteamID steamIDInvitee)
	{
		return true;
	}

	int Matchmaking::GetNumLobbyMembers(CSteamID steamIDLobby)
	{
		return 1;
	}

	CSteamID Matchmaking::GetLobbyMemberByIndex(CSteamID steamIDLobby, int iMember)
	{
		return SteamUser()->GetSteamID();
	}

	const char *Matchmaking::GetLobbyData(CSteamID steamIDLobby, const char *pchKey)
	{
		DUMP_FUNC_NAME();
		return nullptr;
		//return Components::Party::GetLobbyInfo(steamIDLobby, pchKey);
	}

	bool Matchmaking::SetLobbyData(CSteamID steamIDLobby, const char *pchKey, const char *pchValue)
	{
		return true;
	}

	int Matchmaking::GetLobbyDataCount(CSteamID steamIDLobby)
	{
		DUMP_FUNC_NAME();
		return 0;
	}

	bool Matchmaking::GetLobbyDataByIndex(CSteamID steamIDLobby, int iLobbyData, char *pchKey, int cchKeyBufferSize, char *pchValue, int cchValueBufferSize)
	{
		return false;
	}

	bool Matchmaking::DeleteLobbyData(CSteamID steamIDLobby, const char *pchKey)
	{
		return false;
	}

	const char *Matchmaking::GetLobbyMemberData(CSteamID steamIDLobby, CSteamID steamIDUser, const char *pchKey)
	{
		return "";
	}

	void Matchmaking::SetLobbyMemberData(CSteamID steamIDLobby, const char *pchKey, const char *pchValue)
	{
	}

	bool Matchmaking::SendLobbyChatMsg(CSteamID steamIDLobby, const void *pvMsgBody, int cubMsgBody)
	{
		return true;
	}

	int Matchmaking::GetLobbyChatEntry(CSteamID steamIDLobby, int iChatID, CSteamID *pSteamIDUser, void *pvData, int cubData, EChatEntryType *peChatEntryType )
	{
		return 0;
	}

	bool Matchmaking::RequestLobbyData(CSteamID steamIDLobby)
	{
		return false;
	}

	void Matchmaking::SetLobbyGameServer(CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer)
	{
	}

	bool Matchmaking::GetLobbyGameServer(CSteamID steamIDLobby, uint32 * punGameServerIP, uint16 * punGameServerPort, CSteamID * psteamIDGameServer)
	{
		return false;
	}

	bool Matchmaking::SetLobbyMemberLimit(CSteamID steamIDLobby, int cMaxMembers)
	{
		return true;
	}

	int Matchmaking::GetLobbyMemberLimit(CSteamID steamIDLobby)
	{
		return 0;
	}

	bool Matchmaking::SetLobbyType(CSteamID steamIDLobby, ELobbyType eLobbyType)
	{
		return true;
	}

	bool Matchmaking::SetLobbyJoinable(CSteamID steamIDLobby, bool bLobbyJoinable)
	{
		return true;
	}

	CSteamID Matchmaking::GetLobbyOwner(CSteamID steamIDLobby)
	{
		return SteamUser()->GetSteamID();
	}

	bool Matchmaking::SetLobbyOwner(CSteamID steamIDLobby, CSteamID steamIDNewOwner)
	{
		return true;
	}
	bool Matchmaking::SetLinkedLobby(CSteamID steamIDLobby, CSteamID steamIDLobbyDependent)
	{
		return false;
	}
}

STEAM_IGNORE_WARNINGS_END
