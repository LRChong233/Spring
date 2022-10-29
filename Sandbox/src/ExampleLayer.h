#pragma once

#include "Spring.h"

class ExampleLayer :public Spring::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Spring::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Spring::Event& e) override;
private:
	Spring::ShaderLibrary m_ShaderLibrary;
	Spring::Ref<Spring::Shader> m_Shader;
	Spring::Ref<Spring::VertexArray> m_VertexArray;

	Spring::Ref<Spring::Shader> m_FlatColorShader;
	Spring::Ref<Spring::VertexArray> m_SquareVA;

	Spring::Ref<Spring::Texture2D> m_Texture, m_ChernoLogoTexture;

	Spring::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};