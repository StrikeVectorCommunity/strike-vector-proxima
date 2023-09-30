#include "pch.h"
#include "SteamRemoteStorage.hpp"

STEAM_IGNORE_WARNINGS_START

namespace Steam
{
	
	bool RemoteStorage::FileWrite(const char* pchFile, const void* pvData, int32 cubData)
	{
		return false;
	}
	int32 RemoteStorage::FileRead(const char* pchFile, void* pvData, int32 cubDataToRead)
	{
		return int32();
	}
	bool RemoteStorage::FileForget(const char* pchFile)
	{
		return false;
	}
	bool RemoteStorage::FileDelete(const char* pchFile)
	{
		return false;
	}
	SteamAPICall_t RemoteStorage::FileShare(const char* pchFile)
	{
		return SteamAPICall_t();
	}
	bool RemoteStorage::SetSyncPlatforms(const char* pchFile, ERemoteStoragePlatform eRemoteStoragePlatform)
	{
		return false;
	}
	UGCFileWriteStreamHandle_t RemoteStorage::FileWriteStreamOpen(const char* pchFile)
	{
		return UGCFileWriteStreamHandle_t();
	}
	bool RemoteStorage::FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t writeHandle, const void* pvData, int32 cubData)
	{
		return false;
	}
	bool RemoteStorage::FileWriteStreamClose(UGCFileWriteStreamHandle_t writeHandle)
	{
		return false;
	}
	bool RemoteStorage::FileWriteStreamCancel(UGCFileWriteStreamHandle_t writeHandle)
	{
		return false;
	}
	bool RemoteStorage::FileExists(const char* pchFile)
	{
		return false;
	}
	bool RemoteStorage::FilePersisted(const char* pchFile)
	{
		return false;
	}
	int32 RemoteStorage::GetFileSize(const char* pchFile)
	{
		return int32();
	}
	int64 RemoteStorage::GetFileTimestamp(const char* pchFile)
	{
		return int64();
	}
	ERemoteStoragePlatform RemoteStorage::GetSyncPlatforms(const char* pchFile)
	{
		return ERemoteStoragePlatform();
	}
	int32 RemoteStorage::GetFileCount()
	{
		return int32();
	}
	const char* RemoteStorage::GetFileNameAndSize(int iFile, int32* pnFileSizeInBytes)
	{
		return nullptr;
	}
	bool RemoteStorage::GetQuota(int32* pnTotalBytes, int32* puAvailableBytes)
	{
		*pnTotalBytes = 0x10000000;
		*puAvailableBytes = 0x10000000;
		return false;
	}
	bool RemoteStorage::IsCloudEnabledForAccount()
	{
		return false;
	}
	bool RemoteStorage::IsCloudEnabledForApp()
	{
		return false;
	}
	void RemoteStorage::SetCloudEnabledForApp(bool bEnabled)
	{
	}
	SteamAPICall_t RemoteStorage::UGCDownload(UGCHandle_t hContent)
	{
		return SteamAPICall_t();
	}
	bool RemoteStorage::GetUGCDownloadProgress(UGCHandle_t hContent, int32* pnBytesDownloaded, int32* pnBytesExpected)
	{
		return false;
	}
	bool RemoteStorage::GetUGCDetails(UGCHandle_t hContent, AppId_t* pnAppID, char** ppchName, int32* pnFileSizeInBytes, CSteamID* pSteamIDOwner)
	{
		return false;
	}
	int32 RemoteStorage::UGCRead(UGCHandle_t hContent, void* pvData, int32 cubDataToRead)
	{
		return int32();
	}
	int32 RemoteStorage::GetCachedUGCCount()
	{
		return int32();
	}
	UGCHandle_t RemoteStorage::GetCachedUGCHandle(int32 iCachedContent)
	{
		return UGCHandle_t();
	}
	SteamAPICall_t RemoteStorage::PublishWorkshopFile(const char* pchFile, const char* pchPreviewFile, AppId_t nConsumerAppId, const char* pchTitle, const char* pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t* pTags, EWorkshopFileType eWorkshopFileType)
	{
		return SteamAPICall_t();
	}
	PublishedFileUpdateHandle_t RemoteStorage::CreatePublishedFileUpdateRequest(PublishedFileId_t unPublishedFileId)
	{
		return PublishedFileUpdateHandle_t();
	}
	bool RemoteStorage::UpdatePublishedFileFile(PublishedFileUpdateHandle_t updateHandle, const char* pchFile)
	{
		return false;
	}
	bool RemoteStorage::UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t updateHandle, const char* pchPreviewFile)
	{
		return false;
	}
	bool RemoteStorage::UpdatePublishedFileTitle(PublishedFileUpdateHandle_t updateHandle, const char* pchTitle)
	{
		return false;
	}
	bool RemoteStorage::UpdatePublishedFileDescription(PublishedFileUpdateHandle_t updateHandle, const char* pchDescription)
	{
		return false;
	}
	bool RemoteStorage::UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility)
	{
		return false;
	}
	bool RemoteStorage::UpdatePublishedFileTags(PublishedFileUpdateHandle_t updateHandle, SteamParamStringArray_t* pTags)
	{
		return false;
	}
	SteamAPICall_t RemoteStorage::CommitPublishedFileUpdate(PublishedFileUpdateHandle_t updateHandle)
	{
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::GetPublishedFileDetails(PublishedFileId_t unPublishedFileId)
	{
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::DeletePublishedFile(PublishedFileId_t unPublishedFileId)
	{
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::EnumerateUserPublishedFiles(uint32 unStartIndex)
	{
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::SubscribePublishedFile(PublishedFileId_t unPublishedFileId)
	{
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::EnumerateUserSubscribedFiles(uint32 unStartIndex)
	{
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::UnsubscribePublishedFile(PublishedFileId_t unPublishedFileId)
	{
		return SteamAPICall_t();
	}
	bool RemoteStorage::UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t updateHandle, const char* pchChangeDescription)
	{
		return false;
	}
	SteamAPICall_t RemoteStorage::GetPublishedItemVoteDetails(PublishedFileId_t unPublishedFileId)
	{
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::UpdateUserPublishedItemVote(PublishedFileId_t unPublishedFileId, bool bVoteUp)
	{
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::GetUserPublishedItemVoteDetails(PublishedFileId_t unPublishedFileId)
	{
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::EnumerateUserSharedWorkshopFiles(CSteamID steamId, uint32 unStartIndex, SteamParamStringArray_t* pRequiredTags, SteamParamStringArray_t* pExcludedTags)
	{
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::PublishVideo(EWorkshopVideoProvider eVideoProvider, const char* pchVideoAccount, const char* pchVideoIdentifier, const char* pchPreviewFile, AppId_t nConsumerAppId, const char* pchTitle, const char* pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t* pTags)
	{
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::SetUserPublishedFileAction(PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction)
	{
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::EnumeratePublishedFilesByUserAction(EWorkshopFileAction eAction, uint32 unStartIndex)
	{
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType eEnumerationType, uint32 unStartIndex, uint32 unCount, uint32 unDays, SteamParamStringArray_t* pTags, SteamParamStringArray_t* pUserTags)
	{
		return SteamAPICall_t();
	}
}

STEAM_IGNORE_WARNINGS_END
