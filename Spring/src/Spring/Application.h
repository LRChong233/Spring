#pragma once

#include "Core.h"

#include "Window.h"
#include "Spring/LayerStack.h"
#include "Spring/Events/Event.h"
#include "Spring/Events/ApplicationEvent.h"

#include "Spring/ImGui/ImGuiLayer.h"

#include "Spring/Renderer/Shader.h"
#include "Spring/Renderer/Buffer.h"
#include "Spring/Renderer/VertexArray.h"

namespace Spring {

	class SPRING_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}



