#include "core_pch.h"
#include "BoardSettingSystem.h"
#include "Core/Application.h"

void BoardEventSystem::StartGame(const GameStartEvent & e) {
	std::cout << e.GetName() << std::endl;
	Application::GetApp()->GetDispatcher().trigger<CallEvent>((size_t)100);

	//게임 시작 이벤트
	// 1. 덱을 생성하고, 준비한다. 
	// 2. 플레이어를 생성한다. 
	// 3. 플레이어에게 카드를 나눠준다. 
}


void BoardEventSystem::EndGame(const GameResultEvent & e) { 
	std::cout << e.GetName() << std::endl; 
}

void BoardEventSystem::DrawCard(const CardDrawEvent & e) { 
	std::cout << e.GetName() << std::endl; 
	
}
