#pragma once

#include <glm/glm.hpp>

#include "Jasmine/Renderer/Texture.h"
#include "Jasmine/Renderer/Mesh.h"
#include "Jasmine/Renderer/Camera.h"

namespace Jasmine {

	struct TagComponent
	{
		std::string Tag;

		operator std::string& () { return Tag; }
		operator const std::string& () const { return Tag; }
	};

	struct TransformComponent
	{
		glm::mat4 Transform;

		operator glm::mat4& () { return Transform; }
		operator const glm::mat4& () const { return Transform; }
	};

	struct MeshComponent
	{
		Ref<Jasmine::Mesh> Mesh;

		operator Ref<Jasmine::Mesh>() { return Mesh; }
	};

	struct ScriptComponent
	{
		// TODO: C# script
		std::string ModuleName;
	};

	struct CameraComponent
	{
		//OrthographicCamera Camera;
		Jasmine::Camera Camera;
		bool Primary = true;

		operator Jasmine::Camera& () { return Camera; }
		operator const Jasmine::Camera& () const { return Camera; }
	};

	struct SpriteRendererComponent
	{
		glm::vec4 Color = { 1.0f, 1.0f, 1.0f, 1.0f };
		Ref<Texture2D> Texture;
		float TilingFactor = 1.0f;
	};


}

