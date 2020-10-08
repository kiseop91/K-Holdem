#include <core_pch.h>
#include "Application.h"

Application* Application::s_Instance = nullptr;

Application::Application(std::string name)
{
	std::cout << "Init Application" << std::endl;
	s_Instance = this;
}

Application::~Application()
{
}

void Application::Run()
{
}

void Application::OnEvent(Event & e)
{
}
