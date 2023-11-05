#include "JMpch.h"
#include "VulkanRenderPass.h"

namespace Jasmine {

	VulkanRenderPass::VulkanRenderPass(const RenderPassSpecification& spec)
		: m_Specification(spec)
	{
	}

	VulkanRenderPass::~VulkanRenderPass()
	{
	}

}