#include "pch.h"

namespace Proxima
{
	std::vector<ServerList::ServerData> ServerList::mockServers{};
	bool ServerList::hasMocked;
	HServerListRequest ServerList::nextRequestId = 1;

	void ServerList::GetServers(HServerListRequest req, Steam::Steam_Matchmaking_Request request)
	{
		if (!hasMocked)
		{
			hasMocked = true;
			for (size_t i = 0; i < 1; i++)
			{
				mockServers.push_back(CreateMockServer());
			}
		}

		for (size_t i = 0; i < mockServers.size(); i++)
		{
			request.callbacks->ServerResponded(req, i + 1);
		}

		request.callbacks->RefreshComplete(req, Steam::EMatchMakingServerResponse::eServerResponded);
	}

	gameserveritem_t* ServerList::GetServerInfo(HServerListRequest requestId, int id)
	{
		Logger::Print("Getting server info for server {} (out of {} mock servers)", id, mockServers.size());
		return &mockServers[id - 1].item;
	}

	void ServerList::GetServerRules(HServerListRequest requestId, const Steam::Steam_Matchmaking_Servers_Direct_IP_Request& request, uint32_t ip, uint16_t port)
	{
		for (const auto& server : mockServers)
		{
			if (server.item.m_NetAdr.GetIP() == ip && server.item.m_NetAdr.GetQueryPort() == port)
			{
				for (const auto& kv : server.rules)
				{
					request.rules_response->RulesResponded(kv.first.data(), kv.second.data());
				}

				Logger::Print("Responded with server rules for ip {} and port {}", ip, port);
				request.rules_response->RulesRefreshComplete();

				return;
			}
		}

		Logger::Print("No server on ip:port {}:{} in server list ({})", ip, port, mockServers.size());
	}

	ServerList::ServerData ServerList::CreateMockServer()
	{
		gameserveritem_t item{};
		item.m_bDoNotRefresh = false;
		item.m_bHadSuccessfulResponse = true;
		item.m_bPassword = false;
		item.m_bSecure = false;
		item.m_nAppID = STRIKE_VECTOR_APPID;
		item.m_nBotPlayers = 0;
		item.m_NetAdr.SetIP(3232235777);
		item.m_NetAdr.SetConnectionPort(7777);
		item.m_NetAdr.SetQueryPort(27015);
		item.m_nMaxPlayers = 16;

		{
			float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			item.m_nPing = static_cast<int>(r * 100);
		}
		
		

		item.m_nPlayers = 0;
		item.m_nServerVersion = 4382;
		item.m_steamID.m_unAll64Bits = 1;
		std::strcpy(item.m_szGameDescription, "HarrierGameInfo");
		std::strcpy(item.m_szGameDir, "StrikeVector");
		item.SetName("StrikeVector");
		std::strcpy(item.m_szGameDescription, "HarrierGameInfo");
		std::strcpy(item.m_szMap, "sw_02");
		item.m_ulTimeLastPlayed = 0;

		std::map<std::string, std::string> rules{};
		rules["SteamEngineVersion"] = std::to_string(10907);
		rules["OwningPlayerId"] = std::to_string(0);
		rules["NumPublicConnections"] = std::to_string(32);
		rules["bUsesStats"] = "True";
		rules["bIsDedicated"] = "True";
		rules["OwningPlayerName"] = "Strike Vector";

#define SERV_NAME "p1073741825"
#define SERV_MAP "p1073741826"
#define SERV_GAMEMODE "p1073741827"
#define SERV_MAX_CONNECTIONS "p1073741832"
#define SERV_VERSION "p1073741831"
#define SERV_CURRENT_PLAYERS "p1073741833"
#define SERV_DOM_POINTS "p1073741828"
#define SERV_MAX_LEVEL "p1073741840"

		rules[SERV_NAME] = "Mock server!";
		rules[SERV_MAP] = "bomber";
		rules[SERV_GAMEMODE] = "tdm";
		rules[SERV_MAX_CONNECTIONS] = "32";
		rules[SERV_VERSION] = "4382";
		rules[SERV_CURRENT_PLAYERS] = "0";
		rules[SERV_DOM_POINTS] = "3";
		rules[SERV_MAX_LEVEL] = "";

		// There's more.. like 1073741830
		/*
const PROPERTY_SERVERNAME = 0x40000001;
const PROPERTY_MAPNAME = 0x40000002;
const PROPERTY_GAMEMODE = 0x40000003;
const PROPERTY_DOMPOINTS = 0x40000004;
const PROPERTY_GAMEMODEOPTION0 = 0x40000005;
const PROPERTY_GAMEMODEOPTION1 = 0x40000006;
const PROPERTY_GAMEVERSION = 0x40000007;
const PROPERTY_MAXPLAYERS = 0x40000008;
const PROPERTY_CURRENTPLAYERS = 0x40000009;
const PROPERTY_MAXLEVEL = 0x40000010;
		*/

		return ServerList::ServerData{ item, rules };
	}

}