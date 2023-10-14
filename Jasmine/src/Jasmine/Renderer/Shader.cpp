#include "JMpch.h"
#include "Shader.h"

#include "Jasmine/Platform/OpenGL/OpenGLShader.h"

namespace Jasmine {

	Shader* Shader::Create(const std::string& filepath)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None: return nullptr;
			case RendererAPIType::OpenGL: return new OpenGLShader(filepath);
		}
		return nullptr;
	}

}