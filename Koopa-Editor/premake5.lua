project "Koopa-Editor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Koopa/lib/spdlog/include",
		"%{wks.location}/Koopa/src",
		"%{wks.location}/Koopa/lib",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.ImGuizmo}"
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
