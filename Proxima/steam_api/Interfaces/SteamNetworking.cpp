#include "pch.h"

STEAM_IGNORE_WARNINGS_START

namespace Steam
{
	bool Networking::SendP2PPacket(CSteamID steamIDRemote, const void* pubData, uint32 cubData, EP2PSend eP2PSendType, int nChannel)
	{
		DUMP_FUNC_NAME();

		return false;
	}
	bool Networking::IsP2PPacketAvailable(uint32* pcubMsgSize, int nChannel)
	{
		DUMP_FUNC_NAME();

		return false;
	}
	bool Networking::ReadP2PPacket(void* pubDest, uint32 cubDest, uint32* pcubMsgSize, CSteamID* psteamIDRemote, int nChannel)
	{
		DUMP_FUNC_NAME();

		return false;
	}
	bool Networking::AcceptP2PSessionWithUser(CSteamID steamIDRemote)
	{
		DUMP_FUNC_NAME();

		return false;
	}

	bool Networking::CloseP2PSessionWithUser(CSteamID steamIDRemote)
	{
		DUMP_FUNC_NAME();

		return false;
	}

	bool Networking::CloseP2PChannelWithUser(CSteamID steamIDRemote, int nChannel)
	{
		DUMP_FUNC_NAME();

		return false;
	}

	bool Networking::GetP2PSessionState(CSteamID steamIDRemote, P2PSessionState_t* pConnectionState)
	{
		DUMP_FUNC_NAME();

		return false;
	}

	bool Networking::AllowP2PPacketRelay(bool bAllow)
	{
		DUMP_FUNC_NAME();

		return false;
	}

	SNetListenSocket_t Networking::CreateListenSocket(int nVirtualP2PPort, uint32 nIP, uint16 nPort, bool bAllowUseOfPacketRelay)
	{
		DUMP_FUNC_NAME();

		return SNetListenSocket_t();
	}

	unsigned int Networking::CreateP2PConnectionSocket(CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec, bool bAllowUseOfPacketRelay)
	{
		DUMP_FUNC_NAME();

		return NULL;
	}

	SNetSocket_t Networking::CreateConnectionSocket(uint32 nIP, uint16 nPort, int nTimeoutSec)
	{
		DUMP_FUNC_NAME();

		return SNetSocket_t();
	}

	bool Networking::DestroySocket(SNetSocket_t hSocket, bool bNotifyRemoteEnd)
	{
		DUMP_FUNC_NAME();

		return false;
	}

	bool Networking::DestroyListenSocket(SNetListenSocket_t hSocket, bool bNotifyRemoteEnd)
	{
		DUMP_FUNC_NAME();

		return false;
	}

	bool Networking::SendDataOnSocket(SNetSocket_t hSocket, void* pubData, uint32 cubData, bool bReliable)
	{
		DUMP_FUNC_NAME();

		return false;
	}
	bool Networking::IsDataAvailableOnSocket(SNetSocket_t hSocket, uint32* pcubMsgSize)
	{
		DUMP_FUNC_NAME();

		return false;
	}
	bool Networking::RetrieveDataFromSocket(SNetSocket_t hSocket, void* pubDest, uint32 cubDest, uint32* pcubMsgSize)
	{
		DUMP_FUNC_NAME();

		return false;
	}
	bool Networking::IsDataAvailable(SNetListenSocket_t hListenSocket, uint32* pcubMsgSize, SNetSocket_t* phSocket)
	{
		DUMP_FUNC_NAME();

		return false;
	}
	bool Networking::RetrieveData(SNetListenSocket_t hListenSocket, void* pubDest, uint32 cubDest, uint32* pcubMsgSize, SNetSocket_t* phSocket)
	{
		DUMP_FUNC_NAME();

		return false;
	}
	bool Networking::GetSocketInfo(SNetSocket_t hSocket, CSteamID* pSteamIDRemote, int* peSocketStatus, uint32* punIPRemote, uint16* punPortRemote)
	{
		DUMP_FUNC_NAME();

		return false;
	}
	bool Networking::GetListenSocketInfo(SNetListenSocket_t hListenSocket, uint32* pnIP, uint16* pnPort)
	{
		DUMP_FUNC_NAME();

		return false;
	}
	ESNetSocketConnectionType Networking::GetSocketConnectionType(SNetSocket_t hSocket)
	{
		DUMP_FUNC_NAME();

		return ESNetSocketConnectionType();
	}
	int Networking::GetMaxPacketSize(SNetSocket_t hSocket)
	{
		DUMP_FUNC_NAME();

		return 0;
	}
}

STEAM_IGNORE_WARNINGS_END
