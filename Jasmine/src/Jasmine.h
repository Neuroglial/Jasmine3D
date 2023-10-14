//
// Note:	this file is to be included in client applications ONLY
//			NEVER include this file anywhere in the engine codebase
//
#pragma once

#include "Jasmine/Core/Application.h"
#include "Jasmine/Core/Log.h"

#include "Jasmine/Core/Events/Event.h"
#include "Jasmine/Core/Events/ApplicationEvent.h"
#include "Jasmine/Core/Events/KeyEvent.h"
#include "Jasmine/Core/Events/MouseEvent.h"

#include "imgui/imgui.h"

// --- Jasmine Render API ------------------------------
#include "Jasmine/Renderer/Renderer.h"
#include "Jasmine/Renderer/FrameBuffer.h"
#include "Jasmine/Renderer/VertexBuffer.h"
#include "Jasmine/Renderer/IndexBuffer.h"
#include "Jasmine/Renderer/Texture.h"
#include "Jasmine/Renderer/Shader.h"
// ---------------------------------------------------

// --- Entry Point ------------
#include "Jasmine/EntryPoint.h"
// ----------------------------