#pragma once

#ifdef SP_PLATFORM_WINDOWS

extern Spring::Application* Spring::CreateApplication();

int main()
{
	Spring::Log::Init();
	SP_CORE_WARN("Initialized Log!");
	int a = 5;
	SP_INFO("Hello! Var={0}", a);

	auto app = Spring::CreateApplication();
	app->Run();
	delete app;
}

#endif