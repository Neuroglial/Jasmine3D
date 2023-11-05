#pragma once

#ifdef JM_PLATFORM_WINDOWS

extern Jasmine::Application* Jasmine::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

int main(int argc, char** argv)
{
	while (g_ApplicationRunning)
	{
		Jasmine::InitializeCore();
		Jasmine::Application* app = Jasmine::CreateApplication(argc, argv);
		JM_CORE_ASSERT(app, "Client Application is null!");
		app->Run();
		delete app;
		Jasmine::ShutdownCore();
	}
}

#endif
