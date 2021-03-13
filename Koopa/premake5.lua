project "Koopa"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "kppch.h"
	pchsource "src/kppch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",
		"lib/stb_image/**.h",
		"lib/stb_image/**.cpp",
		"lib/glm/glm/**.hpp",
		"lib/glm/glm/**.inl",

		"lib/ImGuizmo/ImGuizmo.h",
		"lib/ImGuizmo/ImGuizmo.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"src",
		"lib/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.yaml_cpp}",
		"%{IncludeDir.ImGuizmo}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"yaml-cpp",
		"opengl32.lib"
	}

	filter "files:lib/ImGuizmo/**.cpp"
	flags { "NoPCH" }

	filter "system:windows"
		systemversion "latest"

		defines
		{
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
