#pragma once
#include <entt/entt.hpp>

class Event;

int main(int argc, char** argv);

struct my_process : entt::process<my_process, std::uint32_t> {
	using delta_type = std::uint32_t;

	my_process(delta_type delay)
		: remaining{ delay }
	{}

	void update(delta_type delta, void *) {
		remaining -= std::min(remaining, delta);
		std::cout << "Running Proccess" << std::endl;
		// ...

		if (!remaining) {
			succeed();
		}
	}

private:
	delta_type remaining;
};

class Application
{
public:
	Application(std::string name);
	virtual ~Application();

	void Run();

	void OnEvent(Event& e);

private:
	entt::scheduler<std::uint32_t> m_Scheduler;

	static Application* s_Instance;
	friend int ::main(int argc, char** argv);
};


Application* CreateApplication();

