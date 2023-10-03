#include "pch.h"

namespace Proxima
{
	const std::filesystem::path FileSystem::BASE_PATH = "Proxima";
	const std::filesystem::path FileSystem::STATS_DIRECTORY_NAME = BASE_PATH / "Stats";
	const std::filesystem::path FileSystem::STATS_SERVER_FILENAME = STATS_DIRECTORY_NAME / "Server.txt";
	const std::filesystem::path FileSystem::STATS_USER_FILENAME = STATS_DIRECTORY_NAME / "User.txt";

	const std::filesystem::path FileSystem::REMOTE_STORAGE_DIRECTORY_NAME = BASE_PATH / "Storage";

	bool FileSystem::ReadStats(StatsCategory channel, std::map<std::string, float> out)
	{
		CreateStatsFolder();

		const std::string buff = ReadFileInternal(channel == StatsCategory::GameServer ? STATS_SERVER_FILENAME : STATS_USER_FILENAME);

		if (buff.empty())
		{
			return false;
		}

		out.clear();

		 std::istringstream f(buff);
		 {
			std::string line;    
			while (std::getline(f, line)) {
				if (line.starts_with("#"))
				{
					continue;
				}

				int pos = line.find_first_of("=");
				if (pos != std::string::npos)
				{
					const std::string key = line.substr(0, pos);
					const std::string value = line.substr(pos+1);

					float floatValue = std::stof(value);

					out[key] = floatValue;
				}
			}
		 }

		// TODO: JSON ?
		return true;
	}

	bool FileSystem::WriteStats(StatsCategory channel, std::map<std::string, float> in)
	{
		CreateStatsFolder();
		
		std::ostringstream output{};

		for(const auto& kv: in)
		{
			output << std::format("{}={}", kv.first, kv.second) << "\n";
		}

		return WriteFileInternal(output.str(), channel == StatsCategory::GameServer ? STATS_SERVER_FILENAME : STATS_USER_FILENAME);
	}

	void FileSystem::CreateStatsFolder()
	{
		std::filesystem::create_directory(BASE_PATH);
		std::filesystem::create_directory(STATS_DIRECTORY_NAME);
	}

	void FileSystem::CreateRemoteStorageFolder()
	{
		std::filesystem::create_directory(BASE_PATH);
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
		std::ifstream stream(path, std::ifstream::binary);
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