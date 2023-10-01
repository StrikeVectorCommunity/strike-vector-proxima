const int k_cbMaxGameServerGameDir = 32;
const int k_cbMaxGameServerMapName = 32;
const int k_cbMaxGameServerGameDescription = 64;
const int k_cbMaxGameServerName = 64;
const int k_cbMaxGameServerTags = 128;
const int k_cbMaxGameServerGameData = 2048;

class gameserveritem_t
{
public:
	gameserveritem_t();

	const char* GetName() const;
	void SetName( const char *pName );

public:
	servernetadr_t m_NetAdr;									///< IP/Query Port/Connection Port for this server
	int m_nPing;												///< current ping time in milliseconds
	bool m_bHadSuccessfulResponse;								///< server has responded successfully in the past
	bool m_bDoNotRefresh;										///< server is marked as not responding and should no longer be refreshed
	char m_szGameDir[k_cbMaxGameServerGameDir];					///< current game directory
	char m_szMap[k_cbMaxGameServerMapName];						///< current map
	char m_szGameDescription[k_cbMaxGameServerGameDescription];	///< game description
	uint32 m_nAppID;											///< Steam App ID of this server
	int m_nPlayers;												///< total number of players currently on the server.  INCLUDES BOTS!!
	int m_nMaxPlayers;											///< Maximum players that can join this server
	int m_nBotPlayers;											///< Number of bots (i.e simulated players) on this server
	bool m_bPassword;											///< true if this server needs a password to join
	bool m_bSecure;												///< Is this server protected by VAC
	uint32 m_ulTimeLastPlayed;									///< time (in unix time) when this server was last played on (for favorite/history servers)
	int	m_nServerVersion;										///< server version as reported to Steam

private:

	/// Game server name
	char m_szServerName[k_cbMaxGameServerName];

	// For data added after SteamMatchMaking001 add it here
public:
	/// the tags this server exposes
	char m_szGameTags[k_cbMaxGameServerTags];

	/// steamID of the game server - invalid if it's doesn't have one (old server, or not connected to Steam)
	CSteamID m_steamID;
};

inline gameserveritem_t::gameserveritem_t()
{
	m_szGameDir[0] = m_szMap[0] = m_szGameDescription[0] = m_szServerName[0] = 0;
	m_bHadSuccessfulResponse = m_bDoNotRefresh = m_bPassword = m_bSecure = false;
	m_nPing = m_nAppID = m_nPlayers = m_nMaxPlayers = m_nBotPlayers = m_ulTimeLastPlayed = m_nServerVersion = 0;
	m_szGameTags[0] = 0;
}

inline const char* gameserveritem_t::GetName() const
{
	// Use the IP address as the name if nothing is set yet.
	if ( m_szServerName[0] == 0 )
		return m_NetAdr.GetConnectionAddressString();
	else
		return m_szServerName;
}

inline void gameserveritem_t::SetName( const char *pName )
{
	strncpy( m_szServerName, pName, sizeof( m_szServerName ) );
	m_szServerName[ sizeof( m_szServerName ) - 1 ] = '\0';
}

