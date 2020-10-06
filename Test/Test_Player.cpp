#include "pch.h"
#include <vector>
#include "../vendor/entt/entt.hpp"
entt::registry reg;

struct CardComponent
{

};

struct MoneyComponet
{
	MoneyComponet(int _money)
		:money(_money)
	{ }

	int money;
};

struct Player
{
public:
	Player()
	{
		entity = reg.create();
		reg.emplace<MoneyComponet>(entity, 1000);
	}

	int GetMoney()
	{
		auto comp = reg.get<MoneyComponet>(entity);
		return comp.money;
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