#include <Jasmine.h>
#include <Jasmine/EntryPoint.h>

#include "EditorLayer.h"

class JasmineApplication : public Jasmine::Application
{
public:
	JasmineApplication(const Jasmine::ApplicationProps& props)
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
	return new JasmineApplication({"Jasmine", 1600, 900});
}
