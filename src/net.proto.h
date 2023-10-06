#include "pch.h"

#pragma pack(push, 1)
struct Auth_Ticket
{
	uint32_t number;
	enum : int32_t { CANCEL = 0x0 } type;
};

struct Common_Message
{
    uint64_t source_id;
    uint64_t dest_id;

	enum : uint32_t{
	    EAnnounce = 3
        , ELow_Level = 4
        , ELobby = 5
        , ELobby_Messages = 6
        , ENetwork_pb = 7
        , EGameserver = 8
        , EFriend = 9
        , EAuth_Ticket = 10
        , EFriend_Messages = 11
        , ENetwork_Old = 12
        , ENetworking_Sockets = 13
        , ESteam_Messages = 14
        , ENetworking_Messages = 15
	} message_type;

	union
	{
        void* unknown;
        Auth_Ticket auth_ticket;
	} message;

	uint32_t source_ip;
	uint32_t source_port;
};


#pragma pack(pop)