#include "core_pch.h"
#include "EventSystem.h"

void PlayerEventSystem::receive(const CallEvent & e) { /* ... */ }

void PlayerEventSystem::method(const DieEvent & e) { /* ... */ }

inline void PlayerEventSystem::method(const RaiseEvent & e) { /* ... */ }

void PlayerEventSystem::method(const AllinEvent & e) { /* ... */ }
