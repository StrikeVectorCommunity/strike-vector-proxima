#include "pch.h"

STEAM_IGNORE_WARNINGS_START

namespace Steam
{
    bool GameServer::InitGameServer(uint32 unIP, uint16 usGamePort, uint16 usQueryPort, uint32 unFlags, AppId_t nGameAppId, const char* pchVersionString)
    {
        Logger::Print("Initialized game server with\nIP:{}\nPORT:{}\nQPORT:{}\nunFlags:{}\ngameAppID:{}\nversionString:{}", unIP, usGamePort, usQueryPort, unFlags, nGameAppId, pchVersionString);

        return true;
    }
    void GameServer::SetProduct(const char* pszProduct)
    {
        Logger::Print("Set product: {}", pszProduct);
    }
    void GameServer::SetGameDescription(const char* pszGameDescription)
    {
        Logger::Print("Set game description: {}", pszGameDescription);
    }
    void GameServer::SetModDir(const char* pszModDir)
    {
        Logger::Print("Set mod dir: {}", pszModDir);
    }
    void GameServer::SetDedicatedServer(bool bDedicated)
    {
        Logger::Print("Set dedicated: {}", bDedicated);
    }
    void GameServer::LogOn(const char* pszAccountName, const char* pszPassword)
    {
        Logger::Print("Logging on:\nlogin:{}\npassword:{}", pszAccountName, pszPassword);
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
		return Proxima::Client::GetSteamID();
    }
    bool GameServer::WasRestartRequested()
    {
        DUMP_FUNC_NAME();
        return false;
    }
    void GameServer::SetMaxPlayerCount(int cPlayersMax)
    {
        Logger::Print("Set max player count: {}", cPlayersMax);
    }
    void GameServer::SetBotPlayerCount(int cBotplayers)
    {
        Logger::Print("Set bot player count: {}", cBotplayers);
    }
    void GameServer::SetServerName(const char* pszServerName)
    {
        Logger::Print("Set server name: {}", pszServerName);
    }
    void GameServer::SetMapName(const char* pszMapName)
    {
        Logger::Print("Set map name: {}", pszMapName);
    }
    void GameServer::SetPasswordProtected(bool bPasswordProtected)
    {
        Logger::Print("Set password protected: {}", bPasswordProtected);
    }
    void GameServer::SetSpectatorPort(uint16 unSpectatorPort)
    {
        Logger::Print("Set spectator port: {}", unSpectatorPort);
    }
    void GameServer::SetSpectatorServerName(const char* pszSpectatorServerName)
    {
        Logger::Print("Set spectator server name: {}", pszSpectatorServerName);
    }
    void GameServer::ClearAllKeyValues()
    {
        DUMP_FUNC_NAME();
    }
    void GameServer::SetKeyValue(const char* pKey, const char* pValue)
    {
        Logger::Print("Set kv {}={}", pKey, pValue);
    }
    void GameServer::SetGameTags(const char* pchGameTags)
    {
        Logger::Print("Set game tags: {}", pchGameTags);
    }
    void GameServer::SetGameData(const char* pchGameData)
    {
        Logger::Print("Set game data: {}", pchGameData);
    }
    void GameServer::SetRegion(const char* pszRegion)
    {
        Logger::Print("Set region: {}", pszRegion);
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
		return Proxima::Auth::GenerateTicket(pTicket, cbMaxTicket, pcbTicket);
    }
    EBeginAuthSessionResult GameServer::BeginAuthSession(const void* pAuthTicket, int cbAuthTicket, CSteamID steamID)
    {
        DUMP_FUNC_NAME();
		return Proxima::Auth::BeginAuth(pAuthTicket, cbAuthTicket, steamID);
    }
    void GameServer::EndAuthSession(CSteamID steamID)
    {
        DUMP_FUNC_NAME();
		Proxima::Auth::EndAuth(steamID);
    }
    void GameServer::CancelAuthTicket(HAuthTicket hAuthTicket)
    {
        DUMP_FUNC_NAME();
		Proxima::Auth::CancelTicket(hAuthTicket);
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
        Logger::Print("Set heartbeat interval: {}", iHeartbeatInterval);
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
