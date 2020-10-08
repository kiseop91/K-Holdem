
class Event;

int main(int argc, char** argv);

class Application
{
public:
	Application(std::string name);
	virtual ~Application();

	void Run();

	void OnEvent(Event& e);

private:
	static Application* s_Instance;
	friend int ::main(int argc, char** argv);
};


Application* CreateApplication();

