#pragma once

#include "JMpch.h"
#include "Jasmine/Core/Layer.h"

namespace Jasmine {

	class ImGuiLayer : public Layer
	{
	public:
		virtual void Begin() = 0;
		virtual void End() = 0;

		void SetDarkThemeColors();

		static ImGuiLayer* Create();
	};



}
