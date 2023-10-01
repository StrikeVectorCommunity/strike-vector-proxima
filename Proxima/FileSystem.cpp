#include "pch.h"

namespace Proxima
{
	const std::filesystem::path FileSystem::REMOTE_STORAGE_DIRECTORY_NAME = "ProximaStorage";

	void FileSystem::CreateRemoteStorageFolder()
	{
		std::filesystem::create_directory(REMOTE_STORAGE_DIRECTORY_NAME);
	}

	bool FileSystem::WriteFileInternal(const std::string& data, const std::filesystem::path& path)
	{
		std::ofstream output(path, std::ios::binary);
		if (output.is_open())
		{
			output.write(data.data(), data.size());
			return true;
		}

		return false;
	}

	std::string FileSystem::ReadFileInternal(const std::filesystem::path& path)
	{
		std::ifstream stream(path, std::ifstream::ate | std::ifstream::binary);
		if (stream.is_open())
		{
			std::stringstream buffer;
			buffer << stream.rdbuf();
			return buffer.str();
		}

		return std::string();
	}
	
	
	std::streamoff FileSystem::GetFileSize(const std::filesystem::path& path)
	{
		std::ifstream stream(path, std::ifstream::ate | std::ifstream::binary);
		if (stream.is_open())
		{
			return stream.tellg();
		}

		return 0;
	}
}