#include "pch.h"

namespace Proxima
{
	std::vector<std::function<void()>> Client::frameQueue{};
	Client::Profile Client::profile{};

	void Client::RunFrame()
	{
		for (const auto& f : frameQueue)
		{
			f();
		}

		frameQueue.clear();
	}

	void Client::AddToQueue(const std::function<void()>& func)
	{
		frameQueue.push_back(func);
	}

	CSteamID Client::GenerateSteamIDFromMacAddress()              
	{        
	   uint32 id = 0;

	   IP_ADAPTER_INFO* AdapterInfo = reinterpret_cast<IP_ADAPTER_INFO*>(malloc(sizeof(IP_ADAPTER_INFO) * 32));                  
	   DWORD dwBufLen = sizeof(IP_ADAPTER_INFO) * 32;           

	   DWORD dwStatus = GetAdaptersInfo(AdapterInfo, &dwBufLen );                  
	   if ( dwStatus != ERROR_SUCCESS )       
	   {
		  id = 0xDEADBEEF; // no adapters.      
	   }
	   else if (AdapterInfo)
	   {
		   for (size_t i = 0; i < AdapterInfo->AddressLength; i++)
		   {
			   id += static_cast<uint32>(AdapterInfo->Address[i]) << i;
		   }
	   }

	   CSteamID steamID;

	   steamID.m_comp.m_EAccountType = EAccountType::k_EAccountTypeIndividual;
	   steamID.m_comp.m_EUniverse = EUniverse::k_EUniversePublic;
	   steamID.m_comp.m_unAccountInstance = 123;
	   steamID.m_comp.m_unAccountID = id;

	   free(AdapterInfo);

	   return steamID;
	}        

	std::string Client::GetUsername()
	{
		char username[UNLEN+1];
		DWORD username_len = UNLEN+1;
		GetUserNameA(username, &username_len);

		return username;
	}

	void Client::InitializeInternal()
	{
		profile.steamID = GenerateSteamIDFromMacAddress();
		profile.name = GetUsername();

		Logger::Initialize();

		Logger::Print("Client initialized - profile name {} and ID {} (account {})\n", profile.name, profile.steamID.m_unAll64Bits, static_cast<unsigned int>(profile.steamID.m_comp.m_unAccountID));
	}

	void Client::Initialize()
	{
		// app initialization intercept
		//Utils::Hook(0x24E6030, Client::On_appInit, HOOK_CALL).install()->quick();
		//Utils::Hook(0x24E8BBB, EngineInit, HOOK_CALL).install()->quick();
		//Utils::Hook(0x24E8C31, EngineInit, HOOK_CALL).install()->quick();

		Client::InitializeInternal();
	}
}