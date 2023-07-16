include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "Tulip"
    architecture "x86_64"
    startproject "Tulip-Editor"


    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    solution_items
    {
        ".editorconfig"
    }

    flags
    {
        "MultiProcessorCompile"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


group "dependencies"
    include "vendor/premake"
    include "Tulip/vendor/Box2D"
    include "Tulip/vendor/GLFW"
    include "Tulip/vendor/Glad"
    include "Tulip/vendor/imgui"
    include "Tulip/vendor/yaml-cpp"
group ""

include "Tulip"
include "Sandbox"
include "Tulip-Editor"
