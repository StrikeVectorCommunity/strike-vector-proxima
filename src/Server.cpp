#include "pch.h"

namespace Proxima
{
	std::vector<std::function<void()>> Server::frameQueue{};

	void Server::RunFrame()
	{
		for (const auto& f : frameQueue)
		{
			f();
		}

		frameQueue.clear();
				
		Steam::callbacks->GetResultsServer()->RunCallResults();
		Steam::callbacks->GetServer()->RunCallbacks();

	}

	void Server::AddToQueue(const std::function<void()>& func)
	{
		frameQueue.push_back(func);
	}
}