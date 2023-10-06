#include "pch.h"
#include "SteamScreenshots.hpp"

ScreenshotHandle Steam::Screenshots::WriteScreenshot(void* pubRGB, uint32 cubRGB, int nWidth, int nHeigh)
{
	return ScreenshotHandle();
}

ScreenshotHandle Steam::Screenshots::AddScreenshotToLibrary(const char* pchFilename, const char* pchThumbnailFilename, int nWidth, int nHeight)
{
	return ScreenshotHandle();
}

void Steam::Screenshots::TriggerScreenshot()
{
}

void Steam::Screenshots::HookScreenshots(bool bHook)
{
}

bool Steam::Screenshots::SetLocation(ScreenshotHandle hScreenshot, const char* pchLocation)
{
	return false;
}

bool Steam::Screenshots::TagUser(ScreenshotHandle hScreenshot, CSteamID steamID)
{
	return false;
}

bool Steam::Screenshots::TagPublishedFile(ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID)
{
	return false;
}

bool Steam::Screenshots::IsScreenshotsHooked()
{
	return false;
}

ScreenshotHandle Steam::Screenshots::AddVRScreenshotToLibrary(EVRScreenshotType eType, const char* pchFilename, const char* pchVRFilename)
{
	return ScreenshotHandle();
}
