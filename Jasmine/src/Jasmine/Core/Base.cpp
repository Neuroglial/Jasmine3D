#include "JMpch.h"
#include "Base.h"

#include "Log.h"

#define Jasmine_BUILD_ID "v0.1a"

namespace Jasmine {

	void InitializeCore()
	{
		Log::Init();

		JM_CORE_TRACE("Jasmine Engine {}", Jasmine_BUILD_ID);
		JM_CORE_TRACE("Initializing...");
	}

	void ShutdownCore()
	{
		JM_CORE_TRACE("Shutting down...");
		
		Log::Shutdown();
	}

}