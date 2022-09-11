#include <Spring.h>

//#include "imgui/imgui.h"

class ExampleLayer : public Spring::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Spring::Input::IsKeyPressed(SP_KEY_TAB))
			SP_TRACE("Tab key is pressed (poll)!");
	}

	//virtual void OnImGuiRender() override
	//{
	//	ImGui::Begin("Text");
	//	ImGui::Text("Hello World!");
	//	ImGui::End();
	//}

	void OnEvent(Spring::Event& event) override
	{
		if (event.GetEventType() == Spring::EventType::KeyPressed)
		{
			Spring::KeyPressedEvent& e = (Spring::KeyPressedEvent&)event;
			if (e.GetKeyCode() == SP_KEY_TAB)
				SP_TRACE("Tab key is pressed (event)!");
			SP_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class Sandbox : public Spring::Application {
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox(){}
};

Spring::Application* Spring::CreateApplication()
{
	return new Sandbox();
}