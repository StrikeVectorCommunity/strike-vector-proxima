#include "pch.h"

namespace Proxima
{
#define PRINT_DEBUG(x) Logger::Print(x)

	// Taken largely from goldberg
	int Auth::nextTicketID = 2;
    std::vector<struct Auth_Ticket_Data> Auth::inbound{}, Auth::outbound{};
	
	constexpr auto  STEAM_AUTH_TICKET_SIZE = 234;
	constexpr auto STEAM_ID_OFFSET_TICKET = (4 + 8);
	constexpr auto STEAM_TICKET_MIN_SIZE = (4 + 8 + 8);

    Auth_Ticket_Data Auth::MakeTicketData(void* pTicket, int cbMaxTicket, uint32* pcbTicket)
    {
        uint64 steam_id = Proxima::Client::GetSteamID().m_unAll64Bits;
        memset(pTicket, 123, cbMaxTicket);
        ((char*)pTicket)[0] = 0x14;
        ((char*)pTicket)[1] = 0;
        ((char*)pTicket)[2] = 0;
        ((char*)pTicket)[3] = 0;
        memcpy((char*)pTicket + STEAM_ID_OFFSET_TICKET, &steam_id, sizeof(steam_id));
        *pcbTicket = cbMaxTicket;

        Auth_Ticket_Data ticket_data;
        ticket_data.id = Proxima::Client::GetSteamID();
        ticket_data.number = ++nextTicketID;
        uint32 ttt = static_cast<uint32>(ticket_data.number);

        memcpy(((char*)pTicket) + sizeof(uint64), &ttt, sizeof(ttt));
        return ticket_data;
    }

    uint32 Auth::GenerateTicket(void* pTicket, int cbMaxTicket, uint32* pcbTicket)
    {
        if (cbMaxTicket < STEAM_TICKET_MIN_SIZE) return 0;
        if (cbMaxTicket > STEAM_AUTH_TICKET_SIZE) cbMaxTicket = STEAM_AUTH_TICKET_SIZE;

        Auth_Ticket_Data ticket_data = MakeTicketData(pTicket, cbMaxTicket, pcbTicket);
        uint32 ttt = static_cast<uint32>(ticket_data.number);
        Steam::GetAuthSessionTicketResponse_t data;
        data.m_hAuthTicket = ttt;
        data.m_eResult = k_EResultOK;

        const auto callID = Steam::Callbacks::RegisterCall();
        Steam::Callbacks::ReturnCall(&data, sizeof(data), data.k_iCallback, callID);

        outbound.push_back(ticket_data);

        return ttt;
    }


    void Auth::CancelTicket(uint32 number)
    {
        const auto ticket = std::find_if(outbound.begin(), outbound.end(), [&number](Auth_Ticket_Data const& item) { return item.number == number; });
        if (outbound.end() == ticket)
            return;

        Auth_Ticket auth_ticket{};
        auth_ticket.number = number;
        auth_ticket.type = Auth_Ticket::CANCEL;
        Common_Message msg;
        msg.source_id = Proxima::Client::GetSteamID().m_unAll64Bits;
        msg.message.auth_ticket = auth_ticket;

        //network->sendToAll(&msg, true);

        outbound.erase(ticket);
    }
    EBeginAuthSessionResult Auth::BeginAuth(const void* pAuthTicket, int cbAuthTicket, CSteamID steamID)
    {
        // IDK why this is the timeout
#define STEAM_TICKET_PROCESS_TIME 0.03 

        if (cbAuthTicket < STEAM_TICKET_MIN_SIZE)
        {
            return k_EBeginAuthSessionResultInvalidTicket;
        }

        Auth_Ticket_Data data;
        uint64 id;
        memcpy(&id, (char *)pAuthTicket + STEAM_ID_OFFSET_TICKET, sizeof(id));
        uint32 number;
        memcpy(&number, ((char *)pAuthTicket) + sizeof(uint64), sizeof(number));

        CSteamID sid{};
        sid.m_unAll64Bits = id;

        data.id = sid;
        data.number = number;
        data.created = std::chrono::high_resolution_clock::now();

        for (auto & t : inbound) {
            if (t.id == data.id && !HasTimedOut(t.created, STEAM_TICKET_PROCESS_TIME)) {
                return k_EBeginAuthSessionResultDuplicateRequest;
            }
        }

        inbound.push_back(data);
        LaunchCallback(steamID, EAuthSessionResponse::k_EAuthSessionResponseOK);

#undef STEAM_TICKET_PROCESS_TIME

        return k_EBeginAuthSessionResultOK;
    }

    bool Auth::EndAuth(CSteamID id)
    {
        bool erased = false;
        auto t = std::begin(inbound);
        while (t != std::end(inbound)) {
            if (t->id == id) {
                erased = true;
                t = inbound.erase(t);
            } else {
                ++t;
            }
        }

        return erased;
    }

    bool Auth::HasTimedOut(std::chrono::high_resolution_clock::time_point old, double timeout)
    {
        if (timeout == 0.0) return true;

        std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
        if (std::chrono::duration_cast<std::chrono::duration<double>>(now - old).count() > timeout) {
            return true;
        }

        return false;
    }

    void Auth::LaunchCallback(CSteamID id, EAuthSessionResponse resp)
    {
        ValidateAuthTicketResponse_t data;
        data.m_SteamID = id;
        data.m_eAuthSessionResponse = resp;
        data.m_OwnerSteamID = id;
        
        const auto callID = Steam::Callbacks::RegisterCall();
        Steam::Callbacks::ReturnCall(&data, sizeof(data), data.k_iCallback, callID);
    }
}
