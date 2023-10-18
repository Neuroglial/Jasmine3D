#include "JMpch.h"
#include "Renderer.h"

#include "Shader.h"

namespace Jasmine {

	Renderer* Renderer::s_Instance = new Renderer();
	RendererAPIType RendererAPI::s_CurrentRendererAPI = RendererAPIType::OpenGL;
	
	void Renderer::Init()
	{
		s_Instance->m_ShaderLibrary = std::make_unique<ShaderLibrary>();
		JM_RENDER({ RendererAPI::Init(); });

		Renderer::GetShaderLibrary()->Load("assets/shaders/JasminePBR_Static.glsl");
		Renderer::GetShaderLibrary()->Load("assets/shaders/JasminePBR_Anim.glsl");
	}

	void Renderer::Clear()
	{
		JM_RENDER({
			RendererAPI::Clear(0.0f, 0.0f, 0.0f, 1.0f);
		});
	}

	void Renderer::Clear(float r, float g, float b, float a)
	{
		JM_RENDER_4(r, g, b, a, {
			RendererAPI::Clear(r, g, b, a);
		});
	}

	void Renderer::ClearMagenta()
	{
		Clear(1, 0, 1);
	}

	void Renderer::SetClearColor(float r, float g, float b, float a)
	{
	}

	void Renderer::DrawIndexed(uint32_t count, bool depthTest)
	{
		JM_RENDER_2(count, depthTest, {
			RendererAPI::DrawIndexed(count, depthTest);
		});
	}

	void Renderer::WaitAndRender()
	{
		s_Instance->m_CommandQueue.Execute();
	}

	void Renderer::IBeginRenderPass(const Ref<RenderPass>& renderPass)
	{
		// TODO: Convert all of this into a render command buffer
		m_ActiveRenderPass = renderPass;

		renderPass->GetSpecification().TargetFramebuffer->Bind();
	}

	void Renderer::IEndRenderPass()
	{
		JM_CORE_ASSERT(m_ActiveRenderPass, "No active render pass! Have you called Renderer::EndRenderPass twice?");
		m_ActiveRenderPass->GetSpecification().TargetFramebuffer->Unbind();
		m_ActiveRenderPass = nullptr;
	}

	void Renderer::SubmitMeshI(const Ref<Mesh>& mesh)
	{

	}

}