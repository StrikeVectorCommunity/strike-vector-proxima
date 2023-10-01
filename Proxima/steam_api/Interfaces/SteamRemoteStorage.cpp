#include "pch.h"
#include "SteamRemoteStorage.hpp"

STEAM_IGNORE_WARNINGS_START

namespace Steam
{
	
	bool RemoteStorage::FileWrite(const char* pchFile, const void* pvData, int32 cubData)
	{
		Logger::Print("RemoteStorage: Writing file {} with {} bytes of data", pchFile, cubData);

		return Proxima::FileSystem::WriteRemoteStorageFile(pchFile, reinterpret_cast<const char*>(pvData), cubData);
	}
	int32 RemoteStorage::FileRead(const char* pchFile, void* pvData, int32 cubDataToRead)
	{
		Logger::Print("RemoteStorage: Reading file {} with {} bytes of  data", pchFile, cubDataToRead);

		const std::string buff = Proxima::FileSystem::ReadRemoteStorageFile(pchFile, cubDataToRead);
		std::memcpy(pvData, buff.data(), min(static_cast<uint32_t>(cubDataToRead), buff.size()));

		return buff.size();
	}
	bool RemoteStorage::FileForget(const char* pchFile)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	bool RemoteStorage::FileDelete(const char* pchFile)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	SteamAPICall_t RemoteStorage::FileShare(const char* pchFile)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	bool RemoteStorage::SetSyncPlatforms(const char* pchFile, ERemoteStoragePlatform eRemoteStoragePlatform)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	UGCFileWriteStreamHandle_t RemoteStorage::FileWriteStreamOpen(const char* pchFile)
	{
		DUMP_FUNC_NAME();
		return UGCFileWriteStreamHandle_t();
	}
	bool RemoteStorage::FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t writeHandle, const void* pvData, int32 cubData)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	bool RemoteStorage::FileWriteStreamClose(UGCFileWriteStreamHandle_t writeHandle)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	bool RemoteStorage::FileWriteStreamCancel(UGCFileWriteStreamHandle_t writeHandle)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	bool RemoteStorage::FileExists(const char* pchFile)
	{
		Logger::Print("RemoteStorage: Checked if file {} exists", pchFile);
		return false;
	}
	bool RemoteStorage::FilePersisted(const char* pchFile)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	int32 RemoteStorage::GetFileSize(const char* pchFile)
	{
		Logger::Print("RemoteStorage: Queried file size of file {}", pchFile);
		return Proxima::FileSystem::GetRemoteStorageFileSize(pchFile);
	}
	int64 RemoteStorage::GetFileTimestamp(const char* pchFile)
	{
		DUMP_FUNC_NAME();
		return int64();
	}
	ERemoteStoragePlatform RemoteStorage::GetSyncPlatforms(const char* pchFile)
	{
		DUMP_FUNC_NAME();
		return ERemoteStoragePlatform();
	}
	int32 RemoteStorage::GetFileCount()
	{
		DUMP_FUNC_NAME();
		return int32();
	}
	const char* RemoteStorage::GetFileNameAndSize(int iFile, int32* pnFileSizeInBytes)
	{
		DUMP_FUNC_NAME();
		return nullptr;
	}
	bool RemoteStorage::GetQuota(int32* pnTotalBytes, int32* puAvailableBytes)
	{
		DUMP_FUNC_NAME();
		*pnTotalBytes = 0x10000000;
		*puAvailableBytes = 0x10000000;
		return false;
	}
	bool RemoteStorage::IsCloudEnabledForAccount()
	{
		DUMP_FUNC_NAME();
		return false;
	}
	bool RemoteStorage::IsCloudEnabledForApp()
	{
		DUMP_FUNC_NAME();
		return false;
	}
	void RemoteStorage::SetCloudEnabledForApp(bool bEnabled)
	{
		DUMP_FUNC_NAME();
	}

	SteamAPICall_t RemoteStorage::UGCDownload(UGCHandle_t hContent)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	bool RemoteStorage::GetUGCDownloadProgress(UGCHandle_t hContent, int32* pnBytesDownloaded, int32* pnBytesExpected)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	bool RemoteStorage::GetUGCDetails(UGCHandle_t hContent, AppId_t* pnAppID, char** ppchName, int32* pnFileSizeInBytes, CSteamID* pSteamIDOwner)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	int32 RemoteStorage::UGCRead(UGCHandle_t hContent, void* pvData, int32 cubDataToRead)
	{
		DUMP_FUNC_NAME();
		return int32();
	}
	int32 RemoteStorage::GetCachedUGCCount()
	{
		DUMP_FUNC_NAME();
		return int32();
	}
	UGCHandle_t RemoteStorage::GetCachedUGCHandle(int32 iCachedContent)
	{
		DUMP_FUNC_NAME();
		return UGCHandle_t();
	}
	SteamAPICall_t RemoteStorage::PublishWorkshopFile(const char* pchFile, const char* pchPreviewFile, AppId_t nConsumerAppId, const char* pchTitle, const char* pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t* pTags, EWorkshopFileType eWorkshopFileType)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	PublishedFileUpdateHandle_t RemoteStorage::CreatePublishedFileUpdateRequest(PublishedFileId_t unPublishedFileId)
	{
		DUMP_FUNC_NAME();
		return PublishedFileUpdateHandle_t();
	}
	bool RemoteStorage::UpdatePublishedFileFile(PublishedFileUpdateHandle_t updateHandle, const char* pchFile)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	bool RemoteStorage::UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t updateHandle, const char* pchPreviewFile)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	bool RemoteStorage::UpdatePublishedFileTitle(PublishedFileUpdateHandle_t updateHandle, const char* pchTitle)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	bool RemoteStorage::UpdatePublishedFileDescription(PublishedFileUpdateHandle_t updateHandle, const char* pchDescription)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	bool RemoteStorage::UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	bool RemoteStorage::UpdatePublishedFileTags(PublishedFileUpdateHandle_t updateHandle, SteamParamStringArray_t* pTags)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	SteamAPICall_t RemoteStorage::CommitPublishedFileUpdate(PublishedFileUpdateHandle_t updateHandle)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::GetPublishedFileDetails(PublishedFileId_t unPublishedFileId)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::DeletePublishedFile(PublishedFileId_t unPublishedFileId)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::EnumerateUserPublishedFiles(uint32 unStartIndex)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::SubscribePublishedFile(PublishedFileId_t unPublishedFileId)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::EnumerateUserSubscribedFiles(uint32 unStartIndex)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::UnsubscribePublishedFile(PublishedFileId_t unPublishedFileId)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	bool RemoteStorage::UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t updateHandle, const char* pchChangeDescription)
	{
		DUMP_FUNC_NAME();
		return false;
	}
	SteamAPICall_t RemoteStorage::GetPublishedItemVoteDetails(PublishedFileId_t unPublishedFileId)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::UpdateUserPublishedItemVote(PublishedFileId_t unPublishedFileId, bool bVoteUp)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::GetUserPublishedItemVoteDetails(PublishedFileId_t unPublishedFileId)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::EnumerateUserSharedWorkshopFiles(CSteamID steamId, uint32 unStartIndex, SteamParamStringArray_t* pRequiredTags, SteamParamStringArray_t* pExcludedTags)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::PublishVideo(EWorkshopVideoProvider eVideoProvider, const char* pchVideoAccount, const char* pchVideoIdentifier, const char* pchPreviewFile, AppId_t nConsumerAppId, const char* pchTitle, const char* pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t* pTags)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::SetUserPublishedFileAction(PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::EnumeratePublishedFilesByUserAction(EWorkshopFileAction eAction, uint32 unStartIndex)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
	SteamAPICall_t RemoteStorage::EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType eEnumerationType, uint32 unStartIndex, uint32 unCount, uint32 unDays, SteamParamStringArray_t* pTags, SteamParamStringArray_t* pUserTags)
	{
		DUMP_FUNC_NAME();
		return SteamAPICall_t();
	}
}

STEAM_IGNORE_WARNINGS_END
