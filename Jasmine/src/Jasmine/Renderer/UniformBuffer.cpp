#include "JMpch.h"
#include "UniformBuffer.h"

#include "Jasmine/Renderer/Renderer.h"

#include "Jasmine/Platform/OpenGL/OpenGLUniformBuffer.h"
#include "Jasmine/Platform/Vulkan/VulkanUniformBuffer.h"

#include "Jasmine/Renderer/RendererAPI.h"

namespace Jasmine {

	Ref<UniformBuffer> UniformBuffer::Create(uint32_t size, uint32_t binding)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:     return nullptr;
			case RendererAPIType::Vulkan:  return Ref<VulkanUniformBuffer>::Create(size, binding);
			case RendererAPIType::OpenGL:  return Ref<OpenGLUniformBuffer>::Create(size, binding);
		}

		JM_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
