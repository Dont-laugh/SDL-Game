workspace "SDL-Game"
    architecture "x64"
    startproject "Engine"
    configurations { "Debug", "Release" }
    platforms { "Windows", "MacOS" }

outputdir = "%{cfg.system}-%{cfg.buildcfg}-%{cfg.architecture}"
sdl_lib = "SDL2/lib/x64"

project "Engine"
    location "Engine"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/**.cpp",
        "%{prj.name}/**.hpp",
        "%{prj.name}/**.h",
    }

    includedirs
    {
        "SDL2/include",
        "%{prj.name}/src/include",
    }

    libdirs
    {
        sdl_lib,
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
        optimize "Off"

    filter "configurations:Release"
        symbols "Off"
        optimize "On"

    filter "system:Windows"
        systemversion "latest"
        links { "SDL2", "SDL2main" }
        postbuildcommands
        {
            "{COPY} ../" .. sdl_lib .. "/SDL2.dll ../bin/" .. outputdir .. "/%{prj.name}"
        }

    filter "system:MacOS"
        links { "SDL2.framework" }
        postbuildcommands
        {
            "cp ../" .. sdl_lib .. "/SDL2.dll ../bin/" .. outputdir .. "/%{prj.name}"
        }
