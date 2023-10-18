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

		void Begin();
		void End();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;
	private:
		void SetDarkThemeColors();
		float m_Time = 0.0f;
	};

}
