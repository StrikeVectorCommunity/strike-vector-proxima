#pragma once

class Logger
{
public:
	static void Initialize();

	static void Print_Stub(const wchar_t* message, ...);

	static void PrintInternal(const std::wstring_view& fmt, std::wformat_args&& args);
	static void PrintInternal(const std::string_view& fmt, std::format_args&& args);

	static void Print(const std::wstring_view& fmt)
	{
		PrintInternal(fmt, std::make_wformat_args(0));
	}

	template <typename... Args>
	static void Print(const std::wstring_view& fmt, Args&&... args)
	{
		PrintInternal(fmt, std::make_wformat_args(args...));
	}
	
	static void Print(const std::string_view& fmt)
	{
		PrintInternal(fmt, std::make_format_args(0));
	}

	template <typename... Args>
	static void Print(const std::string_view& fmt, Args&&... args)
	{
		PrintInternal(fmt, std::make_format_args(args...));
	}

private:
	typedef void(__thiscall* LogMessage_t)(void*, const wchar_t*, int);

	static LogMessage_t logFunction;

	static void MessagePrint(const std::wstring& msg);
	static void PrintOnGameConsole(const std::wstring& wmsg);
};

#define XX(str) L#str
#define X(str) XX(str)
#define DUMP_FUNC_NAME() { Logger::Print("Called API {}:{} {}",  __FILE__, __FUNCTION__, __LINE__); }
