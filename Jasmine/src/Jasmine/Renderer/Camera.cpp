#include "JMpch.h"
#include "Camera.h"

namespace Jasmine {

	Camera::Camera(const glm::mat4& projectionMatrix)
		: m_ProjectionMatrix(projectionMatrix)
	{
	}

}