#include "pch.h"

STEAM_IGNORE_WARNINGS_START

namespace Steam
{
	bool Networking::SendP2PPacket(CSteamID steamIDRemote, const void* pubData, uint32 cubData, EP2PSend eP2PSendType, int nChannel)
	{
		return false;
	}
	bool Networking::IsP2PPacketAvailable(uint32* pcubMsgSize, int nChannel)
	{
		return false;
	}
	bool Networking::ReadP2PPacket(void* pubDest, uint32 cubDest, uint32* pcubMsgSize, CSteamID* psteamIDRemote, int nChannel)
	{
		return false;
	}
	bool Networking::AcceptP2PSessionWithUser(CSteamID steamIDRemote)
	{
		return false;
	}

	bool Networking::CloseP2PSessionWithUser(CSteamID steamIDRemote)
	{
		return false;
	}

	bool Networking::CloseP2PChannelWithUser(CSteamID steamIDRemote, int nChannel)
	{
		return false;
	}

	bool Networking::GetP2PSessionState(CSteamID steamIDRemote, P2PSessionState_t* pConnectionState)
	{
		return false;
	}

	bool Networking::AllowP2PPacketRelay(bool bAllow)
	{
		return false;
	}

	SNetListenSocket_t Networking::CreateListenSocket(int nVirtualP2PPort, uint32 nIP, uint16 nPort, bool bAllowUseOfPacketRelay)
	{
		return SNetListenSocket_t();
	}

	unsigned int Networking::CreateP2PConnectionSocket(CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec, bool bAllowUseOfPacketRelay)
	{
		return NULL;
	}

	SNetSocket_t Networking::CreateConnectionSocket(uint32 nIP, uint16 nPort, int nTimeoutSec)
	{
		return SNetSocket_t();
	}

	bool Networking::DestroySocket(SNetSocket_t hSocket, bool bNotifyRemoteEnd)
	{
		return false;
	}

	bool Networking::DestroyListenSocket(SNetListenSocket_t hSocket, bool bNotifyRemoteEnd)
	{
		return false;
	}

	bool Networking::SendDataOnSocket(SNetSocket_t hSocket, void* pubData, uint32 cubData, bool bReliable)
	{
		return false;
	}
	bool Networking::IsDataAvailableOnSocket(SNetSocket_t hSocket, uint32* pcubMsgSize)
	{
		return false;
	}
	bool Networking::RetrieveDataFromSocket(SNetSocket_t hSocket, void* pubDest, uint32 cubDest, uint32* pcubMsgSize)
	{
		return false;
	}
	bool Networking::IsDataAvailable(SNetListenSocket_t hListenSocket, uint32* pcubMsgSize, SNetSocket_t* phSocket)
	{
		return false;
	}
	bool Networking::RetrieveData(SNetListenSocket_t hListenSocket, void* pubDest, uint32 cubDest, uint32* pcubMsgSize, SNetSocket_t* phSocket)
	{
		return false;
	}
	bool Networking::GetSocketInfo(SNetSocket_t hSocket, CSteamID* pSteamIDRemote, int* peSocketStatus, uint32* punIPRemote, uint16* punPortRemote)
	{
		return false;
	}
	bool Networking::GetListenSocketInfo(SNetListenSocket_t hListenSocket, uint32* pnIP, uint16* pnPort)
	{
		return false;
	}
	ESNetSocketConnectionType Networking::GetSocketConnectionType(SNetSocket_t hSocket)
	{
		return ESNetSocketConnectionType();
	}
	int Networking::GetMaxPacketSize(SNetSocket_t hSocket)
	{
		return 0;
	}
}

STEAM_IGNORE_WARNINGS_END
