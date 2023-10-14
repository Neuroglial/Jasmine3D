#include "JMpch.h"

#include "Jasmine/Platform/OpenGL/OpenGLVertexBuffer.h"

namespace Jasmine {

	VertexBuffer* VertexBuffer::Create(unsigned int size)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    return nullptr;
			case RendererAPIType::OpenGL:  return new OpenGLVertexBuffer(size);
		}
		return nullptr;

	}

}