#include "JMpch.h"
#include "OpenGLContext.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "Jasmine/Core/Log.h"

namespace Jasmine {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
	}

	OpenGLContext::~OpenGLContext()
	{
	}

	void OpenGLContext::Create()
	{
		JM_CORE_INFO("OpenGLContext::Create");

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		JM_CORE_ASSERT(status, "Failed to initialize Glad!");

		JM_CORE_INFO("OpenGL Info:");
		JM_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		JM_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		JM_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

#ifdef JM_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		JM_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Jasmine requires at least OpenGL version 4.5!");
#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}