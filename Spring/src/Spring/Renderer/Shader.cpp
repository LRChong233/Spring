#include "sppch.h"
#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Spring {

	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: SP_CORE_ASSERT(false, "RendererAPI::None is currently not supprot!"); return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLShader(vertexSrc, fragmentSrc);
		}
		SP_CORE_ASSERT(false, "Unknown RendererAPI!"); 
		return nullptr;
	}

}