#include "Application.h"

#include "Spring/Events/ApplicationEvent.h"
#include "Spring/Log.h"

namespace Spring {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}


	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SP_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SP_TRACE(e);
		}

		while (true);
	}
}

