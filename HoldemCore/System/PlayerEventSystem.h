#pragma once
#include <Event/Event.h>

class PlayerEventSystem {
public:
	//플레이어 손패확인 
	void ViewHand(const HandViewEvent &e);

	//플레이어 Call 이벤트 콜비용
	void Call(const CallEvent &e);

	//플레이어 Call 이벤트 콜비용
	void Check(const CheckEvent &e);

	//플레이어 Die
	void Die(const DieEvent &e);

	//레이스 이벤트, 레이스비용
	void Raise(const RaiseEvent &e);

	//올인 비용.
	void Allin(const AllinEvent &e);
};