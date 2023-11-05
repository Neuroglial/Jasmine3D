#include "JMpch.h"
#include "ScriptEngineRegistry.h"

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Jasmine/Scene/Entity.h"
#include "ScriptWrappers.h"

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
		Component_RegisterType(RigidBody2DComponent);
		Component_RegisterType(BoxCollider2DComponent);
		Component_RegisterType(RigidBodyComponent);
		Component_RegisterType(BoxColliderComponent);
		Component_RegisterType(SphereColliderComponent);
	}

	void ScriptEngineRegistry::RegisterAll()
	{
		InitComponentTypes();

		mono_add_internal_call("Jasmine.Noise::PerlinNoise_Native", Jasmine::Script::Jasmine_Noise_PerlinNoise);

		mono_add_internal_call("Jasmine.Physics::Raycast_Native", Jasmine::Script::Jasmine_Physics_Raycast);
		mono_add_internal_call("Jasmine.Physics::OverlapBox_Native", Jasmine::Script::Jasmine_Physics_OverlapBox);
		mono_add_internal_call("Jasmine.Physics::OverlapCapsule_Native", Jasmine::Script::Jasmine_Physics_OverlapCapsule);
		mono_add_internal_call("Jasmine.Physics::OverlapSphere_Native", Jasmine::Script::Jasmine_Physics_OverlapSphere);
		mono_add_internal_call("Jasmine.Physics::OverlapBoxNonAlloc_Native", Jasmine::Script::Jasmine_Physics_OverlapBoxNonAlloc);
		mono_add_internal_call("Jasmine.Physics::OverlapCapsuleNonAlloc_Native", Jasmine::Script::Jasmine_Physics_OverlapCapsuleNonAlloc);
		mono_add_internal_call("Jasmine.Physics::OverlapSphereNonAlloc_Native", Jasmine::Script::Jasmine_Physics_OverlapSphereNonAlloc);

		mono_add_internal_call("Jasmine.Entity::CreateComponent_Native", Jasmine::Script::Jasmine_Entity_CreateComponent);
		mono_add_internal_call("Jasmine.Entity::HasComponent_Native", Jasmine::Script::Jasmine_Entity_HasComponent);
		mono_add_internal_call("Jasmine.Entity::FindEntityByTag_Native", Jasmine::Script::Jasmine_Entity_FindEntityByTag);

		mono_add_internal_call("Jasmine.TransformComponent::GetTransform_Native", Jasmine::Script::Jasmine_TransformComponent_GetTransform);
		mono_add_internal_call("Jasmine.TransformComponent::SetTransform_Native", Jasmine::Script::Jasmine_TransformComponent_SetTransform);
		mono_add_internal_call("Jasmine.TransformComponent::GetTranslation_Native", Jasmine::Script::Jasmine_TransformComponent_GetTranslation);
		mono_add_internal_call("Jasmine.TransformComponent::SetTranslation_Native", Jasmine::Script::Jasmine_TransformComponent_SetTranslation);
		mono_add_internal_call("Jasmine.TransformComponent::GetRotation_Native", Jasmine::Script::Jasmine_TransformComponent_GetRotation);
		mono_add_internal_call("Jasmine.TransformComponent::SetRotation_Native", Jasmine::Script::Jasmine_TransformComponent_SetRotation);
		mono_add_internal_call("Jasmine.TransformComponent::GetScale_Native", Jasmine::Script::Jasmine_TransformComponent_GetScale);
		mono_add_internal_call("Jasmine.TransformComponent::SetScale_Native", Jasmine::Script::Jasmine_TransformComponent_SetScale);

		mono_add_internal_call("Jasmine.MeshComponent::GetMesh_Native", Jasmine::Script::Jasmine_MeshComponent_GetMesh);
		mono_add_internal_call("Jasmine.MeshComponent::SetMesh_Native", Jasmine::Script::Jasmine_MeshComponent_SetMesh);

		mono_add_internal_call("Jasmine.RigidBody2DComponent::ApplyLinearImpulse_Native", Jasmine::Script::Jasmine_RigidBody2DComponent_ApplyLinearImpulse);
		mono_add_internal_call("Jasmine.RigidBody2DComponent::GetLinearVelocity_Native", Jasmine::Script::Jasmine_RigidBody2DComponent_GetLinearVelocity);
		mono_add_internal_call("Jasmine.RigidBody2DComponent::SetLinearVelocity_Native", Jasmine::Script::Jasmine_RigidBody2DComponent_SetLinearVelocity);

		mono_add_internal_call("Jasmine.RigidBodyComponent::GetBodyType_Native", Jasmine::Script::Jasmine_RigidBodyComponent_GetBodyType);
		mono_add_internal_call("Jasmine.RigidBodyComponent::AddForce_Native", Jasmine::Script::Jasmine_RigidBodyComponent_AddForce);
		mono_add_internal_call("Jasmine.RigidBodyComponent::AddTorque_Native", Jasmine::Script::Jasmine_RigidBodyComponent_AddTorque);
		mono_add_internal_call("Jasmine.RigidBodyComponent::GetLinearVelocity_Native", Jasmine::Script::Jasmine_RigidBodyComponent_GetLinearVelocity);
		mono_add_internal_call("Jasmine.RigidBodyComponent::SetLinearVelocity_Native", Jasmine::Script::Jasmine_RigidBodyComponent_SetLinearVelocity);
		mono_add_internal_call("Jasmine.RigidBodyComponent::GetAngularVelocity_Native", Jasmine::Script::Jasmine_RigidBodyComponent_GetAngularVelocity);
		mono_add_internal_call("Jasmine.RigidBodyComponent::SetAngularVelocity_Native", Jasmine::Script::Jasmine_RigidBodyComponent_SetAngularVelocity);
		mono_add_internal_call("Jasmine.RigidBodyComponent::Rotate_Native", Jasmine::Script::Jasmine_RigidBodyComponent_Rotate);
		mono_add_internal_call("Jasmine.RigidBodyComponent::GetLayer_Native", Jasmine::Script::Jasmine_RigidBodyComponent_GetLayer);
		mono_add_internal_call("Jasmine.RigidBodyComponent::GetMass_Native", Jasmine::Script::Jasmine_RigidBodyComponent_GetMass);
		mono_add_internal_call("Jasmine.RigidBodyComponent::SetMass_Native", Jasmine::Script::Jasmine_RigidBodyComponent_SetMass);

		mono_add_internal_call("Jasmine.Input::IsKeyPressed_Native", Jasmine::Script::Jasmine_Input_IsKeyPressed);
		mono_add_internal_call("Jasmine.Input::IsMouseButtonPressed_Native", Jasmine::Script::Jasmine_Input_IsMouseButtonPressed);
		mono_add_internal_call("Jasmine.Input::GetMousePosition_Native", Jasmine::Script::Jasmine_Input_GetMousePosition);
		mono_add_internal_call("Jasmine.Input::SetCursorMode_Native", Jasmine::Script::Jasmine_Input_SetCursorMode);
		mono_add_internal_call("Jasmine.Input::GetCursorMode_Native", Jasmine::Script::Jasmine_Input_GetCursorMode);

		mono_add_internal_call("Jasmine.Texture2D::Constructor_Native", Jasmine::Script::Jasmine_Texture2D_Constructor);
		mono_add_internal_call("Jasmine.Texture2D::Destructor_Native", Jasmine::Script::Jasmine_Texture2D_Destructor);
		mono_add_internal_call("Jasmine.Texture2D::SetData_Native", Jasmine::Script::Jasmine_Texture2D_SetData);

		mono_add_internal_call("Jasmine.Material::Destructor_Native", Jasmine::Script::Jasmine_Material_Destructor);
		mono_add_internal_call("Jasmine.Material::SetFloat_Native", Jasmine::Script::Jasmine_Material_SetFloat);
		mono_add_internal_call("Jasmine.Material::SetTexture_Native", Jasmine::Script::Jasmine_Material_SetTexture);

		mono_add_internal_call("Jasmine.MaterialInstance::Destructor_Native", Jasmine::Script::Jasmine_MaterialInstance_Destructor);
		mono_add_internal_call("Jasmine.MaterialInstance::SetFloat_Native", Jasmine::Script::Jasmine_MaterialInstance_SetFloat);
		mono_add_internal_call("Jasmine.MaterialInstance::SetVector3_Native", Jasmine::Script::Jasmine_MaterialInstance_SetVector3);
		mono_add_internal_call("Jasmine.MaterialInstance::SetVector4_Native", Jasmine::Script::Jasmine_MaterialInstance_SetVector4);
		mono_add_internal_call("Jasmine.MaterialInstance::SetTexture_Native", Jasmine::Script::Jasmine_MaterialInstance_SetTexture);

		mono_add_internal_call("Jasmine.Mesh::Constructor_Native", Jasmine::Script::Jasmine_Mesh_Constructor);
		mono_add_internal_call("Jasmine.Mesh::Destructor_Native", Jasmine::Script::Jasmine_Mesh_Destructor);
		mono_add_internal_call("Jasmine.Mesh::GetMaterial_Native", Jasmine::Script::Jasmine_Mesh_GetMaterial);
		mono_add_internal_call("Jasmine.Mesh::GetMaterialByIndex_Native", Jasmine::Script::Jasmine_Mesh_GetMaterialByIndex);
		mono_add_internal_call("Jasmine.Mesh::GetMaterialCount_Native", Jasmine::Script::Jasmine_Mesh_GetMaterialCount);

		mono_add_internal_call("Jasmine.MeshFactory::CreatePlane_Native", Jasmine::Script::Jasmine_MeshFactory_CreatePlane);
	}

}