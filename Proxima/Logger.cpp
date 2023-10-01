#include "pch.h"

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
	// Until we know what's up with that WoW64 emulation subsystem error, better not to hook into the game directly
	// It's unstable and hard to debug
	// Maybe there is some sort of anti tampering code
	return;

#if false
	//// Call original print function
	if (!wmsg.empty())
	{
		const bool* GFileManager = Utils::Hook::Get<bool*>(0x389D030);

		if (*GFileManager)
		{
			constexpr auto GLog = 0x389D028;

			Utils::Hook::Call<void(int, const wchar_t*)>(0x113B9D0)(GLog, wmsg.c_str());
		}
	}
#endif
}



Logger::Logger()
{
}
