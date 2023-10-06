#pragma once

namespace Steam
{
	struct SteamParamStringArray_t
{
	const char ** m_ppStrings;
	int32 m_nNumStrings;
};

// A handle to a piece of user generated content
typedef uint64 UGCHandle_t;
typedef uint64 PublishedFileUpdateHandle_t;
typedef uint64 PublishedFileId_t;
const PublishedFileId_t k_PublishedFileIdInvalid = 0;
const UGCHandle_t k_UGCHandleInvalid = 0xffffffffffffffffull;
const PublishedFileUpdateHandle_t k_PublishedFileUpdateHandleInvalid = 0xffffffffffffffffull;

// Handle for writing to Steam Cloud
typedef uint64 UGCFileWriteStreamHandle_t;
const UGCFileWriteStreamHandle_t k_UGCFileStreamHandleInvalid = 0xffffffffffffffffull;

const uint32 k_cchPublishedDocumentTitleMax = 128 + 1;
const uint32 k_cchPublishedDocumentDescriptionMax = 8000;
const uint32 k_cchPublishedDocumentChangeDescriptionMax = 8000;
const uint32 k_unEnumeratePublishedFilesMaxResults = 50;
const uint32 k_cchTagListMax = 1024 + 1;
const uint32 k_cchFilenameMax = 260;
const uint32 k_cchPublishedFileURLMax = 256;


enum ERemoteStoragePlatform
{
	k_ERemoteStoragePlatformNone		= 0,
	k_ERemoteStoragePlatformWindows		= (1 << 0),
	k_ERemoteStoragePlatformOSX			= (1 << 1),
	k_ERemoteStoragePlatformPS3			= (1 << 2),
	k_ERemoteStoragePlatformLinux		= (1 << 3),
	k_ERemoteStoragePlatformSwitch		= (1 << 4),
	k_ERemoteStoragePlatformAndroid		= (1 << 5),
	k_ERemoteStoragePlatformIOS			= (1 << 6),
	// NB we get one more before we need to widen some things

	k_ERemoteStoragePlatformAll = 0xffffffff
};

enum ERemoteStoragePublishedFileVisibility
{
	k_ERemoteStoragePublishedFileVisibilityPublic = 0,
	k_ERemoteStoragePublishedFileVisibilityFriendsOnly = 1,
	k_ERemoteStoragePublishedFileVisibilityPrivate = 2,
	k_ERemoteStoragePublishedFileVisibilityUnlisted = 3,
};


enum EWorkshopFileType
{
	k_EWorkshopFileTypeFirst = 0,

	k_EWorkshopFileTypeCommunity			  = 0,		// normal Workshop item that can be subscribed to
	k_EWorkshopFileTypeMicrotransaction		  = 1,		// Workshop item that is meant to be voted on for the purpose of selling in-game
	k_EWorkshopFileTypeCollection			  = 2,		// a collection of Workshop or Greenlight items
	k_EWorkshopFileTypeArt					  = 3,		// artwork
	k_EWorkshopFileTypeVideo				  = 4,		// external video
	k_EWorkshopFileTypeScreenshot			  = 5,		// screenshot
	k_EWorkshopFileTypeGame					  = 6,		// Greenlight game entry
	k_EWorkshopFileTypeSoftware				  = 7,		// Greenlight software entry
	k_EWorkshopFileTypeConcept				  = 8,		// Greenlight concept
	k_EWorkshopFileTypeWebGuide				  = 9,		// Steam web guide
	k_EWorkshopFileTypeIntegratedGuide		  = 10,		// application integrated guide
	k_EWorkshopFileTypeMerch				  = 11,		// Workshop merchandise meant to be voted on for the purpose of being sold
	k_EWorkshopFileTypeControllerBinding	  = 12,		// Steam Controller bindings
	k_EWorkshopFileTypeSteamworksAccessInvite = 13,		// internal
	k_EWorkshopFileTypeSteamVideo			  = 14,		// Steam video
	k_EWorkshopFileTypeGameManagedItem		  = 15,		// managed completely by the game, not the user, and not shown on the web

	// Update k_EWorkshopFileTypeMax if you add values.
	k_EWorkshopFileTypeMax = 16
	
};

enum EWorkshopVote
{
	k_EWorkshopVoteUnvoted = 0,
	k_EWorkshopVoteFor = 1,
	k_EWorkshopVoteAgainst = 2,
	k_EWorkshopVoteLater = 3,
};

enum EWorkshopFileAction
{
	k_EWorkshopFileActionPlayed = 0,
	k_EWorkshopFileActionCompleted = 1,
};

enum EWorkshopEnumerationType
{
	k_EWorkshopEnumerationTypeRankedByVote = 0,
	k_EWorkshopEnumerationTypeRecent = 1,
	k_EWorkshopEnumerationTypeTrending = 2,
	k_EWorkshopEnumerationTypeFavoritesOfFriends = 3,
	k_EWorkshopEnumerationTypeVotedByFriends = 4,
	k_EWorkshopEnumerationTypeContentByFriends = 5,
	k_EWorkshopEnumerationTypeRecentFromFollowedUsers = 6,
};

enum EWorkshopVideoProvider
{
	k_EWorkshopVideoProviderNone = 0,
	k_EWorkshopVideoProviderYoutube = 1
};


enum EUGCReadAction
{
	// Keeps the file handle open unless the last byte is read.  You can use this when reading large files (over 100MB) in sequential chunks.
	// If the last byte is read, this will behave the same as k_EUGCRead_Close.  Otherwise, it behaves the same as k_EUGCRead_ContinueReading.
	// This value maintains the same behavior as before the EUGCReadAction parameter was introduced.
	k_EUGCRead_ContinueReadingUntilFinished = 0,

	// Keeps the file handle open.  Use this when using UGCRead to seek to different parts of the file.
	// When you are done seeking around the file, make a final call with k_EUGCRead_Close to close it.
	k_EUGCRead_ContinueReading = 1,

	// Frees the file handle.  Use this when you're done reading the content.  
	// To read the file from Steam again you will need to call UGCDownload again. 
	k_EUGCRead_Close = 2,	
};



	class RemoteStorage
	{
	public:
		// NOTE
	//
	// Filenames are case-insensitive, and will be converted to lowercase automatically.
	// So "foo.bar" and "Foo.bar" are the same file, and if you write "Foo.bar" then
	// iterate the files, the filename returned will be "foo.bar".
	//

	// file operations
	virtual bool	FileWrite( const char *pchFile, const void *pvData, int32 cubData );
	virtual int32	FileRead( const char *pchFile, void *pvData, int32 cubDataToRead );
	virtual bool	FileForget( const char *pchFile );
	virtual bool	FileDelete( const char *pchFile );
	virtual SteamAPICall_t FileShare( const char *pchFile );
	virtual bool	SetSyncPlatforms( const char *pchFile, ERemoteStoragePlatform eRemoteStoragePlatform );

	// file operations that cause network IO
	virtual UGCFileWriteStreamHandle_t FileWriteStreamOpen( const char *pchFile );
	virtual bool FileWriteStreamWriteChunk( UGCFileWriteStreamHandle_t writeHandle, const void *pvData, int32 cubData );
	virtual bool FileWriteStreamClose( UGCFileWriteStreamHandle_t writeHandle );
	virtual bool FileWriteStreamCancel( UGCFileWriteStreamHandle_t writeHandle );

	// file information
	virtual bool	FileExists( const char *pchFile );
	virtual bool	FilePersisted( const char *pchFile );
	virtual int32	GetFileSize( const char *pchFile );
	virtual int64	GetFileTimestamp( const char *pchFile );
	virtual ERemoteStoragePlatform GetSyncPlatforms( const char *pchFile );

	// iteration
	virtual int32 GetFileCount();
	virtual const char *GetFileNameAndSize( int iFile, int32 *pnFileSizeInBytes );

	// configuration management
	virtual bool GetQuota( int32 *pnTotalBytes, int32 *puAvailableBytes );
	virtual bool IsCloudEnabledForAccount();
	virtual bool IsCloudEnabledForApp();
	virtual void SetCloudEnabledForApp( bool bEnabled );

	// user generated content

	// Downloads a UGC file
	virtual SteamAPICall_t UGCDownload( UGCHandle_t hContent );

	// Gets the amount of data downloaded so far for a piece of content. pnBytesExpected can be 0 if function returns false
	// or if the transfer hasn't started yet, so be careful to check for that before dividing to get a percentage
	virtual bool	GetUGCDownloadProgress( UGCHandle_t hContent, int32 *pnBytesDownloaded, int32 *pnBytesExpected );

	// Gets metadata for a file after it has been downloaded. This is the same metadata given in the RemoteStorageDownloadUGCResult_t call result
	virtual bool	GetUGCDetails( UGCHandle_t hContent, AppId_t *pnAppID, char **ppchName, int32 *pnFileSizeInBytes, CSteamID *pSteamIDOwner );

	// After download, gets the content of the file
	virtual int32	UGCRead( UGCHandle_t hContent, void *pvData, int32 cubDataToRead );

	// Functions to iterate through UGC that has finished downloading but has not yet been read via UGCRead()
	virtual int32	GetCachedUGCCount();
	virtual	UGCHandle_t GetCachedUGCHandle( int32 iCachedContent );

	// publishing UGC
	virtual SteamAPICall_t	PublishWorkshopFile( const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags, EWorkshopFileType eWorkshopFileType );
	virtual PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest( PublishedFileId_t unPublishedFileId );
	virtual bool UpdatePublishedFileFile( PublishedFileUpdateHandle_t updateHandle, const char *pchFile );
	virtual bool UpdatePublishedFilePreviewFile( PublishedFileUpdateHandle_t updateHandle, const char *pchPreviewFile );
	virtual bool UpdatePublishedFileTitle( PublishedFileUpdateHandle_t updateHandle, const char *pchTitle );
	virtual bool UpdatePublishedFileDescription( PublishedFileUpdateHandle_t updateHandle, const char *pchDescription );
	virtual bool UpdatePublishedFileVisibility( PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility );
	virtual bool UpdatePublishedFileTags( PublishedFileUpdateHandle_t updateHandle, SteamParamStringArray_t *pTags );
	virtual SteamAPICall_t	CommitPublishedFileUpdate( PublishedFileUpdateHandle_t updateHandle );
	virtual SteamAPICall_t	GetPublishedFileDetails( PublishedFileId_t unPublishedFileId );
	virtual SteamAPICall_t	DeletePublishedFile( PublishedFileId_t unPublishedFileId );
	// enumerate the files that the current user published with this app
	virtual SteamAPICall_t	EnumerateUserPublishedFiles( uint32 unStartIndex );
	virtual SteamAPICall_t	SubscribePublishedFile( PublishedFileId_t unPublishedFileId );
	virtual SteamAPICall_t	EnumerateUserSubscribedFiles( uint32 unStartIndex );
	virtual SteamAPICall_t	UnsubscribePublishedFile( PublishedFileId_t unPublishedFileId );
	virtual bool UpdatePublishedFileSetChangeDescription( PublishedFileUpdateHandle_t updateHandle, const char *pchChangeDescription );
	virtual SteamAPICall_t	GetPublishedItemVoteDetails( PublishedFileId_t unPublishedFileId );
	virtual SteamAPICall_t	UpdateUserPublishedItemVote( PublishedFileId_t unPublishedFileId, bool bVoteUp );
	virtual SteamAPICall_t	GetUserPublishedItemVoteDetails( PublishedFileId_t unPublishedFileId );
	virtual SteamAPICall_t	EnumerateUserSharedWorkshopFiles( CSteamID steamId, uint32 unStartIndex, SteamParamStringArray_t *pRequiredTags, SteamParamStringArray_t *pExcludedTags );
	virtual SteamAPICall_t	PublishVideo( EWorkshopVideoProvider eVideoProvider, const char *pchVideoAccount, const char *pchVideoIdentifier, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags );
	virtual SteamAPICall_t	SetUserPublishedFileAction( PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction );
	virtual SteamAPICall_t	EnumeratePublishedFilesByUserAction( EWorkshopFileAction eAction, uint32 unStartIndex );
	// this method enumerates the public view of workshop files
	virtual SteamAPICall_t	EnumeratePublishedWorkshopFiles( EWorkshopEnumerationType eEnumerationType, uint32 unStartIndex, uint32 unCount, uint32 unDays, SteamParamStringArray_t *pTags, SteamParamStringArray_t *pUserTags );

	};
}
