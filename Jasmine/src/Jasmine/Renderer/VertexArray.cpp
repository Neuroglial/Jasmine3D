#include "JMpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Jasmine/Platform/OpenGL/OpenGLVertexArray.h"

namespace Jasmine {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    JM_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPIType::OpenGL:  return Ref<OpenGLVertexArray>::Create();
		}

		JM_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

}
