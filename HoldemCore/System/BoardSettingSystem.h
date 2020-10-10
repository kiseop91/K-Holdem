#pragma once
#include <Event/Event.h>

class BoardEventSystem {
public:
	void StartGame(const GameStartEvent &e);
	void EndGame(const GameResultEvent &e);
	void DrawCard(const CardDrawEvent &e);
};