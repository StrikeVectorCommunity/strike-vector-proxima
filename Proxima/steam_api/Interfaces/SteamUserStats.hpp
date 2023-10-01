namespace Steam
{

	typedef uint64 SteamLeaderboard_t;
	typedef uint64 SteamLeaderboardEntries_t;
	typedef uint64 UGCHandle_t;

	enum ELeaderboardDataRequest
	{
		k_ELeaderboardDataRequestGlobal = 0,
		k_ELeaderboardDataRequestGlobalAroundUser = 1,
		k_ELeaderboardDataRequestFriends = 2,
		k_ELeaderboardDataRequestUsers = 3
	};

	// the sort order of a leaderboard
	enum ELeaderboardSortMethod
	{
		k_ELeaderboardSortMethodNone = 0,
		k_ELeaderboardSortMethodAscending = 1,	// top-score is lowest number
		k_ELeaderboardSortMethodDescending = 2,	// top-score is highest number
	};

	// the display type (used by the Steam Community web site) for a leaderboard
	enum ELeaderboardDisplayType
	{
		k_ELeaderboardDisplayTypeNone = 0,
		k_ELeaderboardDisplayTypeNumeric = 1,			// simple numerical score
		k_ELeaderboardDisplayTypeTimeSeconds = 2,		// the score represents a time, in seconds
		k_ELeaderboardDisplayTypeTimeMilliSeconds = 3,	// the score represents a time, in milliseconds
	};

	enum ELeaderboardUploadScoreMethod
	{
		k_ELeaderboardUploadScoreMethodNone = 0,
		k_ELeaderboardUploadScoreMethodKeepBest = 1,	// Leaderboard will keep user's best score
		k_ELeaderboardUploadScoreMethodForceUpdate = 2,	// Leaderboard will always replace score with specified
	};

	struct LeaderboardEntry_t
	{
		CSteamID m_steamIDUser; // user with the entry - use SteamFriends()->GetFriendPersonaName() & SteamFriends()->GetFriendAvatar() to get more info
		int32 m_nGlobalRank;	// [1..N], where N is the number of users with an entry in the leaderboard
		int32 m_nScore;			// score as set in the leaderboard
		int32 m_cDetails;		// number of int32 details available for this entry
		UGCHandle_t m_hUGC;		// handle for UGC attached to the entry
	};

	struct LeaderboardFindResult_t
{
	enum { k_iCallback = 1100 + 4 };
	SteamLeaderboard_t m_hSteamLeaderboard;	// handle to the leaderboard serarched for, 0 if no leaderboard found
	uint8 m_bLeaderboardFound;				// 0 if no leaderboard found
};

	class UserStats
	{
	public:
		// Ask the server to send down this user's data and achievements for this game
		STEAM_CALL_BACK(UserStatsReceived_t)
			virtual bool RequestCurrentStats();

		// Data accessors
		STEAM_FLAT_NAME(GetStatInt32)
			virtual bool GetStat(const char* pchName, int32* pData);

		STEAM_FLAT_NAME(GetStatFloat)
			virtual bool GetStat(const char* pchName, float* pData);

		// Set / update data
		STEAM_FLAT_NAME(SetStatInt32)
			virtual bool SetStat(const char* pchName, int32 nData);

		STEAM_FLAT_NAME(SetStatFloat)
			virtual bool SetStat(const char* pchName, float fData);

		virtual bool UpdateAvgRateStat(const char* pchName, float flCountThisSession, double dSessionLength);

		// Achievement flag accessors
		virtual bool GetAchievement(const char* pchName, bool* pbAchieved);
		virtual bool SetAchievement(const char* pchName);
		virtual bool ClearAchievement(const char* pchName);

		// Get the achievement status, and the time it was unlocked if unlocked.
		// If the return value is true, but the unlock time is zero, that means it was unlocked before Steam 
		// began tracking achievement unlock times (December 2009). Time is seconds since January 1, 1970.
		virtual bool GetAchievementAndUnlockTime(const char* pchName, bool* pbAchieved, uint32* punUnlockTime);

		// Store the current data on the server, will get a callback when set
		// And one callback for every new achievement
		//
		// If the callback has a result of k_EResultInvalidParam, one or more stats 
		// uploaded has been rejected, either because they broke constraints
		// or were out of date. In this case the server sends back updated values.
		// The stats should be re-iterated to keep in sync.
		virtual bool StoreStats();

		// Achievement / GroupAchievement metadata

		// Gets the icon of the achievement, which is a handle to be used in ISteamUtils::GetImageRGBA(), or 0 if none set. 
		// A return value of 0 may indicate we are still fetching data, and you can wait for the UserAchievementIconFetched_t callback
		// which will notify you when the bits are ready. If the callback still returns zero, then there is no image set for the
		// specified achievement.
		virtual int GetAchievementIcon(const char* pchName);

		// Get general attributes for an achievement. Accepts the following keys:
		// - "name" and "desc" for retrieving the localized achievement name and description (returned in UTF8)
		// - "hidden" for retrieving if an achievement is hidden (returns "0" when not hidden, "1" when hidden)
		virtual const char* GetAchievementDisplayAttribute(const char* pchName, const char* pchKey);

		// Achievement progress - triggers an AchievementProgress callback, that is all.
		// Calling this w/ N out of N progress will NOT set the achievement, the game must still do that.
		virtual bool IndicateAchievementProgress(const char* pchName, uint32 nCurProgress, uint32 nMaxProgress);

		// Used for iterating achievements. In general games should not need these functions because they should have a
		// list of existing achievements compiled into them
		virtual uint32 GetNumAchievements();
		// Get achievement name iAchievement in [0,GetNumAchievements)
		virtual const char* GetAchievementName(uint32 iAchievement);

		// Friends stats & achievements

		// downloads stats for the user
		// returns a UserStatsReceived_t received when completed
		// if the other user has no stats, UserStatsReceived_t.m_eResult will be set to k_EResultFail
		// these stats won't be auto-updated; you'll need to call RequestUserStats() again to refresh any data
		STEAM_CALL_RESULT(UserStatsReceived_t)
			virtual SteamAPICall_t RequestUserStats(CSteamID steamIDUser);

		// requests stat information for a user, usable after a successful call to RequestUserStats()
		STEAM_FLAT_NAME(GetUserStatInt32)
			virtual bool GetUserStat(CSteamID steamIDUser, const char* pchName, int32* pData);

		STEAM_FLAT_NAME(GetUserStatFloat)
			virtual bool GetUserStat(CSteamID steamIDUser, const char* pchName, float* pData);

		virtual bool GetUserAchievement(CSteamID steamIDUser, const char* pchName, bool* pbAchieved);
		// See notes for GetAchievementAndUnlockTime above
		virtual bool GetUserAchievementAndUnlockTime(CSteamID steamIDUser, const char* pchName, bool* pbAchieved, uint32* punUnlockTime);

		// Reset stats 
		virtual bool ResetAllStats(bool bAchievementsToo);

		// Leaderboard functions

		// asks the Steam back-end for a leaderboard by name, and will create it if it's not yet
		// This call is asynchronous, with the result returned in LeaderboardFindResult_t
		STEAM_CALL_RESULT(LeaderboardFindResult_t)
			virtual SteamAPICall_t FindOrCreateLeaderboard(const char* pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType);

		// as above, but won't create the leaderboard if it's not found
		// This call is asynchronous, with the result returned in LeaderboardFindResult_t
		STEAM_CALL_RESULT(LeaderboardFindResult_t)
			virtual SteamAPICall_t FindLeaderboard(const char* pchLeaderboardName);

		// returns the name of a leaderboard
		virtual const char* GetLeaderboardName(SteamLeaderboard_t hSteamLeaderboard);

		// returns the total number of entries in a leaderboard, as of the last request
		virtual int GetLeaderboardEntryCount(SteamLeaderboard_t hSteamLeaderboard);

		// returns the sort method of the leaderboard
		virtual ELeaderboardSortMethod GetLeaderboardSortMethod(SteamLeaderboard_t hSteamLeaderboard);

		// returns the display type of the leaderboard
		virtual ELeaderboardDisplayType GetLeaderboardDisplayType(SteamLeaderboard_t hSteamLeaderboard);

		// Asks the Steam back-end for a set of rows in the leaderboard.
		// This call is asynchronous, with the result returned in LeaderboardScoresDownloaded_t
		// LeaderboardScoresDownloaded_t will contain a handle to pull the results from GetDownloadedLeaderboardEntries() (below)
		// You can ask for more entries than exist, and it will return as many as do exist.
		// k_ELeaderboardDataRequestGlobal requests rows in the leaderboard from the full table, with nRangeStart & nRangeEnd in the range [1, TotalEntries]
		// k_ELeaderboardDataRequestGlobalAroundUser requests rows around the current user, nRangeStart being negate
		//   e.g. DownloadLeaderboardEntries( hLeaderboard, k_ELeaderboardDataRequestGlobalAroundUser, -3, 3 ) will return 7 rows, 3 before the user, 3 after
		// k_ELeaderboardDataRequestFriends requests all the rows for friends of the current user 
		STEAM_CALL_RESULT(LeaderboardScoresDownloaded_t)
			virtual SteamAPICall_t DownloadLeaderboardEntries(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd);
		// as above, but downloads leaderboard entries for an arbitrary set of users - ELeaderboardDataRequest is k_ELeaderboardDataRequestUsers
		// if a user doesn't have a leaderboard entry, they won't be included in the result
		// a max of 100 users can be downloaded at a time, with only one outstanding call at a time
		STEAM_METHOD_DESC(Downloads leaderboard entries for an arbitrary set of users - ELeaderboardDataRequest is k_ELeaderboardDataRequestUsers)
			STEAM_CALL_RESULT(LeaderboardScoresDownloaded_t)
			virtual SteamAPICall_t DownloadLeaderboardEntriesForUsers(SteamLeaderboard_t hSteamLeaderboard,
				STEAM_ARRAY_COUNT_D(cUsers, Array of users to retrieve) CSteamID* prgUsers, int cUsers);

		// Returns data about a single leaderboard entry
		// use a for loop from 0 to LeaderboardScoresDownloaded_t::m_cEntryCount to get all the downloaded entries
		// e.g.
		//		void OnLeaderboardScoresDownloaded( LeaderboardScoresDownloaded_t *pLeaderboardScoresDownloaded )
		//		{
		//			for ( int index; index < pLeaderboardScoresDownloaded->m_cEntryCount; index++ )
		//			{
		//				LeaderboardEntry_t leaderboardEntry;
		//				int32 details[3];		// we know this is how many we've stored previously
		//				GetDownloadedLeaderboardEntry( pLeaderboardScoresDownloaded->m_hSteamLeaderboardEntries, index, &leaderboardEntry, details, 3 );
		//				assert( leaderboardEntry.m_cDetails == 3 );
		//				...
		//			}
		// once you've accessed all the entries, the data will be free'd, and the SteamLeaderboardEntries_t handle will become invalid
		virtual bool GetDownloadedLeaderboardEntry(SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, LeaderboardEntry_t* pLeaderboardEntry, int32* pDetails, int cDetailsMax);

		// Uploads a user score to the Steam back-end.
		// This call is asynchronous, with the result returned in LeaderboardScoreUploaded_t
		// Details are extra game-defined information regarding how the user got that score
		// pScoreDetails points to an array of int32's, cScoreDetailsCount is the number of int32's in the list
		STEAM_CALL_RESULT(LeaderboardScoreUploaded_t)
			virtual SteamAPICall_t UploadLeaderboardScore(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, const int32* pScoreDetails, int cScoreDetailsCount);

		// Attaches a piece of user generated content the user's entry on a leaderboard.
		// hContent is a handle to a piece of user generated content that was shared using ISteamUserRemoteStorage::FileShare().
		// This call is asynchronous, with the result returned in LeaderboardUGCSet_t.
		STEAM_CALL_RESULT(LeaderboardUGCSet_t)
			virtual SteamAPICall_t AttachLeaderboardUGC(SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC);

		// Retrieves the number of players currently playing your game (online + offline)
		// This call is asynchronous, with the result returned in NumberOfCurrentPlayers_t
		STEAM_CALL_RESULT(NumberOfCurrentPlayers_t)
			virtual SteamAPICall_t GetNumberOfCurrentPlayers();

		// Requests that Steam fetch data on the percentage of players who have received each achievement
		// for the game globally.
		// This call is asynchronous, with the result returned in GlobalAchievementPercentagesReady_t.
		STEAM_CALL_RESULT(GlobalAchievementPercentagesReady_t)
			virtual SteamAPICall_t RequestGlobalAchievementPercentages();

		// Get the info on the most achieved achievement for the game, returns an iterator index you can use to fetch
		// the next most achieved afterwards.  Will return -1 if there is no data on achievement 
		// percentages (ie, you haven't called RequestGlobalAchievementPercentages and waited on the callback).
		virtual int GetMostAchievedAchievementInfo(char* pchName, uint32 unNameBufLen, float* pflPercent, bool* pbAchieved);

		// Get the info on the next most achieved achievement for the game. Call this after GetMostAchievedAchievementInfo or another
		// GetNextMostAchievedAchievementInfo call passing the iterator from the previous call. Returns -1 after the last
		// achievement has been iterated.
		virtual int GetNextMostAchievedAchievementInfo(int iIteratorPrevious, char* pchName, uint32 unNameBufLen, float* pflPercent, bool* pbAchieved);

		// Returns the percentage of users who have achieved the specified achievement.
		virtual bool GetAchievementAchievedPercent(const char* pchName, float* pflPercent);

		// Requests global stats data, which is available for stats marked as "aggregated".
		// This call is asynchronous, with the results returned in GlobalStatsReceived_t.
		// nHistoryDays specifies how many days of day-by-day history to retrieve in addition
		// to the overall totals. The limit is 60.
		STEAM_CALL_RESULT(GlobalStatsReceived_t)
			virtual SteamAPICall_t RequestGlobalStats(int nHistoryDays);

		// Gets the lifetime totals for an aggregated stat
		STEAM_FLAT_NAME(GetGlobalStatInt64)
			virtual bool GetGlobalStat(const char* pchStatName, int64* pData);

		STEAM_FLAT_NAME(GetGlobalStatDouble)
			virtual bool GetGlobalStat(const char* pchStatName, double* pData);

		// Gets history for an aggregated stat. pData will be filled with daily values, starting with today.
		// So when called, pData[0] will be today, pData[1] will be yesterday, and pData[2] will be two days ago, 
		// etc. cubData is the size in bytes of the pubData buffer. Returns the number of 
		// elements actually set.

		STEAM_FLAT_NAME(GetGlobalStatHistoryInt64)
			virtual int32 GetGlobalStatHistory(const char* pchStatName, STEAM_ARRAY_COUNT(cubData) int64* pData, uint32 cubData);

		STEAM_FLAT_NAME(GetGlobalStatHistoryDouble)
			virtual int32 GetGlobalStatHistory(const char* pchStatName, STEAM_ARRAY_COUNT(cubData) double* pData, uint32 cubData);
	};
}