#pragma once

#ifdef SP_PLATFORM_WINDOWS

extern Spring::Application* Spring::CreateApplication();

int main()
{
	auto app = Spring::CreateApplication();
	app->Run();
	delete app;
}

#endif