#include "JMpch.h"
#include "Material.h"

#include "Jasmine/Platform/Vulkan/VulkanMaterial.h"
#include "Jasmine/Platform/OpenGL/OpenGLMaterial.h"

#include "Jasmine/Renderer/RendererAPI.h"

namespace Jasmine {

	Ref<Material> Material::Create(const Ref<Shader>& shader, const std::string& name)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None: return nullptr;
			case RendererAPIType::Vulkan: return Ref<VulkanMaterial>::Create(shader, name);
			case RendererAPIType::OpenGL: return Ref<OpenGLMaterial>::Create(shader, name);
		}
		JM_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}
	
}