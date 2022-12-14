#include "sppch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace Spring {

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case Spring::ShaderDataType::Float:    return GL_FLOAT;
		case Spring::ShaderDataType::Float2:   return GL_FLOAT;
		case Spring::ShaderDataType::Float3:   return GL_FLOAT;
		case Spring::ShaderDataType::Float4:   return GL_FLOAT;
		case Spring::ShaderDataType::Mat3:     return GL_FLOAT;
		case Spring::ShaderDataType::Mat4:     return GL_FLOAT;
		case Spring::ShaderDataType::Int:      return GL_INT;
		case Spring::ShaderDataType::Int2:     return GL_INT;
		case Spring::ShaderDataType::Int3:     return GL_INT;
		case Spring::ShaderDataType::Int4:     return GL_INT;
		case Spring::ShaderDataType::Bool:     return GL_BOOL;
		}

		SP_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		SP_PROFILE_FUNCTION();

		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		SP_PROFILE_FUNCTION();

		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		SP_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		SP_PROFILE_FUNCTION();

		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
	{
		SP_PROFILE_FUNCTION();

		SP_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");

		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();

		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(
				index,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);
			index++;
		}
		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		SP_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}

}