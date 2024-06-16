//
// Note:	this file is to be included in client applications ONLY
//			NEVER include this file anywhere in the engine codebase
//
#pragma once

#include "Jasmine/Core/Application.h"
#include "Jasmine/Core/Log.h"
#include "Jasmine/Core/Input.h"
#include "Jasmine/Core/Timestep.h"
#include "Jasmine/Core/Timer.h"

#include "Jasmine/Core/Events/Event.h"
#include "Jasmine/Core/Events/ApplicationEvent.h"
#include "Jasmine/Core/Events/KeyEvent.h"
#include "Jasmine/Core/Events/MouseEvent.h"

#include "Jasmine/Core/Math/AABB.h"
#include "Jasmine/Core/Math/Ray.h"

#include "imgui/imgui.h"

// --- Jasmine Render API ------------------------------
#include "Jasmine/Renderer/Renderer.h"
#include "Jasmine/Renderer/SceneRenderer.h"
#include "Jasmine/Renderer/RenderPass.h"
#include "Jasmine/Renderer/Framebuffer.h"
#include "Jasmine/Renderer/VertexBuffer.h"
#include "Jasmine/Renderer/IndexBuffer.h"
#include "Jasmine/Renderer/Pipeline.h"
#include "Jasmine/Renderer/Texture.h"
#include "Jasmine/Renderer/Shader.h"
#include "Jasmine/Renderer/Mesh.h"
#include "Jasmine/Renderer/Camera.h"
#include "Jasmine/Renderer/Material.h"
// ---------------------------------------------------

// Scenes
#include "Jasmine/Scene/Entity.h"
#include "Jasmine/Scene/Scene.h"
#include "Jasmine/Scene/SceneCamera.h"
#include "Jasmine/Scene/SceneSerializer.h"
#include "Jasmine/Scene/Components.h"