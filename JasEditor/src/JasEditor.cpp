#include <Jasmine.h>
#include <Jasmine/EntryPoint.h>

#include "EditorLayer.h"

#include "Jasmine/Renderer/RendererAPI.h"

class JasEditorApplication : public Jasmine::Application
{
public:
	JasEditorApplication(const Jasmine::ApplicationProps& props)
		: Application(props)
	{
	}

	virtual void OnInit() override
	{
		PushLayer(new Jasmine::EditorLayer());
	}
};

Jasmine::Application* Jasmine::CreateApplication(int argc, char** argv)
{
	//RendererAPI::SetAPI(RendererAPIType::OpenGL);
	return new JasEditorApplication({"JasEditor", 1600, 900});
}
