#pragma once
namespace Proxima
{
	class Auth
	{
	public:
		static uint32 GenerateTicket(void* pTicket, int cbMaxTicket, uint32* pcbTicket);
		static void CancelTicket(uint32 number);
		static EBeginAuthSessionResult BeginAuth(const void* pAuthTicket, int cbAuthTicket, CSteamID steamID);

		static bool EndAuth(CSteamID id);

	private:


		static std::vector<struct Auth_Ticket_Data> inbound, outbound;
		static int nextTicketID;

		static Auth_Ticket_Data MakeTicketData(void* pTicket, int cbMaxTicket, uint32* pcbTicket);
		static bool HasTimedOut(std::chrono::high_resolution_clock::time_point old, double timeout);

		static void LaunchCallback(CSteamID id, EAuthSessionResponse resp);
	};
}