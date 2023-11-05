#pragma once

#include "Jasmine/Script/ScriptEngine.h"
#include "Jasmine/Core/Input.h"
#include "Jasmine/Physics/Physics.h"

#include <glm/glm.hpp>

extern "C" {
	typedef struct _MonoString MonoString;
	typedef struct _MonoArray MonoArray;
}

namespace Jasmine { namespace Script {

	// Math
	float Jasmine_Noise_PerlinNoise(float x, float y);

	// Input
	bool Jasmine_Input_IsKeyPressed(KeyCode key);
	bool Jasmine_Input_IsMouseButtonPressed(MouseButton button);
	void Jasmine_Input_GetMousePosition(glm::vec2* outPosition);
	void Jasmine_Input_SetCursorMode(CursorMode mode);
	CursorMode Jasmine_Input_GetCursorMode();

	// Physics
	bool Jasmine_Physics_Raycast(glm::vec3* origin, glm::vec3* direction, float maxDistance, RaycastHit* hit);
	MonoArray* Jasmine_Physics_OverlapBox(glm::vec3* origin, glm::vec3* halfSize);
	MonoArray* Jasmine_Physics_OverlapCapsule(glm::vec3* origin, float radius, float halfHeight);
	MonoArray* Jasmine_Physics_OverlapSphere(glm::vec3* origin, float radius);
	int32_t Jasmine_Physics_OverlapBoxNonAlloc(glm::vec3* origin, glm::vec3* halfSize, MonoArray* outColliders);
	int32_t Jasmine_Physics_OverlapCapsuleNonAlloc(glm::vec3* origin, float radius, float halfHeight, MonoArray* outColliders);
	int32_t Jasmine_Physics_OverlapSphereNonAlloc(glm::vec3* origin, float radius, MonoArray* outColliders);

	// Entity
	void Jasmine_Entity_CreateComponent(uint64_t entityID, void* type);
	bool Jasmine_Entity_HasComponent(uint64_t entityID, void* type);
	uint64_t Jasmine_Entity_FindEntityByTag(MonoString* tag);

	void Jasmine_TransformComponent_GetTransform(uint64_t entityID, TransformComponent* outTransform);
	void Jasmine_TransformComponent_SetTransform(uint64_t entityID, TransformComponent* inTransform);
	void Jasmine_TransformComponent_GetTranslation(uint64_t entityID, glm::vec3* outTranslation);
	void Jasmine_TransformComponent_SetTranslation(uint64_t entityID, glm::vec3* inTranslation);
	void Jasmine_TransformComponent_GetRotation(uint64_t entityID, glm::vec3* outRotation);
	void Jasmine_TransformComponent_SetRotation(uint64_t entityID, glm::vec3* inRotation);
	void Jasmine_TransformComponent_GetScale(uint64_t entityID, glm::vec3* outScale);
	void Jasmine_TransformComponent_SetScale(uint64_t entityID, glm::vec3* inScale);

	void* Jasmine_MeshComponent_GetMesh(uint64_t entityID);
	void Jasmine_MeshComponent_SetMesh(uint64_t entityID, Ref<Mesh>* inMesh);

	void Jasmine_RigidBody2DComponent_ApplyLinearImpulse(uint64_t entityID, glm::vec2* impulse, glm::vec2* offset, bool wake);
	void Jasmine_RigidBody2DComponent_GetLinearVelocity(uint64_t entityID, glm::vec2* outVelocity);
	void Jasmine_RigidBody2DComponent_SetLinearVelocity(uint64_t entityID, glm::vec2* velocity);

	RigidBodyComponent::Type Jasmine_RigidBodyComponent_GetBodyType(uint64_t entityID);
	void Jasmine_RigidBodyComponent_AddForce(uint64_t entityID, glm::vec3* force, ForceMode foceMode);
	void Jasmine_RigidBodyComponent_AddTorque(uint64_t entityID, glm::vec3* torque, ForceMode forceMode);
	void Jasmine_RigidBodyComponent_GetLinearVelocity(uint64_t entityID, glm::vec3* outVelocity);
	void Jasmine_RigidBodyComponent_SetLinearVelocity(uint64_t entityID, glm::vec3* velocity);
	void Jasmine_RigidBodyComponent_GetAngularVelocity(uint64_t entityID, glm::vec3* outVelocity);
	void Jasmine_RigidBodyComponent_SetAngularVelocity(uint64_t entityID, glm::vec3* velocity);
	void Jasmine_RigidBodyComponent_Rotate(uint64_t entityID, glm::vec3* rotation);
	uint32_t Jasmine_RigidBodyComponent_GetLayer(uint64_t entityID);
	float Jasmine_RigidBodyComponent_GetMass(uint64_t entityID);
	void Jasmine_RigidBodyComponent_SetMass(uint64_t entityID, float mass);

	// Renderer
	// Texture2D
	void* Jasmine_Texture2D_Constructor(uint32_t width, uint32_t height);
	void Jasmine_Texture2D_Destructor(Ref<Texture2D>* _this);
	void Jasmine_Texture2D_SetData(Ref<Texture2D>* _this, MonoArray* inData, int32_t count);

	// Material
	void Jasmine_Material_Destructor(Ref<Material>* _this);
	void Jasmine_Material_SetFloat(Ref<Material>* _this, MonoString* uniform, float value);
	void Jasmine_Material_SetTexture(Ref<Material>* _this, MonoString* uniform, Ref<Texture2D>* texture);

	void Jasmine_MaterialInstance_Destructor(Ref<Material>* _this);
	void Jasmine_MaterialInstance_SetFloat(Ref<Material>* _this, MonoString* uniform, float value);
	void Jasmine_MaterialInstance_SetVector3(Ref<Material>* _this, MonoString* uniform, glm::vec3* value);
	void Jasmine_MaterialInstance_SetVector4(Ref<Material>* _this, MonoString* uniform, glm::vec4* value);
	void Jasmine_MaterialInstance_SetTexture(Ref<Material>* _this, MonoString* uniform, Ref<Texture2D>* texture);

	// Mesh
	Ref<Mesh>* Jasmine_Mesh_Constructor(MonoString* filepath);
	void Jasmine_Mesh_Destructor(Ref<Mesh>* _this);
	Ref<Material>* Jasmine_Mesh_GetMaterial(Ref<Mesh>* inMesh);
	Ref<Material>* Jasmine_Mesh_GetMaterialByIndex(Ref<Mesh>* inMesh, int index);
	int Jasmine_Mesh_GetMaterialCount(Ref<Mesh>* inMesh);

	void* Jasmine_MeshFactory_CreatePlane(float width, float height);
} }