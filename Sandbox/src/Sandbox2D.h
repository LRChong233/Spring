#pragma once

#include "Spring.h"

class Sandbox2D : public Spring::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;
	
	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Spring::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Spring::Event& e) override;
private:
	Spring::OrthographicCameraController m_CameraController;

	// Temp
	Spring::Ref<Spring::VertexArray> m_SquareVA;
	Spring::Ref<Spring::Shader> m_FlatColorShader;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };


};