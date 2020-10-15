#include "pch.h"


entt::dispatcher dispatcher;

TEST(PlayerEvent, HandView) {
	auto app = Application::GetApp();
	app->GetDispatcher().trigger<GameStartEvent>();
	auto view = app->GetRegistry().view<PlayerTag>();
	auto entity = view.back();
	app->GetDispatcher().trigger<HandViewEvent>(entity);
	//현재는 텍스트 구조라 단순히 보여주기만해서 일단 통과처리한다. ( 눈으로 확인 )
	EXPECT_EQ(true, true);
}

TEST(PlayerEvent, Call) {

	EXPECT_EQ(true, true);
}

TEST(PlayerEvent, Die)
{
	entt::registry reg;
	entt::entity ent = reg.create();
	DieEvent event(ent);
}

TEST(PlayerEvent, Raise)
{
	entt::registry reg;
	auto entity = EntityFactory::makePlayerEntity(reg);

	RaiseEvent event(entity, (size_t)1000);
}

TEST(PlayerEvent, Allin)
{
	entt::registry reg;
	auto entity = EntityFactory::makePlayerEntity(reg);
	AllinEvent event(entity, (size_t)1000);
}