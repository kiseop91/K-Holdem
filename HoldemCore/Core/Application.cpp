#include <core_pch.h>
#include <Holdem.h>

Application* Application::s_Instance = nullptr;

Application::Application(std::string name)
{
	std::cout << "Init Application" << std::endl;
	s_Instance = this;

	//m_Scheduler.attach<my_process>(3u);

	//m_Scheduler.attach([](auto delta, void *, auto succeed, auto fail) {
	//	std::cout << "zz" << std::endl; succeed(); });
}

Application::~Application()
{
}

void Application::Run()
{
	while (true)
	{
		size_t dt = 1;
		m_Scheduler.update(dt);
	}
}



void Application::OnEvent(Event & e)
{
	entt::dispatcher dispatcher;
	BoardSettingSystem listener;
	dispatcher.sink<GameStartEvent>().connect<&BoardSettingSystem::receive>(listener);
	//dispatcher.sink<GameResultEvent>().connect<&listener::method>(e);
	//dispatcher.sink<CallEvent>().connect<&listener::method>(e);
	//dispatcher.sink<RaiseEvent>().connect<&listener::method>(e);
	//dispatcher.sink<DieEvent>().connect<&listener::method>(e);
	//dispatcher.sink<AllinEvent>().connect<&listener::method>(e);
	//dispatcher.sink<CardDrawEvent>().connect<&listener::method>(e);
}
