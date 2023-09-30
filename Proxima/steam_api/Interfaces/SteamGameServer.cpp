#include "pch.h"

STEAM_IGNORE_WARNINGS_START

namespace Steam
{
    bool GameServer::InitGameServer(uint32 unIP, uint16 usGamePort, uint16 usQueryPort, uint32 unFlags, AppId_t nGameAppId, const char* pchVersionString)
    {
        DUMP_FUNC_NAME();
        return true;
    }
    void GameServer::SetProduct(const char* pszProduct)
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::SetGameDescription(const char* pszGameDescription)
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::SetModDir(const char* pszModDir)
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::SetDedicatedServer(bool bDedicated)
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::LogOn(const char* pszAccountName, const char* pszPassword)
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::LogOnAnonymous()
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::LogOff()
    {
        DUMP_FUNC_NAME();
    }
    bool GameServer::BLoggedOn()
    {
        DUMP_FUNC_NAME();
        return true;
    }
    bool GameServer::BSecure()
    {
        DUMP_FUNC_NAME();
        return true;
    }
    CSteamID GameServer::GetSteamID()
    {
        DUMP_FUNC_NAME();
        return CSteamID();
    }
    bool GameServer::WasRestartRequested()
    {
        DUMP_FUNC_NAME();
        return false;
    }
    void GameServer::SetMaxPlayerCount(int cPlayersMax)
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::SetBotPlayerCount(int cBotplayers)
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::SetServerName(const char* pszServerName)
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::SetMapName(const char* pszMapName)
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::SetPasswordProtected(bool bPasswordProtected)
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::SetSpectatorPort(uint16 unSpectatorPort)
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::SetSpectatorServerName(const char* pszSpectatorServerName)
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::ClearAllKeyValues()
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::SetKeyValue(const char* pKey, const char* pValue)
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::SetGameTags(const char* pchGameTags)
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::SetGameData(const char* pchGameData)
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::SetRegion(const char* pszRegion)
    {
        DUMP_FUNC_NAME();
    }
    bool GameServer::SendUserConnectAndAuthenticate(uint32 unIPClient, const void* pvAuthBlob, uint32 cubAuthBlobSize, CSteamID* pSteamIDUser)
    {
        DUMP_FUNC_NAME();
        return false;
    }
    CSteamID GameServer::CreateUnauthenticatedUserConnection()
    {
        DUMP_FUNC_NAME();
        return CSteamID();
    }
    void GameServer::SendUserDisconnect(CSteamID steamIDUser)
    {
        DUMP_FUNC_NAME();
    }
    bool GameServer::BUpdateUserData(CSteamID steamIDUser, const char* pchPlayerName, uint32 uScore)
    {
        DUMP_FUNC_NAME();
        return false;
    }
    HAuthTicket GameServer::GetAuthSessionTicket(void* pTicket, int cbMaxTicket, uint32* pcbTicket)
    {
        DUMP_FUNC_NAME();
        return HAuthTicket();
    }
    EBeginAuthSessionResult GameServer::BeginAuthSession(const void* pAuthTicket, int cbAuthTicket, CSteamID steamID)
    {
        DUMP_FUNC_NAME();
        return EBeginAuthSessionResult();
    }
    void GameServer::EndAuthSession(CSteamID steamID)
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::CancelAuthTicket(HAuthTicket hAuthTicket)
    {
        DUMP_FUNC_NAME();
    }
    EUserHasLicenseForAppResult GameServer::UserHasLicenseForApp(CSteamID steamID, AppId_t appID)
    {
        DUMP_FUNC_NAME();
        return EUserHasLicenseForAppResult();
    }
    bool GameServer::RequestUserGroupStatus(CSteamID steamIDUser, CSteamID steamIDGroup)
    {
        DUMP_FUNC_NAME();
        return false;
    }
    void GameServer::GetGameplayStats()
    {
        DUMP_FUNC_NAME();
    }
    SteamAPICall_t GameServer::GetServerReputation()
    {
		DUMP_FUNC_NAME();
        return SteamAPICall_t();
    }
    uint32 GameServer::GetPublicIP_old()
    {
        DUMP_FUNC_NAME();
        return uint32();
    }
    bool GameServer::HandleIncomingPacket(const void* pData, int cbData, uint32 srcIP, uint16 srcPort)
    {
        DUMP_FUNC_NAME();
        return false;
    }
    int GameServer::GetNextOutgoingPacket(void* pOut, int cbMaxOut, uint32* pNetAdr, uint16* pPort)
    {
        DUMP_FUNC_NAME();
        return 0;
    }
    void GameServer::EnableHeartbeats(bool bActive)
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::SetHeartbeatInterval(int iHeartbeatInterval)
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::ForceHeartbeat()
    {
        DUMP_FUNC_NAME();
    }
    SteamAPICall_t GameServer::AssociateWithClan(CSteamID steamIDClan)
    {
        DUMP_FUNC_NAME();
        return SteamAPICall_t();
    }
    SteamAPICall_t GameServer::ComputeNewPlayerCompatibility(CSteamID steamIDNewPlayer)
    {
        DUMP_FUNC_NAME();
        return SteamAPICall_t();
    }
}

STEAM_IGNORE_WARNINGS_END
