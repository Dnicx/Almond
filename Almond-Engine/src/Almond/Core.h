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

#endif