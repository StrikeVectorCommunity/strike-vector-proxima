#include "pch.h"

namespace Proxima
{
	std::unordered_map<Steam::SteamLeaderboard_t, Leaderboards::Leaderboard> Leaderboards::leaderboards{};
	 Steam::SteamLeaderboard_t Leaderboards::nextLeaderboardID = 1;

	Steam::SteamLeaderboard_t Proxima::Leaderboards::FindOrCreateLeaderboardID(const std::string& name)
	{
		for (const auto& kv : leaderboards)
		{
			if (kv.second.name == name)
			{
				return kv.first;
			}
		}

		// Create it
		Leaderboard newLeaderboard{};
		newLeaderboard.name = name;

		const auto id = nextLeaderboardID;
		nextLeaderboardID++;

		leaderboards[id] = newLeaderboard;

		Logger::Print("Created leaderboard {} (ID {})", name, id);

		return id;
	}

	const Leaderboards::Leaderboard* Leaderboards::GetLeaderboard(const Steam::SteamLeaderboard_t& id)
	{
		if (leaderboards.contains(id))
		{
			return &leaderboards[id];
		}

		return nullptr;
	}
}