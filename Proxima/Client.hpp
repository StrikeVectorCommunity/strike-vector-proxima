#pragma once

namespace Proxima
{
	class Client
	{
	public:
		static void Initialize();
		static void RunFrame();
		static void AddToQueue(const std::function<void()>& func);

	private:
		static std::vector<std::function<void()>> frameQueue;
	};
}