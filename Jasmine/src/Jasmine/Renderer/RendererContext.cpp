#include "JMpch.h"
#include "RendererContext.h"

#include "Jasmine/Renderer/RendererAPI.h"

#include "Jasmine/Platform/OpenGL/OpenGLContext.h"
#include "Jasmine/Platform/Vulkan/VulkanContext.h"

namespace Jasmine {

	Ref<RendererContext> RendererContext::Create(GLFWwindow* windowHandle)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    return nullptr;
			case RendererAPIType::OpenGL:  return Ref<OpenGLContext>::Create(windowHandle);
			case RendererAPIType::Vulkan:  return Ref<VulkanContext>::Create(windowHandle);
		}
		JM_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

}