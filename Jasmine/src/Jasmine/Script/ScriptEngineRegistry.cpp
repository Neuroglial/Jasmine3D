#include "JMpch.h"
#include "ScriptEngineRegistry.h"

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Jasmine/Scene/Entity.h"
#include "ScriptWrappers.h"
#include <iostream>

namespace Jasmine {

	std::unordered_map<MonoType*, std::function<bool(Entity&)>> s_HasComponentFuncs;
	std::unordered_map<MonoType*, std::function<void(Entity&)>> s_CreateComponentFuncs;

	extern MonoImage* s_CoreAssemblyImage;

#define Component_RegisterType(Type) \
	{\
		MonoType* type = mono_reflection_type_from_name("Jasmine." #Type, s_CoreAssemblyImage);\
		if (type) {\
			uint32_t id = mono_type_get_type(type);\
			s_HasComponentFuncs[type] = [](Entity& entity) { return entity.HasComponent<Type>(); };\
			s_CreateComponentFuncs[type] = [](Entity& entity) { entity.AddComponent<Type>(); };\
		} else {\
			JM_CORE_ERROR("No C# component class found for " #Type "!");\
		}\
	}

	static void InitComponentTypes()
	{
		Component_RegisterType(TagComponent);
		Component_RegisterType(TransformComponent);
		Component_RegisterType(MeshComponent);
		Component_RegisterType(ScriptComponent);
		Component_RegisterType(CameraComponent);
		Component_RegisterType(SpriteRendererComponent);
	}

	void ScriptEngineRegistry::RegisterAll()
	{
		InitComponentTypes();

		mono_add_internal_call("Jasmine.Noise::PerlinNoise_Native", Jasmine::Script::Jasmine_Noise_PerlinNoise);

		mono_add_internal_call("Jasmine.Entity::GetTransform_Native", Jasmine::Script::Jasmine_Entity_GetTransform);
		mono_add_internal_call("Jasmine.Entity::SetTransform_Native", Jasmine::Script::Jasmine_Entity_SetTransform);
		mono_add_internal_call("Jasmine.Entity::CreateComponent_Native", Jasmine::Script::Jasmine_Entity_CreateComponent);
		mono_add_internal_call("Jasmine.Entity::HasComponent_Native", Jasmine::Script::Jasmine_Entity_HasComponent);
		
		mono_add_internal_call("Jasmine.MeshComponent::GetMesh_Native", Jasmine::Script::Jasmine_MeshComponent_GetMesh);
		mono_add_internal_call("Jasmine.MeshComponent::SetMesh_Native", Jasmine::Script::Jasmine_MeshComponent_SetMesh);

		mono_add_internal_call("Jasmine.Input::IsKeyPressed_Native", Jasmine::Script::Jasmine_Input_IsKeyPressed);

		mono_add_internal_call("Jasmine.Texture2D::Constructor_Native", Jasmine::Script::Jasmine_Texture2D_Constructor);
		mono_add_internal_call("Jasmine.Texture2D::Destructor_Native", Jasmine::Script::Jasmine_Texture2D_Destructor);
		mono_add_internal_call("Jasmine.Texture2D::SetData_Native", Jasmine::Script::Jasmine_Texture2D_SetData);

		mono_add_internal_call("Jasmine.Material::Destructor_Native", Jasmine::Script::Jasmine_Material_Destructor);
		mono_add_internal_call("Jasmine.Material::SetFloat_Native", Jasmine::Script::Jasmine_Material_SetFloat);
		mono_add_internal_call("Jasmine.Material::SetTexture_Native", Jasmine::Script::Jasmine_Material_SetTexture);

		mono_add_internal_call("Jasmine.MaterialInstance::Destructor_Native", Jasmine::Script::Jasmine_MaterialInstance_Destructor);
		mono_add_internal_call("Jasmine.MaterialInstance::SetFloat_Native", Jasmine::Script::Jasmine_MaterialInstance_SetFloat);
		mono_add_internal_call("Jasmine.MaterialInstance::SetVector3_Native", Jasmine::Script::Jasmine_MaterialInstance_SetVector3);
		mono_add_internal_call("Jasmine.MaterialInstance::SetTexture_Native", Jasmine::Script::Jasmine_MaterialInstance_SetTexture);

		mono_add_internal_call("Jasmine.Mesh::Constructor_Native", Jasmine::Script::Jasmine_Mesh_Constructor);
		mono_add_internal_call("Jasmine.Mesh::Destructor_Native", Jasmine::Script::Jasmine_Mesh_Destructor);
		mono_add_internal_call("Jasmine.Mesh::GetMaterial_Native", Jasmine::Script::Jasmine_Mesh_GetMaterial);
		mono_add_internal_call("Jasmine.Mesh::GetMaterialByIndex_Native", Jasmine::Script::Jasmine_Mesh_GetMaterialByIndex);
		mono_add_internal_call("Jasmine.Mesh::GetMaterialCount_Native", Jasmine::Script::Jasmine_Mesh_GetMaterialCount);

		mono_add_internal_call("Jasmine.MeshFactory::CreatePlane_Native", Jasmine::Script::Jasmine_MeshFactory_CreatePlane);

		// static bool IsKeyPressed(KeyCode key) { return s_Instance->IsKeyPressedImpl(key); }
		// 
		// static bool IsMouseButtonPressed(MouseCode button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		// static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		// static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		// static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
	}

}