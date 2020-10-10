#include "pch.h"


entt::dispatcher dispatcher;
struct MockPlayerEventSystem
{
	bool Call(const CallEvent &e)
	{
		if(e.callMoneny == 1000)
			return true;
		else return false;
	}

	bool Die(const CallEvent &e)
	{
		if (e.callMoneny == 1000)
			return true;
		else return false;
	}

	bool Raise(const CallEvent &e)
	{
		if (e.callMoneny == 1000)
			return true;
		else return false;
	}

	bool Allin(const CallEvent &e)
	{
		if (e.callMoneny == 1000)
			return true;
		else return false;
	}
};


TEST(PlayerEvent, Call) {

	MockPlayerEventSystem system;
	dispatcher.sink<CallEvent>().connect<&MockPlayerEventSystem::Call>(system);
	dispatcher.trigger<CallEvent>(static_cast<size_t>(9876));

	CallEvent event(1000);
	auto btest = system.Call(event);

	EXPECT_EQ(btest, true);
}

TEST(PlayerEvent, Die)
{
	entt::registry reg;

	MockPlayerEventSystem system;
	dispatcher.sink<CallEvent>().connect<&MockPlayerEventSystem::Call>(system);
	dispatcher.trigger<CallEvent>(static_cast<size_t>(9876));
	entt::entity ent = reg.create();
	DieEvent event(ent);
}

TEST(PlayerEvent, Raise)
{
	MockPlayerEventSystem system;
	dispatcher.sink<CallEvent>().connect<&MockPlayerEventSystem::Call>(system);
	dispatcher.trigger<CallEvent>(static_cast<size_t>(9876));


	RaiseEvent event((size_t)1000);
}

TEST(PlayerEvent, Allin)
{
	MockPlayerEventSystem system;
	dispatcher.sink<CallEvent>().connect<&MockPlayerEventSystem::Call>(system);
	dispatcher.trigger<CallEvent>(static_cast<size_t>(9876));

	AllinEvent event((size_t)1000);

}