#include <Spring.h>
#include <Spring/Core/EntryPoint.h>

#include "Sandbox2D.h"

class Sandbox : public Spring::Application {
public:
	Sandbox()
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}
	~Sandbox(){}
};

Spring::Application* Spring::CreateApplication()
{
	return new Sandbox();
}