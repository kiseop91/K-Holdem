#pragma once
#include <Event/Event.h>

class BoardEventSystem {
public:
	void receive(const GameStartEvent &e);
	void method(const GameResultEvent &e);
	void method(const CardDrawEvent &e);
};