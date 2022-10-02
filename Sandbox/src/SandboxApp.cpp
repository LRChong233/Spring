#include <Spring.h>

#include "imgui/imgui.h"

class ExampleLayer : public Spring::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
	{
		m_VertexArray.reset(Spring::VertexArray::Create());
		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			0.0f, 0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		std::shared_ptr<Spring::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Spring::VertexBuffer::Create(vertices, sizeof(vertices)));
		Spring::BufferLayout layout = {
			{Spring::ShaderDataType::Float3, "a_Position"},
			{Spring::ShaderDataType::Float4, "a_Color"}
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		std::shared_ptr<Spring::IndexBuffer> indexBuffer;
		indexBuffer.reset(Spring::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);	
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader.reset(new Spring::Shader(vertexSrc, fragmentSrc));


		m_SquareVA.reset(Spring::VertexArray::Create());
		float squareVertices[3 * 4] = {
			-0.75f, -0.75f, 0.0f,
			 0.75f, -0.75f, 0.0f,
			 0.75f,  0.75f, 0.0f,
			-0.75f,  0.75f, 0.0f
		};

		std::shared_ptr<Spring::VertexBuffer> squareVB;
		squareVB.reset(Spring::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Spring::ShaderDataType::Float3, "a_Position" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Spring::IndexBuffer> squareIB;
		squareIB.reset(Spring::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string blueShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);	
			}
		)";

		std::string blueShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			void main()
			{
				color = vec4(0.2, 0.3, 0.8, 1.0);
			}
		)";

		m_BlueShader.reset(new Spring::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));
	}

	void OnUpdate(Spring::Timestep ts) override
	{
		if (Spring::Input::IsKeyPressed(SP_KEY_LEFT))
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;
		else if (Spring::Input::IsKeyPressed(SP_KEY_RIGHT))
			m_CameraPosition.x += m_CameraMoveSpeed * ts;

		if (Spring::Input::IsKeyPressed(SP_KEY_UP))
			m_CameraPosition.y += m_CameraMoveSpeed * ts;
		else if (Spring::Input::IsKeyPressed(SP_KEY_DOWN))
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;

		if (Spring::Input::IsKeyPressed(SP_KEY_A))
			m_CameraRotation += m_CameraRotationSpeed * ts;
		else if (Spring::Input::IsKeyPressed(SP_KEY_D))
			m_CameraRotation -= m_CameraRotationSpeed * ts;

		Spring::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Spring::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Spring::Renderer::BeginScene(m_Camera);

		Spring::Renderer::Submit(m_BlueShader, m_SquareVA);
		Spring::Renderer::Submit(m_Shader, m_VertexArray);

		Spring::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
	}

	void OnEvent(Spring::Event& event) override
	{
	}

private:
	std::shared_ptr<Spring::Shader> m_Shader;
	std::shared_ptr<Spring::VertexArray> m_VertexArray;

	std::shared_ptr<Spring::Shader> m_BlueShader;
	std::shared_ptr<Spring::VertexArray> m_SquareVA;

	Spring::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 5.0f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;

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