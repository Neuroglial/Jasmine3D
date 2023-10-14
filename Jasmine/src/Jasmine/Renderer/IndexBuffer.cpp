#include "JMpch.h"

#include "Jasmine/Platform/OpenGL/OpenGLIndexBuffer.h"

namespace Jasmine {

	IndexBuffer* IndexBuffer::Create(unsigned int size)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    return nullptr;
			case RendererAPIType::OpenGL:  return new OpenGLIndexBuffer(size);
		}
		return nullptr;

	}

}