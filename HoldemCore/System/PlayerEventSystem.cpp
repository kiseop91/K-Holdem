#include "core_pch.h"
#include "PlayerEventSystem.h"
#include <Core/Application.h>
#include <Component/Component.h>

void PlayerEventSystem::ViewHand(const HandViewEvent & e)
{
	std::cout << (int)e.id << " Player의 " << e.GetName() << " 이벤트가 발송되었습니다. " << std::endl;
	auto& reg = Application::GetApp()->GetRegistry();
	const auto& hand = reg.get<HandComponent>(e.id);
	
	for (const auto card : hand.cardList)
		std::cout << (int)card << "  ";
	std::cout << std::endl;
}

void PlayerEventSystem::Call(const CallEvent & e) {
	std::cout << (int)e.id<<" Player의 "<<e.GetName()<< " 이벤트가 발송되었습니다. " << std::endl; 
	//  동작을 생각해보자..
	//  보드에 셋팅된 배팅머니를 보고 가져온다. 
	//  그리고 그 돈을 보드에 던져넣는다.
	//  플레이어는 콜한만큼 돈이 빠져나가고
	//  보드에는 콜머니가 쌓인다. 
	auto& reg = Application::GetApp()->GetRegistry();
	auto view = reg.view<BoardTag>();
	int betMoney = 0;
	for (const auto& ent : view)
	{
		betMoney = reg.get<BettingMoneyComponent>(ent).money;
		reg.get<MoneyComponent>(ent).chip += betMoney;
	}

	reg.get<MoneyComponent>(e.id).chip -= betMoney;
}

void PlayerEventSystem::Check(const CheckEvent & e) {
	std::cout << (int)e.id << " Player의 " << e.GetName() << " 이벤트가 발송되었습니다. " << std::endl;
	auto& reg = Application::GetApp()->GetRegistry();
}

void PlayerEventSystem::Die(const DieEvent & e) {
	std::cout << (int)e.id << " Player의 " << e.GetName() << " 이벤트가 발송되었습니다. " << std::endl;
	auto& reg = Application::GetApp()->GetRegistry();


}

void PlayerEventSystem::Raise(const RaiseEvent & e) { 
	std::cout << (int)e.id << " Player의 " << e.GetName() << " 이벤트가 발송되었습니다. " << std::endl;
	auto& reg = Application::GetApp()->GetRegistry();

}

void PlayerEventSystem::Allin(const AllinEvent & e) {
	std::cout << (int)e.id << " Player의 " << e.GetName() << " 이벤트가 발송되었습니다. " << std::endl;
	auto& reg = Application::GetApp()->GetRegistry();

}
