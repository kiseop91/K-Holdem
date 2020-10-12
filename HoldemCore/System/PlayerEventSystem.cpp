#include "core_pch.h"
#include "PlayerEventSystem.h"
#include <Core/Application.h>
#include <Component/Component.h>

void PlayerEventSystem::ViewHand(const HandViewEvent & e)
{
	std::cout << e.GetName() << " 이벤트가 발송되었습니다. " << std::endl;
	auto& reg = Application::GetApp()->GetRegistry();
	const auto& hand = reg.get<HandComponent>(e.entity);
	
	for (const auto card : hand.cardList)
		std::cout << (int)card << "  ";
	std::cout << std::endl;
}

void PlayerEventSystem::Call(const CallEvent & e) {
	std::cout << e.GetName()<< " 이벤트가 발송되었습니다. " << std::endl; 
	e.callMoneny;
}

void PlayerEventSystem::Die(const DieEvent & e) { std::cout << e.GetName() << std::endl; }

void PlayerEventSystem::Raise(const RaiseEvent & e) { std::cout << e.GetName() << std::endl; }

void PlayerEventSystem::Allin(const AllinEvent & e) { std::cout << e.GetName() << std::endl; }
