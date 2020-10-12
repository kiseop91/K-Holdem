#include "core_pch.h"
#include "BoardSettingSystem.h"
#include "Core/Application.h"
#include <System/DeckSystem.h>
#include <Entity/Entity.h>

void BoardEventSystem::StartGame(const GameStartEvent & e) {
	std::cout << e.GetName() << std::endl;
	Application::GetApp()->GetDispatcher().trigger<CallEvent>((size_t)100);
	auto& reg = Application::GetApp()->GetRegistry();

	// 0. 보드를 만든다.
	EntityFactory::makeBoardEntity(reg);

	// 1. 덱을 생성하고, 준비한다. 
	EntityFactory::makeDeckEntity(reg);
	MakeDeck(reg);

	// 2. 플레이어를 생성한다. 
	EntityFactory::makePlayerEntity(reg);
	EntityFactory::makePlayerEntity(reg);

	// 3. 플레이어에게 카드를 나눠준다. 
	auto view = reg.view<PlayerTag, HandComponent>();
	
	for (auto& entity : view)
	{
		auto& hand = view.get<HandComponent>(entity);
		hand.cardList.push_back(DrawDeckCard(reg));
		hand.cardList.push_back(DrawDeckCard(reg));
	}
}


void BoardEventSystem::EndGame(const GameResultEvent & e) { 
	std::cout << e.GetName() << std::endl; 
}

void BoardEventSystem::DrawCard(const CardDrawEvent & e) { 
	std::cout << e.GetName() << std::endl; 
	
}
