#include "core_pch.h"
#include "EventSystem.h"

void PlayerEventSystem::Call(const CallEvent & e) {
	std::cout << e.GetName() << std::endl; 
	e.callMoneny;
}

void PlayerEventSystem::Die(const DieEvent & e) { std::cout << e.GetName() << std::endl; }

void PlayerEventSystem::Raise(const RaiseEvent & e) { std::cout << e.GetName() << std::endl; }

void PlayerEventSystem::Allin(const AllinEvent & e) { std::cout << e.GetName() << std::endl; }
