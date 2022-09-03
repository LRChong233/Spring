#include <Spring.h>

class ExampleLayer : public Spring::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		SP_INFO("ExampleLayer::Update");
	}

	void OnEvent(Spring::Event& event) override
	{
		SP_TRACE("{0}", event);
	}

};

class Sandbox : public Spring::Application {
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Spring::ImGuiLayer());
	}
	~Sandbox(){}
};

Spring::Application* Spring::CreateApplication()
{
	return new Sandbox();
}