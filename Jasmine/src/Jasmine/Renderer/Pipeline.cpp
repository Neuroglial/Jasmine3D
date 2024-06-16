#include "JMpch.h"
#include "Pipeline.h"

#include "Renderer.h"

#include "Jasmine/Platform/OpenGL/OpenGLPipeline.h"

namespace Jasmine {

	Ref<Pipeline> Pipeline::Create(const PipelineSpecification& spec)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    return nullptr;
			case RendererAPIType::OpenGL:  return Ref<OpenGLPipeline>::Create(spec);
		}
		JM_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

}