#include "JMpch.h"
#include "Camera.h"

#include "Jasmine/Core/Input.h"

#include <glfw/glfw3.h>
#include <glm/gtc/quaternion.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

#define M_PI 3.14159f

namespace Jasmine {
	Camera::Camera()
	{
		m_Rotation = glm::vec3(90.0f, 0.0f, 0.0f);
		m_FocalPoint = glm::vec3(0.0f);

		glm::vec3 position = { -5, 5, 5 };
		m_Distance = glm::distance(position, m_FocalPoint);

		m_Yaw = 3.0f * (float)M_PI / 4.0f;
		m_Pitch = M_PI / 4.0f;

		UpdateCameraView();
	}
	Camera::Camera(const glm::mat4& projectionMatrix)
		: m_ProjectionMatrix(projectionMatrix)
	{

		m_Rotation = glm::vec3(90.0f, 0.0f, 0.0f);
		m_FocalPoint = glm::vec3(0.0f);

		glm::vec3 position = { -5, 5, 5 };
		m_Distance = glm::distance(position, m_FocalPoint);

		m_Yaw = 3.0f * (float)M_PI / 4.0f;
		m_Pitch = M_PI / 4.0f;

		UpdateCameraView();
	}

	void Camera::Focus()
	{
	}

	glm::vec2 Camera::PanSpeed() const
	{
		float factor = 0.01;
		float x = std::min(m_ViewportWidth / 1000.0f, 2.4f); // max = 2.4f
		float xFactor = 0.0366f * (x * x) - 0.1778f * x + 0.3021f;

		float y = std::min(m_ViewportHeight / 1000.0f, 2.4f); // max = 2.4f
		float yFactor = 0.0366f * (y * y) - 0.1778f * y + 0.3021f;

		return glm::vec2{ xFactor, yFactor } * factor;
	}

	float Camera::RotationSpeed() const
	{
		return 0.008f;
	}

	float Camera::ZoomSpeed() const
	{
		float distance = m_Distance * 0.8f;
		distance = std::max(distance, 0.0f);
		float speed = distance;
		speed = std::min(speed, 100.0f); // max speed = 100
		return speed;
	}

	void Camera::OnUpdate(Timestep ts)
	{
		const glm::vec2& mouse{ Input::GetMouseX(), Input::GetMouseY() };
		glm::vec2 delta = mouse - m_InitialMousePosition;
		m_InitialMousePosition = mouse;

		if (Input::IsMouseButtonPressed(GLFW_MOUSE_BUTTON_MIDDLE)) {
			if (Input::IsKeyPressed(GLFW_KEY_LEFT_SHIFT))
				MousePan(delta);
			else
				MouseRotate(delta);
		}

		if (Input::IsKeyPressed(GLFW_KEY_UP)) {
			MouseRotate({ 0.0f,0.001f });
		}
		if (Input::IsKeyPressed(GLFW_KEY_DOWN)) {
			MouseRotate({ 0.0f,-0.001f });
		}
		if (Input::IsKeyPressed(GLFW_KEY_LEFT)) {
			MouseRotate({ 0.001f,0.0f });
		}
		if (Input::IsKeyPressed(GLFW_KEY_RIGHT)) {
			MouseRotate({ -0.001f,0.0f });
		}

		UpdateCameraView();
	}

	void Camera::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(JM_BIND_EVENT_FN(Camera::OnMouseScroll));
	}

	void Camera::UpdateCameraView()
	{
		m_Position = CalculatePosition();

		glm::quat orientation = GetOrientation();
		m_Rotation = glm::eulerAngles(orientation) * (180.0f / (float)M_PI);
		m_ViewMatrix = glm::translate(glm::mat4(1.0f), m_Position) * glm::toMat4(orientation);
		m_ViewMatrix = glm::inverse(m_ViewMatrix);
	}

	bool Camera::OnMouseScroll(MouseScrolledEvent& e)
	{

		float delta = e.GetYOffset() * 0.1f;
		MouseZoom(delta);
		return false;
	}

	void Camera::MousePan(const glm::vec2& delta)
	{
		auto speed = PanSpeed();
		//JM_CORE_TRACE("{0}, {1}", speed.x, speed.y);
		m_FocalPoint += -GetRightDirection() * delta.x * speed.x * m_Distance;
		m_FocalPoint += GetUpDirection() * delta.y * speed.y * m_Distance;
	}

	void Camera::MouseRotate(const glm::vec2& delta)
	{
		float yawSign = GetUpDirection().y < 0 ? -1.0f : 1.0f;
		m_Yaw += yawSign * delta.x * RotationSpeed();
		m_Pitch += delta.y * RotationSpeed();
	}

	void Camera::MouseZoom(float delta)
	{
		m_Distance -= delta * ZoomSpeed();
		if (m_Distance < 1.0f)
		{
			m_FocalPoint += GetForwardDirection();
			m_Distance = 1.0f;
		}
	}

	glm::vec3 Camera::GetUpDirection()
	{
		return glm::rotate(GetOrientation(), glm::vec3(0.0f, 1.0f, 0.0f));
	}

	glm::vec3 Camera::GetRightDirection()
	{
		return glm::rotate(GetOrientation(), glm::vec3(1.0f, 0.0f, 0.0f));
	}

	glm::vec3 Camera::GetForwardDirection()
	{
		return glm::rotate(GetOrientation(), glm::vec3(0.0f, 0.0f, -1.0f));
	}

	glm::vec3 Camera::CalculatePosition()
	{
		return m_FocalPoint - GetForwardDirection() * m_Distance;
	}

	glm::quat Camera::GetOrientation() const
	{
		return glm::quat(glm::vec3(-m_Pitch, -m_Yaw, 0.0f));
	}
}