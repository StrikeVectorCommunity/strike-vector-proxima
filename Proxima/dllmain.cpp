// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		// Important to adjust to ASLR on each run
		if (Utils::Hook::FindProgramOffset())
		{
			Logger::Initialize();
			Logger::Print("Client adjusted to ASLR offset of {:#010x}", Utils::Hook::GetProgramOffset());

			Proxima::Client::Initialize();
		}
		else
		{
			// We failed to find program offset, we _need_ to leave
			return FALSE;
		}
	}
		break;

	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		return TRUE;
	}
	
	return TRUE;
}

