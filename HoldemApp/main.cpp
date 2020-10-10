#include <iostream>
#include <Holdem.h>
#include <Core/EntryPoint.h>

class HoldemApp : public Application
{
public:
	HoldemApp()
		: Application("Test")
	{
		Run();

	}

	~HoldemApp()
	{

	}
};

Application* CreateApplication()
{
	return new HoldemApp();
}