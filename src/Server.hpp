#pragma once
namespace Proxima
{
	class Server
	{
	public:
		static void RunFrame();
		static void AddToQueue(const std::function<void()>& func);

	private:
		static std::vector<std::function<void()>> frameQueue;
	};
}
