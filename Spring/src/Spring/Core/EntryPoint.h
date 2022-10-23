#pragma once

#ifdef SP_PLATFORM_WINDOWS

extern Spring::Application* Spring::CreateApplication();

int main()
{
	Spring::Log::Init();

	SP_PROFILE_BEGIN_SESSION("Startup", "SpringProfile-Startup.json");
	auto app = Spring::CreateApplication();
	SP_PROFILE_END_SESSION();

	SP_PROFILE_BEGIN_SESSION("Runtime", "SpringProfile-Runtime.json");
	app->Run();
	SP_PROFILE_END_SESSION();

	SP_PROFILE_BEGIN_SESSION("Startup", "SpringProfile-Shutdown.json");
	delete app;
	SP_PROFILE_END_SESSION();
}

#endif