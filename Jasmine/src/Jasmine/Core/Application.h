#pragma once

#include "Jasmine/Core/Base.h"
#include "Jasmine/Core/Window.h"
#include "Jasmine/Core/LayerStack.h"

#include "Jasmine/Core/Events/ApplicationEvent.h"

#include "Jasmine/ImGui/ImGuiLayer.h"

namespace Jasmine {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		virtual void OnInit() {}
		virtual void OnShutdown() {}
		virtual void OnUpdate() {}

		virtual void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		void RenderImGui();

		inline Window& GetWindow() { return *m_Window; }
		
		static inline Application& Get() { return *s_Instance; }
	private:
		bool OnWindowResize(WindowResizeEvent& e);
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;

		static Application* s_Instance;
	};

	// Implemented by CLIENT
	Application* CreateApplication();
}