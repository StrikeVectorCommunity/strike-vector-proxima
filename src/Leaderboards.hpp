namespace Proxima
{
	class Leaderboards
	{
	public:

		struct Score
		{
			CSteamID steam_id;
			int32_t score = 0;
			std::vector<int32_t> score_details{};
		};

		struct Leaderboard
		{
			std::string name;
			std::vector<Score> scores{};
			Steam::ELeaderboardDisplayType displayType = Steam::ELeaderboardDisplayType::k_ELeaderboardDisplayTypeNumeric;
			Steam::ELeaderboardSortMethod sortMethod = Steam::ELeaderboardSortMethod::k_ELeaderboardSortMethodDescending;
		};

		static Steam::SteamLeaderboard_t FindOrCreateLeaderboardID(const std::string& name);
		static const Leaderboards::Leaderboard* GetLeaderboard(const Steam::SteamLeaderboard_t& id);

	private:
		static std::unordered_map<Steam::SteamLeaderboard_t, Leaderboard> leaderboards;
		static Steam::SteamLeaderboard_t nextLeaderboardID;
	};
}