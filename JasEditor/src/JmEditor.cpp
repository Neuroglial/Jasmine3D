#include <Jasmine.h>
#include <Jasmine/EntryPoint.h>

#include "EditorLayer.h"

class JasminenutApplication : public Jasmine::Application
{
public:
	JasminenutApplication(const Jasmine::ApplicationProps& props)
		: Application(props)
	{
	}

	virtual void OnInit() override
	{
		PushLayer(new Jasmine::EditorLayer());
	}
};

Jasmine::Application* Jasmine::CreateApplication()
{
	return new JasminenutApplication({"JasEditor", 1600, 900});
}