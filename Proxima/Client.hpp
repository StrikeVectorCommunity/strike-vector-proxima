#pragma once

namespace Proxima
{
	class Client
	{
	public:
		static void Initialize();
		static void RunFrame();
		static void AddToQueue(const std::function<void()>& func);

		static const char* GetName()
		{
			return profile.name.data();
		}

		static CSteamID GetSteamID()
		{
			return profile.steamID;
		}

	private:
		struct Profile
		{
			std::string name;
			CSteamID steamID;
		};

		static Profile profile;

		static std::vector<std::function<void()>> frameQueue;
	
		static CSteamID GenerateSteamIDFromMacAddress();
		static std::string GetUsername();

		static void InitializeInternal();
	};
}