#pragma once
namespace Proxima
{
	enum StatsCategory : uint8_t { User, GameServer };

	class Stats
	{
	public:

		struct Container
		{
		public:
			Container(StatsCategory c)
			{
				channel = c;
				stats = std::map<std::string, float> ();
			};

			void Write()
			{
				FileSystem::WriteStats(channel, stats);
			}

			void Read()
			{
				FileSystem::ReadStats(channel, stats);
			}

			void Set(const std::string& name, float value);
			bool Get(const std::string& name, OUT float& val) const;

		private:
			StatsCategory channel;
			std::map<std::string, float> stats;
		};

		static Container* GetServer() { return &server; };
		static Container* GetUser() { return &user; };

	private:
		static Container server;
		static Container user;
	};
}