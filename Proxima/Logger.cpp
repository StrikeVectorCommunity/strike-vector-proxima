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
	const auto narrow_msg = std::vformat(fmt, args);

	  const WCHAR *pwcsName;
	  // required size
	  int nChars = MultiByteToWideChar(CP_ACP, 0, narrow_msg.data(), -1, NULL, 0);
	  // allocate it
	  pwcsName = new WCHAR[nChars];
	  MultiByteToWideChar(CP_ACP, 0, narrow_msg.data(), -1, (LPWSTR)pwcsName, nChars);
	  // use it....
    
	  PrintInternal(pwcsName, std::make_wformat_args(0));

	  // delete it
	  delete [] pwcsName;
}

void Logger::MessagePrint(const std::wstring& msg)
{
	std::wprintf(L"%s", msg.data());
	std::fflush(stdout);

#ifdef _DEBUG
	OutputDebugStringW(msg.data());
#endif

	PrintOnGameConsole(msg);

}

void Logger::PrintOnGameConsole(const std::wstring& wmsg)
{
	void* unknownSingleton = Utils::Hook::Get<void*>(0x389D01C);

	Utils::Hook::Call<void(void*, const wchar_t*)>(0x113B9D0)(unknownSingleton, wmsg.data());
	const auto a = __func__ ;
}



Logger::Logger()
{
	//Utils::Hook(Game::G_LogPrintf, G_LogPrintf_Hk, HOOK_JUMP).install()->quick();
	//Utils::Hook(Game::Com_PrintMessage, PrintMessage_Stub, HOOK_JUMP).install()->quick();
}
