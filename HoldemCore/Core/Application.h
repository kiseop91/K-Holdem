
class Event;

class Application
{
public:
	Application();
	virtual ~Application();

	void Run();

	void OnEvent(Event& e);
};