project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "%{wks.location}/Tulip/vendor/spdlog/include",
        "%{wks.location}/Tulip/src",
        "%{wks.location}/Tulip/vendor",
        "%{IncludeDir.glm}",
        "%{IncludeDir.entt}"
    }

    links
    {
        "Tulip"
    }

    filter "system:windows"
        systemversion "latest"

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