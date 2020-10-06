workspace "Koopa"
	architecture "x64"
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

group "Dependencies"
    include "Koopa/lib/GLFW"
    include "Koopa/lib/Glad"
    include "Koopa/lib/imgui"
group ""

project "Koopa"
	location "Koopa"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "kppch.h"
	pchsource "Koopa/src/kppch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/lib/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"GLAD",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"KP_PLATFORM_WINDOWS",
			"KP_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "KP_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "KP_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "KP_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		"Koopa/src"
	}

	links
	{
		"Koopa"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"KP_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "KP_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "KP_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "KP_DIST"
		runtime "Release"
		optimize "On"