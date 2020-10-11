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
IncludeDir["GLM"] = "Koopa/lib/glm"

group "Dependencies"
    include "Koopa/lib/GLFW"
    include "Koopa/lib/Glad"
    include "Koopa/lib/imgui"
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
		"%{prj.name}/lib/glm/glm/**.inl"
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
		"%{IncludeDir.GLM}"
	}

	links
	{
		"GLFW",
		"GLAD",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"KP_PLATFORM_WINDOWS",
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
		"%{IncludeDir.GLM}"
	}

	links
	{
		"Koopa"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"KP_PLATFORM_WINDOWS"
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