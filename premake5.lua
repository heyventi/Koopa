include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Koopa"
	architecture "x86_64"
	startproject "Koopa"

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

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Koopa/lib/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Koopa/lib/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Koopa/lib/imgui"
IncludeDir["glm"] = "%{wks.location}/Koopa/lib/glm"
IncludeDir["stb_image"] = "%{wks.location}/Koopa/lib/stb_image"
IncludeDir["entt"] = "%{wks.location}/Koopa/lib/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Koopa/lib/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/Koopa/lib/ImGuizmo"

group "Dependencies"
	include "vendor/premake"
	include "Koopa/lib/GLFW"
	include "Koopa/lib/Glad"
	include "Koopa/lib/imgui"
	include "Koopa/lib/yaml-cpp"
group ""

include "Koopa"
include "Sandbox"
include "Koopa-Editor"
include "TinyDefense"