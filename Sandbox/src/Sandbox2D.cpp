#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Platform/OpenGL/OpenGLShader.h"

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.f/720.f)
{
}

void Sandbox2D::OnAttach()
{
	SP_PROFILE_FUNCTION();

	m_CheckerboardTexture = Spring::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	SP_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Spring::Timestep ts)
{
	SP_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	{
		SP_PROFILE_SCOPE("Renderer Prep");
		Spring::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Spring::RenderCommand::Clear();
	}

	{
		SP_PROFILE_SCOPE("Renderer Draw");
		Spring::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Spring::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Spring::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Spring::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
		Spring::Renderer::EndScene();
	}

}

void Sandbox2D::OnImGuiRender()
{
	SP_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

	ImGui::End();
}

void Sandbox2D::OnEvent(Spring::Event& e)
{
	m_CameraController.OnEvent(e);
}
