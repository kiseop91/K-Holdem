#pragma once
#include <Event/Event.h>

class BoardEventSystem {
public:

	//게임 시작할 때 보내는 이벤트. 
	void StartGame(const GameStartEvent &e);

	// 게임 결과를 계산하는 이벤트.
	void EndGame(const GameResultEvent &e);

	// 현재 상태 (플롭이냐 턴이냐 리버)에 따라 맞게 카드를 보드에 배치하게하는 이벤트.
	void DrawCard(const CardDrawEvent &e);
};