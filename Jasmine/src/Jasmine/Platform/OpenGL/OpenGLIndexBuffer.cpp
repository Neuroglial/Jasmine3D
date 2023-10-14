#include "JMpch.h"
#include "OpenGLIndexBuffer.h"

#include <Glad/glad.h>

namespace Jasmine {

	OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int size)
		: m_RendererID(0), m_Size(size)
	{
		JM_RENDER_S({
			glGenBuffers(1, &self->m_RendererID);
		});
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		JM_RENDER_S({
			glDeleteBuffers(1, &self->m_RendererID);
		});
	}

	void OpenGLIndexBuffer::SetData(void* buffer, unsigned int size, unsigned int offset)
	{
		JM_RENDER_S3(buffer, size, offset, {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, self->m_RendererID);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);
		});
	}

	void OpenGLIndexBuffer::Bind() const
	{
		JM_RENDER_S({
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, self->m_RendererID);
		});
	}

}