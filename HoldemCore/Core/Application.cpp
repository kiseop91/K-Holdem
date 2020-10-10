#include <core_pch.h>
#include <Holdem.h>

Application* Application::s_Instance = nullptr;

Application::Application(std::string name)
{
	s_Instance = this;
	initEvent();

	//m_Scheduler.attach<my_process>(3u);

	// 시작 화면 
	 m_Scheduler.attach([](auto delta, void *, auto succeed, auto fail) {
		std::cout << " ----------------------- " << std::endl;
		std::cout << " Welcome Hold'em World!! " << std::endl;
		std::cout << " ----------------------- " << std::endl;
		succeed();
	});

	 // 카드분배 시작

	//inputSystem.
	 auto t = m_Scheduler.attach([&](auto delta, void *, auto succeed, auto fail) {
		 //카드 확인.
		 std::cout << " ------------------------------------------------------- " << std::endl;
		 std::cout << " 메뉴 : 1. 손패  2. Call  3. Raise(x2)  4. Check  5. Die " << std::endl;
		 std::cout << " ------------------------------------------------------- " << std::endl;
		 succeed();
		 int a;
		 std::cin >> a;
		 m_Dispatcher.trigger<CallEvent>((size_t)1);
		 m_Dispatcher.trigger<GameStartEvent>();
		 EntityFactory::makeBoardEntity(m_Registry);
	 });

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
	m_Dispatcher.sink<CallEvent>().connect<&PlayerEventSystem::Call>(playerEventSystem);
	m_Dispatcher.sink<RaiseEvent>().connect<&PlayerEventSystem::Raise>(playerEventSystem);
	m_Dispatcher.sink<DieEvent>().connect<&PlayerEventSystem::Die>(playerEventSystem);
	m_Dispatcher.sink<AllinEvent>().connect<&PlayerEventSystem::Allin>(playerEventSystem);
}
