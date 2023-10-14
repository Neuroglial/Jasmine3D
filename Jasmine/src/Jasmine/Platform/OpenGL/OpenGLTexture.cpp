#include "JMpch.h"
#include "OpenGLTexture.h"

#include "Jasmine/Renderer/RendererAPI.h"
#include "Jasmine/Renderer/Renderer.h"

#include <Glad/glad.h>

namespace Jasmine {

	static GLenum JasmineToOpenGLTextureFormat(TextureFormat format)
	{
		switch (format)
		{
			case Jasmine::TextureFormat::RGB:     return GL_RGB;
			case Jasmine::TextureFormat::RGBA:    return GL_RGBA;
		}
		return 0;
	}

	OpenGLTexture2D::OpenGLTexture2D(TextureFormat format, unsigned int width, unsigned int height)
		: m_Format(format), m_Width(width), m_Height(height)
	{
		auto self = this;
		JM_RENDER_1(self, {
			glGenTextures(1, &self->m_RendererID);
			glBindTexture(GL_TEXTURE_2D, self->m_RendererID);
			glTexImage2D(GL_TEXTURE_2D, 0, JasmineToOpenGLTextureFormat(self->m_Format), self->m_Width, self->m_Height, 0, JasmineToOpenGLTextureFormat(self->m_Format), GL_UNSIGNED_BYTE, nullptr);
			glBindTexture(GL_TEXTURE_2D, 0);
		});
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		auto self = this;
		JM_RENDER_1(self, {
			glDeleteTextures(1, &self->m_RendererID);
		});
	}

}