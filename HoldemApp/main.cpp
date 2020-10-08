#include <iostream>
#include <Core/EntryPoint.h>

class HoldemApp : public Application
{
public:
	HoldemApp()
		: Application("Test")
	{
	}

	~HoldemApp()
	{
	}
};

Application* CreateApplication()
{
	return new HoldemApp();
}