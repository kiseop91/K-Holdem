#include <core_pch.h>
#include <Holdem.h>

Application* Application::s_Instance = nullptr;

Application::Application(std::string name)
{
	s_Instance = this;
	initEvent();

	//m_Scheduler.attach<my_process>(3u);

	//inputSystem.
	/*auto t = m_Scheduler.attach([&](auto delta, void *, auto succeed, auto fail) {
		std::cout << " ------------------------------------------------------- " << std::endl;
		std::cout << " 메뉴 : 1. 손패  2. Call  3. Raise(x2)  4. Check  5. Die " << std::endl;
		std::cout << " ------------------------------------------------------- " << std::endl;

		int menu;
		std::cin >> menu;

		auto view = m_Registry.view<PlayerTag>();
		auto entity = view.back(); 
		switch (menu)
		{
		case 1:
			m_Dispatcher.trigger<HandViewEvent>(entity);
			break;
		case 2:
			m_Dispatcher.trigger<CallEvent>(entity);
			break;
		case 3:
			m_Dispatcher.trigger<RaiseEvent>(entity, (size_t)100);
			break;
		case 4:
			m_Dispatcher.trigger<CheckEvent>(entity);
			break;
		case 5:
			m_Dispatcher.trigger<DieEvent>(entity);
			break;
		default:
			break;
		}
		
	});*/

	 //// 시작 화면 
	 //m_Scheduler.attach([&](auto delta, void *, auto succeed, auto fail) {
		// std::cout << " ----------------------- " << std::endl;
		// std::cout << " Welcome Hold'em World!! " << std::endl;
		// std::cout << " ----------------------- " << std::endl;
		// succeed();
		// m_Dispatcher.trigger<GameStartEvent>();
	 //});
}

Application::~Application()
{
}

entt::dispatcher & Application::GetDispatcher()
{
	return m_Dispatcher;
}

entt::registry & Application::GetRegistry()
{
	return m_Registry;
}

entt::scheduler<std::uint32_t>& Application::GetScheduler()
{
	return m_Scheduler;
}

Application * Application::GetApp()
{
	if (s_Instance == nullptr)
		s_Instance = new Application("new");

	return s_Instance;
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

}

void Application::initEvent()
{
	BoardEventSystem listener;
	m_Dispatcher.sink<GameStartEvent>().connect<&BoardEventSystem::StartGame>(listener);
	m_Dispatcher.sink<GameResultEvent>().connect<&BoardEventSystem::EndGame>(listener);
	m_Dispatcher.sink<CardDrawEvent>().connect<&BoardEventSystem::DrawCard>(listener);

	PlayerEventSystem playerEventSystem;
	m_Dispatcher.sink<HandViewEvent>().connect<&PlayerEventSystem::ViewHand>(playerEventSystem);
	m_Dispatcher.sink<CallEvent>().connect<&PlayerEventSystem::Call>(playerEventSystem);
	m_Dispatcher.sink<CheckEvent>().connect<&PlayerEventSystem::Check>(playerEventSystem);
	m_Dispatcher.sink<RaiseEvent>().connect<&PlayerEventSystem::Raise>(playerEventSystem);
	m_Dispatcher.sink<DieEvent>().connect<&PlayerEventSystem::Die>(playerEventSystem);
	m_Dispatcher.sink<AllinEvent>().connect<&PlayerEventSystem::Allin>(playerEventSystem);
}
