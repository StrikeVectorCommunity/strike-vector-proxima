#include "pch.h"
#include "..\Steam.hpp"

bool Steam::UserStats::RequestCurrentStats()
{
	DUMP_FUNC_NAME();

    UserStatsReceived_t data;
    data.m_nGameID = STRIKE_VECTOR_APPID;
    data.m_eResult = k_EResultOK;
    data.m_steamIDUser = Proxima::Client::GetSteamID();

	const auto id = Callbacks::RegisterCall();
	Callbacks::ReturnCall(&data, sizeof(data), data.k_iCallback, id);

	return true;
}

bool Steam::UserStats::GetStat(const char* pchName, int32* pData)
{
	DUMP_FUNC_NAME();
	float f{};
	bool result = Proxima::Stats::GetUser()->Get(pchName, f);

	if (result)
	{
		*pData = static_cast<int32>(f);
	}

	return result;
}

bool Steam::UserStats::SetStat(const char* pchName, int32 nData)
{
	DUMP_FUNC_NAME();
	Proxima::Stats::GetUser()->Set(pchName, static_cast<float>(nData));
	return true;
}

bool Steam::UserStats::UpdateAvgRateStat(const char* pchName, float flCountThisSession, double dSessionLength)
{
	DUMP_FUNC_NAME();
	return false;
}

bool Steam::UserStats::GetAchievement(const char* pchName, bool* pbAchieved)
{
	DUMP_FUNC_NAME();
	return false;
}

bool Steam::UserStats::SetAchievement(const char* pchName)
{
	DUMP_FUNC_NAME();
	return false;
}

bool Steam::UserStats::ClearAchievement(const char* pchName)
{
	DUMP_FUNC_NAME();
	return false;
}

bool Steam::UserStats::GetAchievementAndUnlockTime(const char* pchName, bool* pbAchieved, uint32* punUnlockTime)
{
	DUMP_FUNC_NAME();
	return false;
}

bool Steam::UserStats::StoreStats()
{
	Proxima::Stats::GetUser()->Write();
	return true;
}

int Steam::UserStats::GetAchievementIcon(const char* pchName)
{
	DUMP_FUNC_NAME();
	return 0;
}

const char* Steam::UserStats::GetAchievementDisplayAttribute(const char* pchName, const char* pchKey)
{
	DUMP_FUNC_NAME();
	return "aa";
}

bool Steam::UserStats::IndicateAchievementProgress(const char* pchName, uint32 nCurProgress, uint32 nMaxProgress)
{
	DUMP_FUNC_NAME();
	return false;
}

uint32 Steam::UserStats::GetNumAchievements()
{
	DUMP_FUNC_NAME();
	return uint32();
}

const char* Steam::UserStats::GetAchievementName(uint32 iAchievement)
{
	DUMP_FUNC_NAME();
	return "aa";
}

SteamAPICall_t Steam::UserStats::RequestUserStats(CSteamID steamIDUser)
{
	// Enable this to allow hot reload achievements status
	//if (steamIDUser == settings->get_local_steam_id()) {
	//    load_achievements();
	//}

	SteamAPICall_t call{};

	//DUMP_FUNC_NAME();

	return call;
}

bool Steam::UserStats::GetUserStat(CSteamID steamIDUser, const char* pchName, int32* pData)
{
	DUMP_FUNC_NAME();
	if (steamIDUser.m_unAll64Bits == Proxima::Client::GetSteamID().m_unAll64Bits)
	{
		float f{};
		bool result = Proxima::Stats::GetUser()->Get(pchName, f);

		if (result)
		{
			*pData = static_cast<int32>(f);
		}

		return result;
	}

	return false;
}

bool Steam::UserStats::GetUserAchievement(CSteamID steamIDUser, const char* pchName, bool* pbAchieved)
{
	DUMP_FUNC_NAME();
	return false;
}

bool Steam::UserStats::GetUserAchievementAndUnlockTime(CSteamID steamIDUser, const char* pchName, bool* pbAchieved, uint32* punUnlockTime)
{
	DUMP_FUNC_NAME();
	return false;
}

bool Steam::UserStats::ResetAllStats(bool bAchievementsToo)
{
	DUMP_FUNC_NAME();
	return false;
}

SteamAPICall_t Steam::UserStats::FindOrCreateLeaderboard(const char* pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType)
{
	DUMP_FUNC_NAME();
	return SteamAPICall_t();
}

SteamAPICall_t Steam::UserStats::FindLeaderboard(const char* pchLeaderboardName)
{
	DUMP_FUNC_NAME();

    LeaderboardFindResult_t data;
	data.m_hSteamLeaderboard = 0;
	data.m_bLeaderboardFound = 0;

	const auto id = Callbacks::RegisterCall();
	Callbacks::ReturnCall(&data, sizeof(data), data.k_iCallback, id);

	return id;
}

const char* Steam::UserStats::GetLeaderboardName(SteamLeaderboard_t hSteamLeaderboard)
{
	DUMP_FUNC_NAME();
	return nullptr;
}

int Steam::UserStats::GetLeaderboardEntryCount(SteamLeaderboard_t hSteamLeaderboard)
{
	DUMP_FUNC_NAME();
	return 0;
}

Steam::ELeaderboardSortMethod Steam::UserStats::GetLeaderboardSortMethod(SteamLeaderboard_t hSteamLeaderboard)
{
	DUMP_FUNC_NAME();
	return ELeaderboardSortMethod();
}

Steam::ELeaderboardDisplayType Steam::UserStats::GetLeaderboardDisplayType(SteamLeaderboard_t hSteamLeaderboard)
{
	DUMP_FUNC_NAME();
	return ELeaderboardDisplayType();
}

SteamAPICall_t Steam::UserStats::DownloadLeaderboardEntries(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd)
{
	DUMP_FUNC_NAME();
	return SteamAPICall_t();
}

SteamAPICall_t Steam::UserStats::DownloadLeaderboardEntriesForUsers(SteamLeaderboard_t hSteamLeaderboard, CSteamID* prgUsers, int cUsers)
{
	DUMP_FUNC_NAME();
	return SteamAPICall_t();
}

bool Steam::UserStats::GetDownloadedLeaderboardEntry(SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, LeaderboardEntry_t* pLeaderboardEntry, int32* pDetails, int cDetailsMax)
{
	DUMP_FUNC_NAME();
	return false;
}

SteamAPICall_t Steam::UserStats::UploadLeaderboardScore(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, const int32* pScoreDetails, int cScoreDetailsCount)
{
	DUMP_FUNC_NAME();
	return SteamAPICall_t();
}

SteamAPICall_t Steam::UserStats::AttachLeaderboardUGC(SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC)
{
	DUMP_FUNC_NAME();
	return SteamAPICall_t();
}

SteamAPICall_t Steam::UserStats::GetNumberOfCurrentPlayers()
{
	DUMP_FUNC_NAME();
	return SteamAPICall_t();
}

SteamAPICall_t Steam::UserStats::RequestGlobalAchievementPercentages()
{
	DUMP_FUNC_NAME();
	return SteamAPICall_t();
}

int Steam::UserStats::GetMostAchievedAchievementInfo(char* pchName, uint32 unNameBufLen, float* pflPercent, bool* pbAchieved)
{
	DUMP_FUNC_NAME();
	return 0;
}

int Steam::UserStats::GetNextMostAchievedAchievementInfo(int iIteratorPrevious, char* pchName, uint32 unNameBufLen, float* pflPercent, bool* pbAchieved)
{
	DUMP_FUNC_NAME();
	return 0;
}

bool Steam::UserStats::GetAchievementAchievedPercent(const char* pchName, float* pflPercent)
{
	DUMP_FUNC_NAME();
	return false;
}

SteamAPICall_t Steam::UserStats::RequestGlobalStats(int nHistoryDays)
{
	DUMP_FUNC_NAME();
	return SteamAPICall_t();
}

bool Steam::UserStats::GetGlobalStat(const char* pchStatName, int64* pData)
{
	DUMP_FUNC_NAME();
	return false;
}

bool Steam::UserStats::GetGlobalStat(const char* pchStatName, double* pData)
{
	DUMP_FUNC_NAME();
	return false;
}

int32 Steam::UserStats::GetGlobalStatHistory(const char* pchStatName, int64* pData, uint32 cubData)
{
	DUMP_FUNC_NAME();
	return int32();
}

int32 Steam::UserStats::GetGlobalStatHistory(const char* pchStatName, double* pData, uint32 cubData)
{
	DUMP_FUNC_NAME();
	return int32();
}

bool Steam::UserStats::GetUserStat(CSteamID steamIDUser, const char* pchName, float* pData)
{
	DUMP_FUNC_NAME();
	if (steamIDUser.m_unAll64Bits == Proxima::Client::GetSteamID().m_unAll64Bits)
	{
		return Proxima::Stats::GetUser()->Get(pchName, *pData);
	}

	return false;
}

bool Steam::UserStats::SetStat(const char* pchName, float fData)
{
	DUMP_FUNC_NAME();
	Proxima::Stats::GetUser()->Set(pchName, fData);
	return true;
}

bool Steam::UserStats::GetStat(const char* pchName, float* pData)
{
	DUMP_FUNC_NAME();
	return Proxima::Stats::GetUser()->Get(pchName, *pData);
}
