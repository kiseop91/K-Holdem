#pragma once
#include <iostream>
#include <Holdem.h>

class RoomProperty
{

};


class RoomProcess : public entt::process<RoomProcess, std::uint32_t> {

public:
//	template<class ...Args>
	RoomProcess(entt::registry& _reg, int _playerNumber);

	void update(std::uint32_t dt, void *) {

		std::cout << " ------------------------------------------------------- " << std::endl;
		std::cout << " 메뉴 : 1. 손패  2. Call  3. Raise(x2)  4. Check  5. Die " << std::endl;
		std::cout << " ------------------------------------------------------- " << std::endl;

		int menu;
		std::cin >> menu;

		auto view = m_Registry.view<PlayerTag>();
		auto entity = view.back();
		auto& dispatcher = Application::GetApp()->GetDispatcher();
		switch (menu)
		{
		case 1:
			dispatcher.trigger<HandViewEvent>(entity);
			break;
		case 2:
			dispatcher.trigger<CallEvent>(entity);
			break;
		case 3:
			dispatcher.trigger<RaiseEvent>(entity, (size_t)100);
			break;
		case 4:
			dispatcher.trigger<CheckEvent>(entity);
			break;
		case 5:
			dispatcher.trigger<DieEvent>(entity);
			break;
		default:
			break;
		}
	}
private:
	void initialize();
	void initPlayer();
	void initDeck();
private:
	entt::registry& m_Registry;
	int m_PlayerNumber;
	std::vector<RoomProperty> m_Property;
};