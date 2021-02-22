workspace "Koopa"
    architecture "x86_64"
	startproject "Sandbox"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Koopa/lib/glfw/include"
IncludeDir["GLAD"] = "Koopa/lib/glad/include"
IncludeDir["ImGui"] = "Koopa/lib/imgui"
IncludeDir["GLM"] = "Koopa/lib/glm"
IncludeDir["stb_image"] = "Koopa/lib/stb_image"
IncludeDir["entt"] = "Koopa/lib/entt/include"
IncludeDir["yaml_cpp"] = "Koopa/lib/yaml-cpp/include"

group "Dependencies"
    include "Koopa/lib/GLFW"
    include "Koopa/lib/Glad"
    include "Koopa/lib/imgui"
    include "Koopa/lib/yaml-cpp"
group ""

project "Koopa"
	location "Koopa"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"	
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "kppch.h"
	pchsource "Koopa/src/kppch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/lib/glm/glm/**.hpp",
		"%{prj.name}/lib/glm/glm/**.inl",
        "%{prj.name}/lib/stb_image/**.h",
        "%{prj.name}/lib/stb_image/**.cpp"		
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/lib/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.GLM}",
        "%{IncludeDir.stb_image}",
        "%{IncludeDir.entt}",
        "%{IncludeDir.yaml_cpp}"
	}

	links
	{
		"GLFW",
		"GLAD",
		"ImGui",
        "yaml-cpp",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"KP_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "KP_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "KP_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "KP_DIST"
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
		"Koopa/lib/spdlog/include",
		"Koopa/src",
		"%{IncludeDir.GLM}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Koopa"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "KP_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "KP_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "KP_DIST"
		runtime "Release"
		optimize "on"

project "Koopa-Editor"
    location "Koopa-Editor"
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
        "Koopa/lib/spdlog/include",
        "Koopa/src",
        "Koopa/lib",
		"%{IncludeDir.GLM}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.entt}"
    }

    links
    {
        "Koopa"
    }

    filter "system:windows"
        systemversion "latest"
        
    filter "configurations:Debug"
        defines "KP_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "KP_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "KP_DIST"
        runtime "Release"
        optimize "on"		