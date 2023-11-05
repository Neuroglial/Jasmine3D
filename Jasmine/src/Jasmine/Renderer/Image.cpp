#include "JMpch.h"
#include "Image.h"

#include "Jasmine/Platform/Vulkan/VulkanImage.h"
#include "Jasmine/Platform/OpenGL/OpenGLImage.h"

#include "Jasmine/Renderer/RendererAPI.h"

namespace Jasmine {

	Ref<Image2D> Image2D::Create(ImageSpecification specification, Buffer buffer)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None: return nullptr;
			case RendererAPIType::OpenGL: return Ref<OpenGLImage2D>::Create(specification, buffer);
			case RendererAPIType::Vulkan: return Ref<VulkanImage2D>::Create(specification);
		}
		JM_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

	Ref<Image2D> Image2D::Create(ImageSpecification specification, const void* data)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None: return nullptr;
			case RendererAPIType::OpenGL: return Ref<OpenGLImage2D>::Create(specification, data);
			case RendererAPIType::Vulkan: return Ref<VulkanImage2D>::Create(specification);
		}
		JM_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

}