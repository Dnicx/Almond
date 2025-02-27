workspace "Almond-Engine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories for vendor lib
VendorIncludeDir = {}
VendorIncludeDir["GLFW"] = "Almond-Engine/vendor/GLFW/include"
VendorIncludeDir["Glad"] = "Almond-Engine/vendor/Glad/include"

include "Almond-Engine/vendor/Glad"


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
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "ALMND_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "ALMND_DIST"
        buildoptions "/MD"
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
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{VendorIncludeDir.GLFW}",
        "%{VendorIncludeDir.Glad}"
    }

    libdirs
    {
        "%{prj.name}/vendor/GLFW/build/install/x64-Debug/lib"
    }

    links
    {
        "opengl32.lib",
        "glfw3",
        "Glad"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "off" -- NOTE!!! THIS is because we don't use GLFW premake
        runtime "Debug"
        systemversion "latest"

        defines
        {
            "ALMND_PLATFORM_WINDOWS",
            "ALMND_BUILD_DLL",  
            "ALMND_ENABLE_ASSERTS",
            "GLFW_INCLUDE_NONE"
        }
        
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/universe" )
        }

    filter "configurations:Debug"
        defines "ALMND_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "ALMND_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "ALMND_DIST"
        buildoptions "/MD"
        optimize "On"