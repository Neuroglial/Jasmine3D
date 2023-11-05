#pragma once

#include "Jasmine/Renderer/Texture.h"
#include "Jasmine/Asset/AssetManager.h"

namespace Jasmine {

	class ObjectsPanel
	{
	public:
		ObjectsPanel();

		void OnImGuiRender();

	private:
		void DrawObject(const char* label, AssetHandle handle);

	private:
		Ref<Texture2D> m_CubeImage;
	};

}
