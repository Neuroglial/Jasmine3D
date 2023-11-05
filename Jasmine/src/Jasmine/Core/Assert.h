#pragma once

#ifdef JM_DEBUG
	#define JM_ENABLE_ASSERTS
#endif

#define JM_ENABLE_VERIFY

#ifdef JM_ENABLE_ASSERTS
	#define JM_ASSERT_NO_MESSAGE(condition) { if(!(condition)) { JM_ERROR("Assertion Failed"); __debugbreak(); } }
	#define JM_ASSERT_MESSAGE(condition, ...) { if(!(condition)) { JM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }

	#define JM_ASSERT_RESOLVE(arg1, arg2, macro, ...) macro
	#define JM_GET_ASSERT_MACRO(...) JM_EXPAND_VARGS(JM_ASSERT_RESOLVE(__VA_ARGS__, JM_ASSERT_MESSAGE, JM_ASSERT_NO_MESSAGE))

	#define JM_ASSERT(...) JM_EXPAND_VARGS( JM_GET_ASSERT_MACRO(__VA_ARGS__)(__VA_ARGS__) )
	#define JM_CORE_ASSERT(...) JM_EXPAND_VARGS( JM_GET_ASSERT_MACRO(__VA_ARGS__)(__VA_ARGS__) )
#else
	#define JM_ASSERT(...)
	#define JM_CORE_ASSERT(...)
#endif

#ifdef JM_ENABLE_VERIFY
	#define JM_VERIFY_NO_MESSAGE(condition) { if(!(condition)) { JM_ERROR("Verify Failed"); __debugbreak(); } }
	#define JM_VERIFY_MESSAGE(condition, ...) { if(!(condition)) { JM_ERROR("Verify Failed: {0}", __VA_ARGS__); __debugbreak(); } }

	#define JM_VERIFY_RESOLVE(arg1, arg2, macro, ...) macro
	#define JM_GET_VERIFY_MACRO(...) JM_EXPAND_VARGS(JM_VERIFY_RESOLVE(__VA_ARGS__, JM_VERIFY_MESSAGE, JM_VERIFY_NO_MESSAGE))

	#define JM_VERIFY(...) JM_EXPAND_VARGS( JM_GET_VERIFY_MACRO(__VA_ARGS__)(__VA_ARGS__) )
	#define JM_CORE_VERIFY(...) JM_EXPAND_VARGS( JM_GET_VERIFY_MACRO(__VA_ARGS__)(__VA_ARGS__) )
#else
	#define JM_VERIFY(...)
	#define JM_CORE_VERIFY(...)
#endif