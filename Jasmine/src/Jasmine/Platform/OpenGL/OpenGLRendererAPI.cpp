#include "JMpch.h"
#include "Jasmine/Renderer/RendererAPI.h"

#include <Glad/glad.h>

namespace Jasmine {

	static void OpenGLLogMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
	{
		if (severity != GL_DEBUG_SEVERITY_NOTIFICATION)
		{
			JM_CORE_ERROR("{0}", message);
			JM_CORE_ASSERT(false, "");
		}
		else
		{
			JM_CORE_TRACE("{0}", message);
		}
	}

	void RendererAPI::Init()
	{
		glDebugMessageCallback(OpenGLLogMessage, nullptr);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);

		unsigned int vao;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glEnable(GL_DEPTH_TEST);
		//glEnable(GL_CULL_FACE);
		glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
		glFrontFace(GL_CCW);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		auto& caps = RendererAPI::GetCapabilities();

		caps.Vendor = (const char*)glGetString(GL_VENDOR);
		caps.Renderer = (const char*)glGetString(GL_RENDERER);
		caps.Version = (const char*)glGetString(GL_VERSION);

		glGetIntegerv(GL_MAX_SAMPLES, &caps.MaxSamples);
		glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY, &caps.MaxAnisotropy);

		GLenum error = glGetError();
		while (error != GL_NO_ERROR)
		{
			JM_CORE_ERROR("OpenGL Error {0}", error);
			error = glGetError();
		}
	}

	void RendererAPI::Shutdown()
	{
	}

	void RendererAPI::Clear(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void RendererAPI::SetClearColor(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
	}

	void RendererAPI::DrawIndexed(unsigned int count, bool depthTest)
	{
		if (!depthTest)
			glDisable(GL_DEPTH_TEST);

		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);

		if (!depthTest)
			glEnable(GL_DEPTH_TEST);
	}

}