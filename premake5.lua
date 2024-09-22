workspace "Almond-Engine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "universe"
    location "universe"
    kind "ConsoleApp"
    language "C++"

    targetdir  ( "bin/" .. outputdir .. "/%{prj.name}" )
    objdir  ( "bin-int/" .. outputdir .. "/%{prj.name}" )

    files 
    { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp" 
    }

    includedirs
    {
        "Almond-Engine/vendor/spdlog/include",
        "Almond-Engine/src"
    }

    links
    {
        "Almond-Engine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "ALMND_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "ALMND_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ALMND_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "ALMND_DIST"
        optimize "On"


project "Almond-Engine"

    location "Almond-Engine"
    kind "SharedLib"
    language "C++"

    targetdir  ( "bin/" .. outputdir .. "/%{prj.name}" )
    objdir  ( "bin-int/" .. outputdir .. "/%{prj.name}" )

    pchheader "aepch.h"
    pchsource "Almond-Engine/src/aepch.cpp"
    
    files 
    { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp" 
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"        
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "ALMND_PLATFORM_WINDOWS",
            "ALMND_BUILD_DLL"
        }
        
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/universe" )
        }

    filter "configurations:Debug"
        defines "ALMND_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ALMND_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "ALMND_DIST"
        optimize "On"