#include "core_pch.h"
#include "BoardSettingSystem.h"
#include "Core/Application.h"

void BoardEventSystem::StartGame(const GameStartEvent & e) {
	std::cout << e.GetName() << std::endl;
	Application::GetApp()->GetDispatcher().trigger<CallEvent>((size_t)100);
}

void BoardEventSystem::EndGame(const GameResultEvent & e) { 
	std::cout << e.GetName() << std::endl; 
}

void BoardEventSystem::DrawCard(const CardDrawEvent & e) { 
	std::cout << e.GetName() << std::endl; 

}
