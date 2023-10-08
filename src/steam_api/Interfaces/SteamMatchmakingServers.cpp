#include "pch.h"

namespace Steam {

	// Fake server
	HServerListRequest MatchmakingServers::RequestInternetServerList(AppId_t iApp, MatchMakingKeyValuePair_t** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse* pRequestServersResponse)
	{
		DUMP_FUNC_NAME();

		const auto request = new Steam_Matchmaking_Request(); // Lifetime control transfered to ServerList()
		request->appid = iApp;
		request->callbacks = pRequestServersResponse;
		request->cancelled = false;
		request->completed = false;
		request->id = Proxima::ServerList::GrabRequestId();

		Proxima::ServerList::AddRequestToQueue(request);

		return request->id;
	}
	HServerListRequest MatchmakingServers::RequestLANServerList(AppId_t iApp, ISteamMatchmakingServerListResponse* pRequestServersResponse)
	{
		DUMP_FUNC_NAME();
		return RequestInternetServerList(iApp, nullptr, 0, pRequestServersResponse);
	}
	HServerListRequest MatchmakingServers::RequestFriendsServerList(AppId_t iApp, MatchMakingKeyValuePair_t** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse* pRequestServersResponse)
	{
		DUMP_FUNC_NAME();
		return RequestInternetServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
	}
	HServerListRequest MatchmakingServers::RequestFavoritesServerList(AppId_t iApp, MatchMakingKeyValuePair_t** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse* pRequestServersResponse)
	{
		DUMP_FUNC_NAME();
		return RequestInternetServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
	}
	HServerListRequest MatchmakingServers::RequestHistoryServerList(AppId_t iApp, MatchMakingKeyValuePair_t** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse* pRequestServersResponse)
	{
		DUMP_FUNC_NAME();
		return RequestInternetServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
	}
	HServerListRequest MatchmakingServers::RequestSpectatorServerList(AppId_t iApp, MatchMakingKeyValuePair_t** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse* pRequestServersResponse)
	{
		DUMP_FUNC_NAME();
		return RequestInternetServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
	}

	void MatchmakingServers::ReleaseRequest(HServerListRequest hServerListRequest)
	{
		// Fine
		DUMP_FUNC_NAME();
	}

	gameserveritem_t* MatchmakingServers::GetServerDetails(HServerListRequest hRequest, int iServer)
	{
		return Proxima::ServerList::GetServerInfo(hRequest, iServer);
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
		return Proxima::ServerList::GetServerCount(hRequest);
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
		auto r = new Steam_Matchmaking_Servers_Direct_IP_Request();
		r->id = Proxima::ServerList::GrabRequestId();
		r->ip = unIP;
		r->port = usPort;
		r->rules_response = pRequestServersResponse;
		r->created = std::chrono::high_resolution_clock::now();

		Logger::Print("Queueing call back for server rules of IP {}, callback addr is {}?", r->ip, reinterpret_cast<int>(r->rules_response));


		Proxima::ServerList::AddRequestToQueue(r);

		return r->id;

	}
	void MatchmakingServers::CancelServerQuery(HServerQuery hServerQuery)
	{
		DUMP_FUNC_NAME();
	}
}