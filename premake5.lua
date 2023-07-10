workspace "Tulip"
    architecture "x86_64"
    startproject "Tulip-Editor"


    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Tulip/vendor/GLFW/include"
IncludeDir["Glad"] = "Tulip/vendor/Glad/include"
IncludeDir["ImGui"] = "Tulip/vendor/imgui"
IncludeDir["glm"] = "Tulip/vendor/glm"
IncludeDir["stb_image"] = "Tulip/vendor/stb_image"
IncludeDir["entt"] = "Tulip/vendor/entt/include"
IncludeDir["yaml_cpp"] = "Tulip/vendor/yaml-cpp/include"


group "dependencies"
    include "Tulip/vendor/GLFW"
    include "Tulip/vendor/Glad"
    include "Tulip/vendor/imgui"
    include "Tulip/vendor/yaml-cpp"
group ""

project "Tulip"
    location "Tulip"
    kind "Staticlib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"


    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "tulippch.h"
    pchsource "Tulip/src/tulippch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/stb_image/**.h",
        "%{prj.name}/vendor/stb_image/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.stb_image}",
        "%{IncludeDir.entt}",
        "%{IncludeDir.yaml_cpp}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "yaml-cpp",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "TULIP_PLATFORM_WINDOWS",
            "TULIP_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        --postbuildcommands
        --{
            --("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        --}

    filter "configurations:Debug"
        defines "TULIP_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "TULIP_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "TULIP_DIST"
        runtime "Release"
        optimize "on"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"


    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Tulip/vendor/spdlog/include",
        "Tulip/src",
        "Tulip/vendor",
        "%{IncludeDir.glm}"
    }

    links
    {
        "Tulip"
    }

    filter "system:windows"

        systemversion "latest"

        defines
        {
            "TULIP_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "TULIP_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "TULIP_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "TULIP_DIST"
        runtime "Release"
        optimize "on"


project "Tulip-Editor"
    location "Tulip-Editor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"


    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Tulip/vendor/spdlog/include",
        "Tulip/src",
        "Tulip/vendor",
        "%{IncludeDir.glm}",
        "%{IncludeDir.entt}"
    }

    links
    {
        "Tulip"
    }

    filter "system:windows"

        systemversion "latest"

        defines
        {
            "TULIP_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "TULIP_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "TULIP_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "TULIP_DIST"
        runtime "Release"
        optimize "on"