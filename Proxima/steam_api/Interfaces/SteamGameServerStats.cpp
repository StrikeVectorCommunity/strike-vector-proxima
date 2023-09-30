#include "pch.h"

SteamAPICall_t Steam::GameServerStats::RequestUserStats(CSteamID steamIDUser)
{
    return SteamAPICall_t();
}

bool Steam::GameServerStats::GetUserStat(CSteamID steamIDUser, const char* pchName, int32* pData)
{
    return false;
}

bool Steam::GameServerStats::GetUserAchievement(CSteamID steamIDUser, const char* pchName, bool* pbAchieved)
{
    return false;
}

bool Steam::GameServerStats::SetUserStat(CSteamID steamIDUser, const char* pchName, int32 nData)
{
    return true;
}

bool Steam::GameServerStats::UpdateUserAvgRateStat(CSteamID steamIDUser, const char* pchName, float flCountThisSession, double dSessionLength)
{
    return false;
}

bool Steam::GameServerStats::SetUserAchievement(CSteamID steamIDUser, const char* pchName)
{
    return false;
}

bool Steam::GameServerStats::ClearUserAchievement(CSteamID steamIDUser, const char* pchName)
{
    return false;
}

SteamAPICall_t Steam::GameServerStats::StoreUserStats(CSteamID steamIDUser)
{
    return SteamAPICall_t();
}

bool Steam::GameServerStats::SetUserStat(CSteamID steamIDUser, const char* pchName, float fData)
{
    return false;
}

bool Steam::GameServerStats::GetUserStat(CSteamID steamIDUser, const char* pchName, float* pData)
{
    return false;
}
