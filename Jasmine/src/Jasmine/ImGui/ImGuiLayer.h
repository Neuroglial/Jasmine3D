#pragma once

#include "JMpch.h"
#include "Jasmine/Core/Layer.h"

namespace Jasmine {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		ImGuiLayer(const std::string& name);
		virtual ~ImGuiLayer();

		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void SetDarkThemeColors();
	private:
		float m_Time = 0.0f;
	};

}
