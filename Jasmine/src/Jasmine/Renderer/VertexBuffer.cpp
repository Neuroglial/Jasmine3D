#include "JMpch.h"
#include "VertexBuffer.h"

#include "Renderer.h"

#include "Jasmine/Platform/OpenGL/OpenGLVertexBuffer.h"
#include "Jasmine/Platform/Vulkan/VulkanVertexBuffer.h"

#include "Jasmine/Renderer/RendererAPI.h"

namespace Jasmine {

	Ref<VertexBuffer> VertexBuffer::Create(void* data, uint32_t size, VertexBufferUsage usage)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    return nullptr;
			case RendererAPIType::OpenGL:  return Ref<OpenGLVertexBuffer>::Create(data, size, usage);
			case RendererAPIType::Vulkan:  return Ref<VulkanVertexBuffer>::Create(data, size, usage);
		}
		JM_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

	Ref<VertexBuffer> VertexBuffer::Create(uint32_t size, VertexBufferUsage usage)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    return nullptr;
			case RendererAPIType::OpenGL:  return Ref<OpenGLVertexBuffer>::Create(size, usage);
			case RendererAPIType::Vulkan:  return Ref<VulkanVertexBuffer>::Create(size, usage);
		}
		JM_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

}