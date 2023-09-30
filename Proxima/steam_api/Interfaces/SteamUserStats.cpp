#include "pch.h"

bool Steam::UserStats::RequestCurrentStats()
{
    return false;
}

bool Steam::UserStats::GetStat(const char* pchName, int32* pData)
{
    return false;
}

bool Steam::UserStats::SetStat(const char* pchName, int32 nData)
{
    return false;
}

bool Steam::UserStats::UpdateAvgRateStat(const char* pchName, float flCountThisSession, double dSessionLength)
{
    return false;
}

bool Steam::UserStats::GetAchievement(const char* pchName, bool* pbAchieved)
{
    return false;
}

bool Steam::UserStats::SetAchievement(const char* pchName)
{
    return false;
}

bool Steam::UserStats::ClearAchievement(const char* pchName)
{
    return false;
}

bool Steam::UserStats::GetAchievementAndUnlockTime(const char* pchName, bool* pbAchieved, uint32* punUnlockTime)
{
    return false;
}

bool Steam::UserStats::StoreStats()
{
    return false;
}

int Steam::UserStats::GetAchievementIcon(const char* pchName)
{
    return 0;
}

const char* Steam::UserStats::GetAchievementDisplayAttribute(const char* pchName, const char* pchKey)
{
    return "aa";
}

bool Steam::UserStats::IndicateAchievementProgress(const char* pchName, uint32 nCurProgress, uint32 nMaxProgress)
{
    return false;
}

uint32 Steam::UserStats::GetNumAchievements()
{
    return uint32();
}

const char* Steam::UserStats::GetAchievementName(uint32 iAchievement)
{
    return "aa";
}

SteamAPICall_t Steam::UserStats::RequestUserStats(CSteamID steamIDUser)
{
    return SteamAPICall_t();
}

bool Steam::UserStats::GetUserStat(CSteamID steamIDUser, const char* pchName, int32* pData)
{
    return false;
}

bool Steam::UserStats::GetUserAchievement(CSteamID steamIDUser, const char* pchName, bool* pbAchieved)
{
    return false;
}

bool Steam::UserStats::GetUserAchievementAndUnlockTime(CSteamID steamIDUser, const char* pchName, bool* pbAchieved, uint32* punUnlockTime)
{
    return false;
}

bool Steam::UserStats::ResetAllStats(bool bAchievementsToo)
{
    return false;
}

SteamAPICall_t Steam::UserStats::FindOrCreateLeaderboard(const char* pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType)
{
    return SteamAPICall_t();
}

SteamAPICall_t Steam::UserStats::FindLeaderboard(const char* pchLeaderboardName)
{
    return SteamAPICall_t();
}

const char* Steam::UserStats::GetLeaderboardName(SteamLeaderboard_t hSteamLeaderboard)
{
    return nullptr;
}

int Steam::UserStats::GetLeaderboardEntryCount(SteamLeaderboard_t hSteamLeaderboard)
{
    return 0;
}

Steam::ELeaderboardSortMethod Steam::UserStats::GetLeaderboardSortMethod(SteamLeaderboard_t hSteamLeaderboard)
{
    return ELeaderboardSortMethod();
}

Steam::ELeaderboardDisplayType Steam::UserStats::GetLeaderboardDisplayType(SteamLeaderboard_t hSteamLeaderboard)
{
    return ELeaderboardDisplayType();
}

SteamAPICall_t Steam::UserStats::DownloadLeaderboardEntries(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd)
{
    return SteamAPICall_t();
}

SteamAPICall_t Steam::UserStats::DownloadLeaderboardEntriesForUsers(SteamLeaderboard_t hSteamLeaderboard, CSteamID* prgUsers, int cUsers)
{
    return SteamAPICall_t();
}

bool Steam::UserStats::GetDownloadedLeaderboardEntry(SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, LeaderboardEntry_t* pLeaderboardEntry, int32* pDetails, int cDetailsMax)
{
    return false;
}

SteamAPICall_t Steam::UserStats::UploadLeaderboardScore(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, const int32* pScoreDetails, int cScoreDetailsCount)
{
    return SteamAPICall_t();
}

SteamAPICall_t Steam::UserStats::AttachLeaderboardUGC(SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC)
{
    return SteamAPICall_t();
}

SteamAPICall_t Steam::UserStats::GetNumberOfCurrentPlayers()
{
    return SteamAPICall_t();
}

SteamAPICall_t Steam::UserStats::RequestGlobalAchievementPercentages()
{
    return SteamAPICall_t();
}

int Steam::UserStats::GetMostAchievedAchievementInfo(char* pchName, uint32 unNameBufLen, float* pflPercent, bool* pbAchieved)
{
    return 0;
}

int Steam::UserStats::GetNextMostAchievedAchievementInfo(int iIteratorPrevious, char* pchName, uint32 unNameBufLen, float* pflPercent, bool* pbAchieved)
{
    return 0;
}

bool Steam::UserStats::GetAchievementAchievedPercent(const char* pchName, float* pflPercent)
{
    return false;
}

SteamAPICall_t Steam::UserStats::RequestGlobalStats(int nHistoryDays)
{
    return SteamAPICall_t();
}

bool Steam::UserStats::GetGlobalStat(const char* pchStatName, int64* pData)
{
    return false;
}

bool Steam::UserStats::GetGlobalStat(const char* pchStatName, double* pData)
{
    return false;
}

int32 Steam::UserStats::GetGlobalStatHistory(const char* pchStatName, int64* pData, uint32 cubData)
{
    return int32();
}

int32 Steam::UserStats::GetGlobalStatHistory(const char* pchStatName, double* pData, uint32 cubData)
{
    return int32();
}

bool Steam::UserStats::GetUserStat(CSteamID steamIDUser, const char* pchName, float* pData)
{
    return false;
}

bool Steam::UserStats::SetStat(const char* pchName, float fData)
{
    return false;
}

bool Steam::UserStats::GetStat(const char* pchName, float* pData)
{
    return false;
}
