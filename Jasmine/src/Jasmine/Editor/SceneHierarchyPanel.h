#pragma once

#include "Jasmine/Scene/Scene.h"
#include "Jasmine/Scene/Entity.h"
#include "Jasmine/Renderer/Mesh.h"
#include "Jasmine/Editor/EditorCamera.h"

namespace Jasmine {

	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel(const Ref<Scene>& scene, EditorCamera* editorCamera = nullptr);

		void SetContext(const Ref<Scene>& scene, EditorCamera* editorCamera = nullptr);
		void SetSelected(Entity entity);
		void SetSelectionChangedCallback(const std::function<void(Entity)>& func) { m_SelectionChangedCallback = func; }
		void SetEntityDeletedCallback(const std::function<void(Entity)>& func) { m_EntityDeletedCallback = func; }

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
		void DrawMeshNode(const Ref<Mesh>& mesh, uint32_t& imguiMeshID);
		void MeshNodeHierarchy(const Ref<Mesh>& mesh, aiNode* node, const glm::mat4& parentTransform = glm::mat4(1.0f), uint32_t level = 0);
		void DrawComponents(Entity entity);
	private:
		Ref<Scene> m_Context;
		EditorCamera* m_EditorCamera;
		Entity m_SelectionContext;

		std::function<void(Entity)> m_SelectionChangedCallback, m_EntityDeletedCallback;
	};

}