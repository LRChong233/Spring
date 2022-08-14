#pragma once

#include "Core.h"

namespace Spring {

	class SPRING_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}



