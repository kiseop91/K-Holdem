#include <iostream>
#include <Holdem.h>
#include "HoldemProcess.h"
#include <Core/EntryPoint.h>

class HoldemApp : public Application
{
public:
	HoldemApp()
		: Application("Test")
	{
		HoldemApp::GetApp()->GetScheduler().attach<RoomProcess>(HoldemApp::GetRegistry(), 2);
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