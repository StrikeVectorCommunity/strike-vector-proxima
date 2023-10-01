#include "pch.h"

namespace Proxima
{
	Stats::Container Stats::server(StatsCategory::GameServer);
	Stats::Container Stats::user(StatsCategory::User);

	void Stats::Container::Set(const std::string& name, float value)
	{
		stats[name] = value;
	}

	bool Stats::Container::Get(const std::string& name, OUT float& out) const
	{
		if (stats.contains(name))
		{
			out = stats.at(name);
			return true;
		}

		return false;
	}
}
