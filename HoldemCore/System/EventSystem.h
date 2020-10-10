#pragma once
#include <Event/Event.h>

class PlayerEventSystem {
public:
	void Call(const CallEvent &e);
	void Die(const DieEvent &e);
	void Raise(const RaiseEvent &e);
	void Allin(const AllinEvent &e);
};