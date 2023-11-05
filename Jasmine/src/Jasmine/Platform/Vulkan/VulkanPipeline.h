#pragma once

#include "Jasmine/Renderer/Pipeline.h"

#include "Vulkan.h"
#include "VulkanShader.h"
#include <map>

namespace Jasmine {

	class VulkanPipeline : public Pipeline
	{
	public:
		VulkanPipeline(const PipelineSpecification& spec);
		virtual ~VulkanPipeline();

		virtual PipelineSpecification& GetSpecification() { return m_Specification; }
		virtual const PipelineSpecification& GetSpecification() const { return m_Specification; }

		virtual void Invalidate() override;
		virtual void SetUniformBuffer(Ref<UniformBuffer> uniformBuffer, uint32_t binding, uint32_t set = 0) override;

		virtual void Bind() override;

		VkPipeline GetVulkanPipeline() { return m_VulkanPipeline; }
		VkPipelineLayout GetVulkanPipelineLayout() { return m_PipelineLayout; }
		VkDescriptorSet GetDescriptorSet(uint32_t set = 0)
		{
			JM_CORE_ASSERT(m_DescriptorSets.DescriptorSets.size() > set);
			return m_DescriptorSets.DescriptorSets[set];
		}

		const std::vector<VkDescriptorSet>& GetDescriptorSets() const { return m_DescriptorSets.DescriptorSets;	}

		void RT_SetUniformBuffer(Ref<UniformBuffer> uniformBuffer, uint32_t binding, uint32_t set = 0);
	private:
		PipelineSpecification m_Specification;

		VkPipelineLayout m_PipelineLayout;
		VkPipeline m_VulkanPipeline;
		VulkanShader::ShaderMaterialDescriptorSet m_DescriptorSets;
	};

}
