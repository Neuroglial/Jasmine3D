#include "JMpch.h"
#include "Base.h"

#include "Log.h"

#define JASMINE_BUILD_ID "v0.1a"

namespace Jasmine {

	void InitializeCore()
	{
		Jasmine::Log::Init();

		JM_CORE_TRACE("Jasmine Engine {}", JASMINE_BUILD_ID);
		JM_CORE_TRACE("Initializing...");
	}

	void ShutdownCore()
	{
		JM_CORE_TRACE("Shutting down...");
	}

}