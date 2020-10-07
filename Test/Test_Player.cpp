#include "pch.h"
#include <vector>
#include "../vendor/entt/entt.hpp"
#include "../HoldemCore/Component/Component.h"
entt::registry reg;

struct CardComponent
{

};

struct Player
{
public:
	Player()
	{
		entity = reg.create();
		reg.emplace<MoneyComponent>(entity, 1000);
	}

	int GetMoney()
	{
		auto comp = reg.get<MoneyComponent>(entity);
		return comp.chip;
	}
	entt::entity entity;
};

struct PlayerTest : testing::Test
{
public:
	std::unique_ptr<Player> player;

	PlayerTest()
	{
		player = std::make_unique<Player>();
	}

	~PlayerTest()
	{
	}

};

TEST_F(PlayerTest, GetMoney) {

	EXPECT_EQ(player->GetMoney(), 1000 );
}