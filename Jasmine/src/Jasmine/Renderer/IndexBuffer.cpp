#include "JMpch.h"
#include "IndexBuffer.h"

#include "Renderer.h"

#include "Jasmine/Platform/OpenGL/OpenGLIndexBuffer.h"

namespace Jasmine {

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t size)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    return nullptr;
			case RendererAPIType::OpenGL:  return Ref<OpenGLIndexBuffer>::Create(size);
		}
		JM_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(void* data, uint32_t size)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    return nullptr;
			case RendererAPIType::OpenGL:  return Ref<OpenGLIndexBuffer>::Create(data, size);
		}
		JM_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

}