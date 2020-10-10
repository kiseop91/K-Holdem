#include <core_pch.h>
#include <Holdem.h>

Application* Application::s_Instance = nullptr;

Application::Application(std::string name)
{
	s_Instance = this;

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
	 m_Scheduler.attach([](auto delta, void *, auto succeed, auto fail) {
		 //카드 확인.
		 std::cout << " ------------------------------------------------------- " << std::endl;
		 std::cout << " 메뉴 : 1. 손패  2. Call  3. Raise(x2)  4. Check  5. Die " << std::endl;
		 std::cout << " ------------------------------------------------------- " << std::endl;
		 succeed();
	 });

}

Application::~Application()
{
}

entt::dispatcher & Application::GetDispatcher()
{
	return m_Dispatcher;
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
