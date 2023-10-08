// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#pragma once

#pragma warning(disable: 4100)

#define __STDC_LIB_EXT1__ 1
#define __STDC_WANT_LIB_EXT1__ 1

// add headers that you want to pre-compile here
#include <windows.h>
#include <cstdint>
#include <map>
#include <vector>
#include <mutex>
#include <unordered_map>
#include <functional>
#include <optional>
#include <assert.h>
#include <Lmcons.h>
#include <shellapi.h>
#include <iostream>
#include <fstream>
#include <codecvt>
#include <filesystem>

#include "iphlpapi.h"

#include "Memory.h"
#include "Hooking.h"
#include "Logger.hpp"

#define STRIKE_VECTOR_APPID 246700

namespace Proxima
{
	class Client;
	class Server;
}

#include "net.proto.h"

#include "steam_api/Steam.hpp"

#include "Auth.hpp"
#include "FileSystem.hpp"
#include "Stats.hpp"
#include "Leaderboards.hpp"

#include "Client.hpp"
#include "Server.hpp"
#include "ServerList.hpp"

#endif //PCH_H
