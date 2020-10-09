#pragma once
#include <Event/Event.h>

class PlayerEventSystem {
public:
	void receive(const CallEvent &e);
	void receive(const DieEvent &e);
	void receive(const RaiseEvent &e);
	void receive(const AllinEvent &e);
};