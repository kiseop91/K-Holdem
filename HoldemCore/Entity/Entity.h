#pragma once
#include <entt/entt.hpp>
#include <Component/Component.h>

class EntityFactory
{
public:
	static entt::entity makeBoardEntity(entt::registry& reg)
	{
		std::cout << " Make Board Entity! " << std::endl;
		entt::entity ent;
		ent = reg.create();
		reg.emplace<BoardTag>(ent);
		reg.emplace<MoneyComponent>(ent, 0);
		reg.emplace<PlayerComponent>(ent, (entt::entity)0);
		reg.emplace<TurnComponent>(ent);
		reg.emplace<HandComponent>(ent);

		return ent;
	}

	static entt::entity makePlayerEntity(entt::registry& reg)
	{
		std::cout << " Make Player Entity! " << std::endl;

		entt::entity ent;
		ent = reg.create();
		reg.emplace<PlayerTag>(ent);
		reg.emplace<MoneyComponent>(ent,0);
		reg.emplace<StateComponent>(ent,false,false,false,false,false);
		reg.emplace<HandComponent>(ent);

		return ent;
	}

	static entt::entity makeDeckEntity(entt::registry& reg)
	{
		std::cout << " Make Deck Entity! " << std::endl;

		entt::entity ent;
		ent = reg.create();
		reg.emplace<DeckTag>(ent);
		reg.emplace<HandComponent>(ent);

		return ent;
	}

};
