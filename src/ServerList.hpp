#pragma once
namespace Proxima
{
	class ServerList
	{
	public:
		static gameserveritem_t* GetServerInfo(HServerListRequest requestId, int id);
		static int GetServerCount(HServerListRequest requestId) { return mockServers.size(); }

		static HServerListRequest GrabRequestId() { return ++nextRequestId; };
		static void AddRequestToQueue(Steam::Steam_Matchmaking_Request* request);
		static void AddRequestToQueue(Steam::Steam_Matchmaking_Servers_Direct_IP_Request* request);

		static void RunFrame();

	private:
		struct ServerData
		{
			gameserveritem_t item{};
			std::map<std::string, std::string> rules{};
		};

		static std::mutex mutex;

		static std::vector<ServerData> mockServers;
		static bool hasMocked;

		static std::vector<Steam::Steam_Matchmaking_Request*> matchmakingRequests;
		static std::vector<Steam::Steam_Matchmaking_Servers_Direct_IP_Request*> rulesRequests;
		static HServerListRequest nextRequestId;

		static ServerData CreateMockServer();
		static void ProcessRequest(Steam::Steam_Matchmaking_Request* request);
		static void ProcessRequest(Steam::Steam_Matchmaking_Servers_Direct_IP_Request* request);
	};
}