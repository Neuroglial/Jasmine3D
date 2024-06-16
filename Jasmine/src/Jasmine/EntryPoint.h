#pragma once

#ifdef JM_PLATFORM_WINDOWS

extern Jasmine::Application* Jasmine::CreateApplication();

int main(int argc, char** argv)
{
	Jasmine::InitializeCore();
	Jasmine::Application* app = Jasmine::CreateApplication();
	JM_CORE_ASSERT(app, "Client Application is null!");
	app->Run();
	delete app;
	Jasmine::ShutdownCore();
}

#endif
