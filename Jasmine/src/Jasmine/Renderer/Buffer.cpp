#include "JMpch.h"

#include "Jasmine/Platform/OpenGL/OpenGLBuffer.h"

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