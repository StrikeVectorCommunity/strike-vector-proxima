#include "pch.h"

SteamAPICall_t Steam::GameServerStats::RequestUserStats(CSteamID steamIDUser)
{
    GSStatsReceived_t stats;
    stats.m_eResult = EResult::k_EResultOK;
    stats.m_steamIDUser = steamIDUser;

    SteamAPICall_t call = Callbacks::RegisterCall();
    Callbacks::ReturnCall(&stats, sizeof stats, GSStatsReceived_t::k_iCallback, call);

    return call;
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
    GSStatsStored_t stats;
    stats.m_eResult = EResult::k_EResultOK;
    stats.m_steamIDUser = steamIDUser;

    SteamAPICall_t call = Callbacks::RegisterCall();
    Callbacks::ReturnCall(&stats, sizeof stats, GSStatsStored_t::k_iCallback, call);

    Proxima::Stats::GetServer()->Write();

    return call;
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
