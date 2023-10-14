#pragma once

#include <memory>

namespace Jasmine {

	void InitializeCore();
	void ShutdownCore();

}

#ifdef JM_DEBUG
	#define JM_ENABLE_ASSERTS
#endif

#ifdef JM_ENABLE_ASSERTS
	#define JM_ASSERT(x, ...) { if(!(x)) { JM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define JM_CORE_ASSERT(x, ...) { if(!(x)) { JM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define JM_ASSERT(x, ...)
	#define JM_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define JM_BIND_EVENT_FN(fn) std::bind(&##fn, this, std::placeholders::_1)