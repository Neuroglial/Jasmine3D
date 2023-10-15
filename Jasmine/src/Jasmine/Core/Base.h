#pragma once

#include <memory>

namespace Jasmine {

	void InitializeCore();
	void ShutdownCore();

}

#ifdef JM_DEBUG
	#define JM_ENABLE_ASSERTS
#endif

#ifdef JM_PLATFORM_WINDOWS
#if JM_DYNAMIC_LINK
	#ifdef JM_BUILD_DLL
		#define Jasmine_API __declspec(dllexport)
	#else
		#define Jasmine_API __declspec(dllimport)
	#endif
#else
	#define Jasmine_API
#endif
#else
	#error Jasmine only supports Windows!
#endif

#ifdef JM_ENABLE_ASSERTS

	#define JM_ASSERT_NO_MESSAGE(condition) { if(!(condition)) { JM_ERROR("Assertion Failed!"); __debugbreak(); } }
	#define JM_ASSERT_MESSAGE(condition, ...) { if(!(condition)) { JM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }

	#define JM_ASSERT_RESOLVE(arg1, arg2, macro, ...) macro

	#define JM_ASSERT(...) JM_ASSERT_RESOLVE(__VA_ARGS__, JM_ASSERT_MESSAGE, JM_ASSERT_NO_MESSAGE)(__VA_ARGS__)
	#define JM_CORE_ASSERT(...) JM_ASSERT_RESOLVE(__VA_ARGS__, JM_ASSERT_MESSAGE, JM_ASSERT_NO_MESSAGE)(__VA_ARGS__)
#else
	#define JM_ASSERT(...)
	#define JM_CORE_ASSERT(...)
#endif

#define BIT(x) (1 << x)

#define JM_BIND_EVENT_FN(fn) std::bind(&##fn, this, std::placeholders::_1)

// Pointer wrappers
namespace Jasmine {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

	using byte = unsigned char;

}