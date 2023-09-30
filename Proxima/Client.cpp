#include "pch.h"

namespace Proxima
{
	std::vector<std::function<void()>> Client::frameQueue{};

	void Client::RunFrame()
	{
		for (const auto& f : frameQueue)
		{
			f();
		}

		frameQueue.clear();
	}

	void Client::AddToQueue(const std::function<void()>& func)
	{
		frameQueue.push_back(func);
	}

	void Client::Initialize()
	{
		//Logger::Print("Client initialized\n");
	}
}