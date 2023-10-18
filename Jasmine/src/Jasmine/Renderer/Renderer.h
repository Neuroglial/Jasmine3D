#pragma once

#include "RenderCommandQueue.h"
#include "RendererAPI.h"

#include "RenderPass.h"

#include "Mesh.h"

namespace Jasmine {

	class ShaderLibrary;

	// TODO: Maybe this should be renamed to RendererAPI? Because we want an actual renderer vs API calls...
	class Renderer
	{
	public:
		typedef void(*RenderCommandFn)(void*);

		// Commands
		static void Clear();
		static void Clear(float r, float g, float b, float a = 1.0f);
		static void SetClearColor(float r, float g, float b, float a);

		static void DrawIndexed(uint32_t count, bool depthTest = true);
		static void ClearMagenta();

		static void Init();

		static const Scope<ShaderLibrary>& GetShaderLibrary() { return Get().m_ShaderLibrary; }

		static void* Submit(RenderCommandFn fn, unsigned int size)
		{
			return s_Instance->m_CommandQueue.Allocate(fn, size);
		}

		void WaitAndRender();

		inline static Renderer& Get() { return *s_Instance; }

		// ~Actual~ Renderer here... TODO: remove confusion later
		static void BeginRenderPass(const Ref<RenderPass>& renderPass) { s_Instance->IBeginRenderPass(renderPass); }
		static void EndRenderPass() { s_Instance->IEndRenderPass(); }

		static void SubmitMesh(const Ref<Mesh>& mesh) { s_Instance->SubmitMeshI(mesh); }
	private:
		void IBeginRenderPass(const Ref<RenderPass>& renderPass);
		void IEndRenderPass();

		void SubmitMeshI(const Ref<Mesh>& mesh);

	private:
		static Renderer* s_Instance;
	private:
		Ref<RenderPass> m_ActiveRenderPass;

		RenderCommandQueue m_CommandQueue;
		Scope<ShaderLibrary> m_ShaderLibrary;
	};

}

#define JM_RENDER_PASTE2(a, b) a ## b
#define JM_RENDER_PASTE(a, b) JM_RENDER_PASTE2(a, b)
#define JM_RENDER_UNIQUE(x) JM_RENDER_PASTE(x, __LINE__)

#define JM_RENDER(code) \
    struct JM_RENDER_UNIQUE(JMRenderCommand) \
    {\
        static void Execute(void*)\
        {\
            code\
        }\
    };\
	{\
		auto mem = ::Jasmine::Renderer::Submit(JM_RENDER_UNIQUE(JMRenderCommand)::Execute, sizeof(JM_RENDER_UNIQUE(JMRenderCommand)));\
		new (mem) JM_RENDER_UNIQUE(JMRenderCommand)();\
	}\

#define JM_RENDER_1(arg0, code) \
	do {\
    struct JM_RENDER_UNIQUE(JMRenderCommand) \
    {\
		JM_RENDER_UNIQUE(JMRenderCommand)(typename ::std::remove_const<typename ::std::remove_reference<decltype(arg0)>::type>::type arg0) \
		: arg0(arg0) {}\
		\
        static void Execute(void* argBuffer)\
        {\
			auto& arg0 = ((JM_RENDER_UNIQUE(JMRenderCommand)*)argBuffer)->arg0;\
            code\
        }\
		\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg0)>::type>::type arg0;\
    };\
	{\
		auto mem = ::Jasmine::Renderer::Submit(JM_RENDER_UNIQUE(JMRenderCommand)::Execute, sizeof(JM_RENDER_UNIQUE(JMRenderCommand)));\
		new (mem) JM_RENDER_UNIQUE(JMRenderCommand)(arg0);\
	} } while(0)

#define JM_RENDER_2(arg0, arg1, code) \
    struct JM_RENDER_UNIQUE(JMRenderCommand) \
    {\
		JM_RENDER_UNIQUE(JMRenderCommand)(typename ::std::remove_const<typename ::std::remove_reference<decltype(arg0)>::type>::type arg0,\
											typename ::std::remove_const<typename ::std::remove_reference<decltype(arg1)>::type>::type arg1) \
		: arg0(arg0), arg1(arg1) {}\
		\
        static void Execute(void* argBuffer)\
        {\
			auto& arg0 = ((JM_RENDER_UNIQUE(JMRenderCommand)*)argBuffer)->arg0;\
			auto& arg1 = ((JM_RENDER_UNIQUE(JMRenderCommand)*)argBuffer)->arg1;\
            code\
        }\
		\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg0)>::type>::type arg0;\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg1)>::type>::type arg1;\
    };\
	{\
		auto mem = ::Jasmine::Renderer::Submit(JM_RENDER_UNIQUE(JMRenderCommand)::Execute, sizeof(JM_RENDER_UNIQUE(JMRenderCommand)));\
		new (mem) JM_RENDER_UNIQUE(JMRenderCommand)(arg0, arg1);\
	}\

#define JM_RENDER_3(arg0, arg1, arg2, code) \
    struct JM_RENDER_UNIQUE(JMRenderCommand) \
    {\
		JM_RENDER_UNIQUE(JMRenderCommand)(typename ::std::remove_const<typename ::std::remove_reference<decltype(arg0)>::type>::type arg0,\
											typename ::std::remove_const<typename ::std::remove_reference<decltype(arg1)>::type>::type arg1,\
											typename ::std::remove_const<typename ::std::remove_reference<decltype(arg2)>::type>::type arg2) \
		: arg0(arg0), arg1(arg1), arg2(arg2) {}\
		\
        static void Execute(void* argBuffer)\
        {\
			auto& arg0 = ((JM_RENDER_UNIQUE(JMRenderCommand)*)argBuffer)->arg0;\
			auto& arg1 = ((JM_RENDER_UNIQUE(JMRenderCommand)*)argBuffer)->arg1;\
			auto& arg2 = ((JM_RENDER_UNIQUE(JMRenderCommand)*)argBuffer)->arg2;\
            code\
        }\
		\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg0)>::type>::type arg0;\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg1)>::type>::type arg1;\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg2)>::type>::type arg2;\
    };\
	{\
		auto mem = ::Jasmine::Renderer::Submit(JM_RENDER_UNIQUE(JMRenderCommand)::Execute, sizeof(JM_RENDER_UNIQUE(JMRenderCommand)));\
		new (mem) JM_RENDER_UNIQUE(JMRenderCommand)(arg0, arg1, arg2);\
	}\

#define JM_RENDER_4(arg0, arg1, arg2, arg3, code) \
    struct JM_RENDER_UNIQUE(JMRenderCommand) \
    {\
		JM_RENDER_UNIQUE(JMRenderCommand)(typename ::std::remove_const<typename ::std::remove_reference<decltype(arg0)>::type>::type arg0,\
											typename ::std::remove_const<typename ::std::remove_reference<decltype(arg1)>::type>::type arg1,\
											typename ::std::remove_const<typename ::std::remove_reference<decltype(arg2)>::type>::type arg2,\
											typename ::std::remove_const<typename ::std::remove_reference<decltype(arg3)>::type>::type arg3)\
		: arg0(arg0), arg1(arg1), arg2(arg2), arg3(arg3) {}\
		\
        static void Execute(void* argBuffer)\
        {\
			auto& arg0 = ((JM_RENDER_UNIQUE(JMRenderCommand)*)argBuffer)->arg0;\
			auto& arg1 = ((JM_RENDER_UNIQUE(JMRenderCommand)*)argBuffer)->arg1;\
			auto& arg2 = ((JM_RENDER_UNIQUE(JMRenderCommand)*)argBuffer)->arg2;\
			auto& arg3 = ((JM_RENDER_UNIQUE(JMRenderCommand)*)argBuffer)->arg3;\
            code\
        }\
		\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg0)>::type>::type arg0;\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg1)>::type>::type arg1;\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg2)>::type>::type arg2;\
		typename ::std::remove_const<typename ::std::remove_reference<decltype(arg3)>::type>::type arg3;\
    };\
	{\
		auto mem = Renderer::Submit(JM_RENDER_UNIQUE(JMRenderCommand)::Execute, sizeof(JM_RENDER_UNIQUE(JMRenderCommand)));\
		new (mem) JM_RENDER_UNIQUE(JMRenderCommand)(arg0, arg1, arg2, arg3);\
	}

#define JM_RENDER_S(code) auto self = this;\
	JM_RENDER_1(self, code)

#define JM_RENDER_S1(arg0, code) auto self = this;\
	JM_RENDER_2(self, arg0, code)

#define JM_RENDER_S2(arg0, arg1, code) auto self = this;\
	JM_RENDER_3(self, arg0, arg1, code)

#define JM_RENDER_S3(arg0, arg1, arg2, code) auto self = this;\
	JM_RENDER_4(self, arg0, arg1, arg2, code)