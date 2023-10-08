#include "pch.h"

SteamAPICall_t Steam::GameServerStats::RequestUserStats(CSteamID steamIDUser)
{
    GSStatsReceived_t data;
    data.m_eResult = EResult::k_EResultOK;
    data.m_steamIDUser = steamIDUser;
    
    return Steam::callbacks->GetResultsServer()->AddCallResult(data.k_iCallback, &data, sizeof(data), 0.1);;
}

bool Steam::GameServerStats::GetUserStat(CSteamID steamIDUser, const char* pchName, int32* pData)
{
    if (steamIDUser.m_unAll64Bits == Proxima::Client::GetSteamID().m_unAll64Bits)
    {
        float f{};
        bool result = Proxima::Stats::GetServer()->Get(pchName, f);

        if (result)
        {
            *pData = static_cast<int32>(f);
        }

        return result;
    }

    return false;
}

bool Steam::GameServerStats::GetUserAchievement(CSteamID steamIDUser, const char* pchName, bool* pbAchieved)
{
    DUMP_FUNC_NAME();
    return false;
}

bool Steam::GameServerStats::SetUserStat(CSteamID steamIDUser, const char* pchName, int32 nData)
{
    if (steamIDUser.m_unAll64Bits == Proxima::Client::GetSteamID().m_unAll64Bits)
    {
        Proxima::Stats::GetServer()->Set(pchName, static_cast<float>(nData));
        return true;
    }

    return false;
}

bool Steam::GameServerStats::UpdateUserAvgRateStat(CSteamID steamIDUser, const char* pchName, float flCountThisSession, double dSessionLength)
{
    DUMP_FUNC_NAME();
    return false;
}

bool Steam::GameServerStats::SetUserAchievement(CSteamID steamIDUser, const char* pchName)
{
    DUMP_FUNC_NAME();
    return false;
}

bool Steam::GameServerStats::ClearUserAchievement(CSteamID steamIDUser, const char* pchName)
{
    DUMP_FUNC_NAME();
    return false;
}

SteamAPICall_t Steam::GameServerStats::StoreUserStats(CSteamID steamIDUser)
{
    GSStatsStored_t data;
    data.m_eResult = EResult::k_EResultOK;
    data.m_steamIDUser = steamIDUser;

    Proxima::Stats::GetServer()->Write();
    
    return Steam::callbacks->GetResultsServer()->AddCallResult(data.k_iCallback, &data, sizeof(data));;
}

bool Steam::GameServerStats::SetUserStat(CSteamID steamIDUser, const char* pchName, float fData)
{
    if (steamIDUser.m_unAll64Bits == Proxima::Client::GetSteamID().m_unAll64Bits)
    {
        Proxima::Stats::GetServer()->Set(pchName, fData);
        return true;
    }

    return false;
}

bool Steam::GameServerStats::GetUserStat(CSteamID steamIDUser, const char* pchName, float* pData)
{
    if (steamIDUser.m_unAll64Bits == Proxima::Client::GetSteamID().m_unAll64Bits)
    {
        return Proxima::Stats::GetServer()->Get(pchName, *pData);
    }

    return false;
}
