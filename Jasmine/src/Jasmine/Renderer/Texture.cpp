#include "JMpch.h"
#include "Texture.h"

#include "Jasmine/Renderer/RendererAPI.h"
#include "Jasmine/Platform/OpenGL/OpenGLTexture.h"

namespace Jasmine {

	Texture2D* Texture2D::Create(TextureFormat format, unsigned int width, unsigned int height)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None: return nullptr;
			case RendererAPIType::OpenGL: return new OpenGLTexture2D(format, width, height);
		}
		return nullptr;
	}

}