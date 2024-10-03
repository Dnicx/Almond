#pragma once

#ifdef ALMND_PLATFORM_WINDOWS
 
    #ifdef ALMND_BUILD_DLL
        #define ALMOND_API __declspec(dllexport)
    #else
        #define ALMOND_API __declspec(dllimport)
    #endif

#else

    #ifdef ALMND_BUILD_DLL
        #error only suppoort windows
    #endif
    // linux is probably extern

#endif

#ifdef ALMND_ENABLE_ASSERTS
	#define ALMOND_ASSERT(x, ...) { if(!(x)) { ALMOND_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ALMOND_CORE_ASSERT(x, ...) { if(!(x)) { ALMOND_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ALMOND_ASSERT(x, ...)
	#define ALMOND_CORE_ASSERT(x, ...)
#endif