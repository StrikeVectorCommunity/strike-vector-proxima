#include "pch.h"

namespace Steam {

	// Fake server
	static HServerListRequest fakeServerRequest = 123;
	static int fakeServerID = 456;

	HServerListRequest MatchmakingServers::RequestInternetServerList(AppId_t iApp, MatchMakingKeyValuePair_t** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse* pRequestServersResponse)
	{
		DUMP_FUNC_NAME();
		//return HServerListRequest();
		Steam_Matchmaking_Request request{};
		request.appid = iApp;
		request.callbacks = pRequestServersResponse;
		request.cancelled = false;
		request.completed = false;
		request.id = fakeServerRequest;

		Logger::Print("Queueing call back for fake server ID {}, callback addr is {}? cancelled:{} completed:{}", fakeServerID, reinterpret_cast<int>(request.callbacks), request.cancelled, request.completed);

		Proxima::Client::AddToQueue([request]() {
			// When it's here
			Logger::Print("Executing call back for fake server ID {}, callback addr is {}? cancelled:{} completed:{}", fakeServerID, reinterpret_cast<int>(request.callbacks), request.cancelled, request.completed);
			request.callbacks->ServerResponded(fakeServerRequest, fakeServerID);
			request.callbacks->RefreshComplete(fakeServerRequest, EMatchMakingServerResponse::eServerResponded);
			});


		return fakeServerRequest;
	}
	HServerListRequest MatchmakingServers::RequestLANServerList(AppId_t iApp, ISteamMatchmakingServerListResponse* pRequestServersResponse)
	{
		DUMP_FUNC_NAME();
		return HServerListRequest();
	}
	HServerListRequest MatchmakingServers::RequestFriendsServerList(AppId_t iApp, MatchMakingKeyValuePair_t** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse* pRequestServersResponse)
	{
		DUMP_FUNC_NAME();
		return HServerListRequest();
	}
	HServerListRequest MatchmakingServers::RequestFavoritesServerList(AppId_t iApp, MatchMakingKeyValuePair_t** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse* pRequestServersResponse)
	{
		DUMP_FUNC_NAME();
		return HServerListRequest();
	}
	HServerListRequest MatchmakingServers::RequestHistoryServerList(AppId_t iApp, MatchMakingKeyValuePair_t** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse* pRequestServersResponse)
	{
		DUMP_FUNC_NAME();
		return HServerListRequest();
	}
	HServerListRequest MatchmakingServers::RequestSpectatorServerList(AppId_t iApp, MatchMakingKeyValuePair_t** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse* pRequestServersResponse)
	{
		DUMP_FUNC_NAME();
		return HServerListRequest();
	}
	void MatchmakingServers::ReleaseRequest(HServerListRequest hServerListRequest)
	{
	}

	gameserveritem_t* MatchmakingServers::GetServerDetails(HServerListRequest hRequest, int iServer)
	{
		DUMP_FUNC_NAME();

		if (hRequest == fakeServerRequest && iServer == fakeServerID)
		{
			Logger::Print("Requested server details for server {}!", iServer);

			static gameserveritem_t item{};

			item.m_nPing = 100;
			item.m_NetAdr.SetIP(3232235777); // 192 178 1 1
			item.m_NetAdr.SetConnectionPort(1234);
			item.m_bHadSuccessfulResponse = true;
			item.m_bDoNotRefresh = false;
			item.m_nAppID = 246700;

			item.SetName("TEST SERVER HELLO!!!");
			item.m_steamID.m_unAll64Bits = 12345678;


			std::strcpy(item.m_szGameDescription, "TEST SERVER DESCRIPTION");
			std::strcpy(item.m_szMap, "TEST SERVER ");

			return &item;

		}

		return nullptr;
	}
	void MatchmakingServers::CancelQuery(HServerListRequest hRequest)
	{
		DUMP_FUNC_NAME();
	}

	void MatchmakingServers::RefreshQuery(HServerListRequest hRequest)
	{
		DUMP_FUNC_NAME();
	}
	bool MatchmakingServers::IsRefreshing(HServerListRequest hRequest)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	int MatchmakingServers::GetServerCount(HServerListRequest hRequest)
	{
		DUMP_FUNC_NAME();
		return 0;
	}
	void MatchmakingServers::RefreshServer(HServerListRequest hRequest, int iServer)
	{
		DUMP_FUNC_NAME();
	}

	HServerQuery MatchmakingServers::PingServer(uint32 unIP, uint16 usPort, ISteamMatchmakingPingResponse* pRequestServersResponse)
	{
		DUMP_FUNC_NAME();
		return HServerQuery();
	}
	HServerQuery MatchmakingServers::PlayerDetails(uint32 unIP, uint16 usPort, ISteamMatchmakingPlayersResponse* pRequestServersResponse)
	{
		DUMP_FUNC_NAME();
		return HServerQuery();
	}
	HServerQuery MatchmakingServers::ServerRules(uint32 unIP, uint16 usPort, ISteamMatchmakingRulesResponse* pRequestServersResponse)
	{
		DUMP_FUNC_NAME();

		//return HServerListRequest();
		Steam_Matchmaking_Servers_Direct_IP_Request r;
		r.id = 78910;
		r.ip = unIP;
		r.port = usPort;
		r.rules_response = pRequestServersResponse;
		r.created = std::chrono::high_resolution_clock::now();

		Logger::Print("Queueing call back for server rules of IP {}, callback addr is {}?", unIP, reinterpret_cast<int>(r.rules_response));


		Proxima::Client::AddToQueue([unIP, r]() {
			// When it's here
			Logger::Print("Executing call back for rules of IP {}, callback addr is {}?", unIP, reinterpret_cast<int>(r.rules_response));
			r.rules_response->RulesRefreshComplete();
			});


		return HServerQuery();

	}
	void MatchmakingServers::CancelServerQuery(HServerQuery hServerQuery)
	{
		DUMP_FUNC_NAME();
	}
}