#pragma once
namespace Proxima
{
	class ServerList
	{
	public:
		static void GetServers(HServerListRequest requestId, Steam::Steam_Matchmaking_Request request);
		static gameserveritem_t* GetServerInfo(HServerListRequest requestId, int id);
		static void GetServerRules(HServerListRequest requestId, const Steam::Steam_Matchmaking_Servers_Direct_IP_Request& request, uint32_t ip, uint16_t port);
		static int GetServerCount(HServerListRequest requestId) { return mockServers.size(); }

		static HServerListRequest GrabRequestId() { return ++nextRequestId; };

	private:
		struct ServerData
		{
			gameserveritem_t item{};
			std::map<std::string, std::string> rules{};
		};

		static ServerData CreateMockServer();

		static std::vector<ServerData> mockServers;
		static bool hasMocked;

		static HServerListRequest nextRequestId;
	};
}