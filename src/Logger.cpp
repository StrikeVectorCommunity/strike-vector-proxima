#include "pch.h"

Logger::LogMessage_t Logger::logFunction = nullptr;

bool FNameSuppressed_Hook(int nameIndex)
{
	if (nameIndex == 4937 || nameIndex == 4943) // Some inventory stuff that spams a lot in SV
	{
		return true;
	}

#define DEV_ONLINE 0x351

	//if (nameIndex != DEV_ONLINE)
	//{
	//	return true;
	//}

#undef DEV_ONLINE

	return false;
}

__declspec(naked) void FNameSuppressed_Stub()
{
	_asm
	{
		push [esp + 0x4]
		call FNameSuppressed_Hook
		add esp,4

		movsx eax, al
		retn
	}
}

void Logger::Initialize()
{
	OutputDebugStringA("Initialized logger\n");

#if false
	// Do not filter logs (FNameSuppressed returns always zero)
	Utils::Hook::Set<uint8_t>(STATIC_TO_DYNAMIC_OFFSET(0x113B6D6), 0xEB);
#else
	// Handle suppression list ourselves
	Utils::Hook(STATIC_TO_DYNAMIC_OFFSET(0x113B680), FNameSuppressed_Stub, HOOK_JUMP).install()->quick();
#endif
}

void Logger::Print_Stub(const wchar_t* message, ...)
{
	wchar_t buf[4096]{};

	va_list va;
	va_start(va, message);
	_vsnwprintf_s(buf, _TRUNCATE, message, va);
	va_end(va);

	MessagePrint(std::wstring{ buf });
}

void Logger::PrintInternal(const std::wstring_view& fmt, std::wformat_args&& args)
{
	const auto msg = std::vformat(fmt, args);

	MessagePrint(msg);
}

void Logger::PrintInternal(const std::string_view& fmt, std::format_args&& args)
{
	// NChar to WChar

	const auto narrowMessage = std::vformat(fmt, args);

	const WCHAR* pwcsName;
	int nChars = MultiByteToWideChar(CP_ACP, 0, narrowMessage.data(), -1, NULL, 0);
	pwcsName = new WCHAR[nChars];
	MultiByteToWideChar(CP_ACP, 0, narrowMessage.data(), -1, (LPWSTR)pwcsName, nChars);

	PrintInternal(pwcsName, std::make_wformat_args(0));

	delete[] pwcsName;
}

void Logger::MessagePrint(const std::wstring& msg)
{
	std::wprintf(L"%s\n", msg.data());
	std::fflush(stdout);

#ifdef _DEBUG
	std::wstring withNewLine = msg + L"\n";
	OutputDebugStringW(withNewLine.data());
#endif

	PrintOnGameConsole(msg);

}


void Logger::PrintOnGameConsole(const std::wstring& wmsg)
{
#if true
	//// Call original print function
	if (!wmsg.empty())
	{
		const auto GLogAddress = STATIC_TO_DYNAMIC_OFFSET(0x38ADC08);
		const auto GLog = Utils::Hook::Get<void*>(GLogAddress);

		if (GLog)
		{
			if (logFunction == nullptr)
			{
				logFunction = *reinterpret_cast<LogMessage_t*>(reinterpret_cast<int>(GLog) + 4);
			}

			const auto data = wmsg.c_str();
			logFunction(reinterpret_cast<void*>(GLogAddress), data, 760); // 760 is a magic here, i don't know what it is, maybe a mask
		}
		else
		{
			logFunction = nullptr;
		}
	}
#else
	// Until we know what's up with that WoW64 emulation subsystem error, better not to hook into the game directly
	// It's unstable and hard to debug
	// Maybe there is some sort of anti tampering code

	return;
#endif
}


