workspace "Jasmine3D"
	architecture "x64"
	targetdir "build"
	startproject "Sandbox"
	
	configurations 
	{ 
		"Debug", 
        	"Release",
        	"Dist"
    	}
    
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	-- Include directories relative to root folder (solution directory)
	IncludeDir = {}
	IncludeDir["GLFW"] = "Jasmine/vendor/GLFW/include"
	IncludeDir["Glad"] = "Jasmine/vendor/Glad/include"
	IncludeDir["ImGui"] = "Jasmine/vendor/ImGui"
	IncludeDir["glm"] = "Jasmine/vendor/glm"
	IncludeDir["ImGuizmo"] = "Jasmine/vendor/ImGuizmo"
	IncludeDir["entt"] = "Jasmine/vendor/entt/include"
	
	LibraryDir = {}
	
	
	------Dependencies--------------------------------------------------
	
	group "Dependencies"
	include "Jasmine/vendor/GLFW"
	include "Jasmine/vendor/Glad"
	include "Jasmine/vendor/ImGui"
	group ""
	
	
	------Core----------------------------------------------------------
	
	group "Core"
	project "Jasmine"
    		location "Jasmine"
    		kind "StaticLib"
    		language "C++"
    		cppdialect "C++17"
    		staticruntime "on"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    		pchheader "JMpch.h"
    		pchsource "Jasmine/src/JMpch.cpp"

		files 
		{ 
			"%{prj.name}/src/**.h", 
			"%{prj.name}/src/**.c", 
			"%{prj.name}/src/**.hpp", 
			"%{prj.name}/src/**.cpp" ,
			"%{prj.name}/vendor/ImGuizmo/ImGuizmo.h",
			"%{prj.name}/vendor/ImGuizmo/ImGuizmo.cpp"
    		}
    		
    		defines
		{
			"_CRT_SECURE_NO_WARNINGS",
			"NOMINMAX"
		}


    		includedirs
		{
			"%{prj.name}/src",
        		"%{prj.name}/vendor",
        		"%{IncludeDir.GLFW}",
        		"%{IncludeDir.Glad}",
        		"%{IncludeDir.glm}",
        		"%{IncludeDir.ImGui}",
        		"%{prj.name}/vendor/assimp/include",
        		"%{prj.name}/vendor/spdlog/include",
        		"%{prj.name}/vendor/stb/include",
        		"%{IncludeDir.ImGuizmo}",
        		"%{IncludeDir.entt}"
     		}
    
    		links 
		{ 
        		"GLFW",
        		"Glad",
        		"ImGui",
			"opengl32.lib"
    		}
    
    		filter "files:Jasmine/vendor/ImGuizmo/**.cpp"
		flags { "NoPCH" }
    		
		filter "system:windows"
     		systemversion "latest"
        
		defines 
		{ 
           	"JM_PLATFORM_WINDOWS",
           	"JM_BUILD_DLL"
		}

    		filter "configurations:Debug"
        		defines "JM_DEBUG"
        		symbols "On"
                
    		filter "configurations:Release"
        		defines "JM_RELEASE"
        		optimize "On"

    		filter "configurations:Dist"
        		defines "JM_DIST"
        		optimize "On"
        		
      project "Jasmine-ScriptCore"
		location "Jasmine-ScriptCore"
		kind "SharedLib"
		language "C#"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files 
		{
			"%{prj.name}/src/**.cs", 
		}
		
	group ""
		
	
  	------Tool-----------------------------------------------------------
  	
  	group "Tool"
	project "JasEditor"
    		location "JasEditor"
    		kind "ConsoleApp"
    		language "C++"
    		cppdialect "C++17"
    		staticruntime "on"
    
		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		links 
		{ 
			"Jasmine"
    		}
    
		files 
		{ 
			"%{prj.name}/src/**.h", 
			"%{prj.name}/src/**.c", 
			"%{prj.name}/src/**.hpp", 
			"%{prj.name}/src/**.cpp" 
		}
    
		includedirs 
		{
        		"%{prj.name}/src",
        		"Jasmine/vendor/spdlog/include",
        		"Jasmine/src",
        		"Jasmine/vendor",
        		"%{IncludeDir.glm}",
        		"%{IncludeDir.ImGuizmo}",
        		"%{IncludeDir.entt}"
    		}
    		
    		postbuildcommands 
		{
			'{COPY} "../JasEditor/assets" "%{cfg.targetdir}/assets"'
		}

	
		filter "system:windows"
        		systemversion "latest"
                
		defines 
		{ 
			"NOMINMAX",
            	"JM_PLATFORM_WINDOWS"
		}
    
    		filter "configurations:Debug"
        		defines "JM_DEBUG"
        		symbols "on"
        		links
			{
				"Jasmine/vendor/assimp/bin/Debug/assimp-vc141-mtd.lib"
			}
			
			postbuildcommands 
			{
				'{COPY} "../Jasmine/vendor/assimp/bin/Debug/assimp-vc141-mtd.dll" "%{cfg.targetdir}"'
			}

                
    		filter "configurations:Release"
        		defines "JM_RELEASE"
        		optimize "on"
        		links
			{
				"Jasmine/vendor/assimp/bin/Release/assimp-vc141-mt.lib"
			}
			
			postbuildcommands 
			{
				'{COPY} "../Jasmine/vendor/assimp/bin/Release/assimp-vc141-mt.dll" "%{cfg.targetdir}"'
			}


    		filter "configurations:Dist"
        		defines "JM_DIST"
        		optimize "on"
        		links
			{
				"Jasmine/vendor/assimp/bin/Release/assimp-vc141-mt.lib"
			}
			
			postbuildcommands 
			{
				'{COPY} "../Jasmine/vendor/assimp/bin/Release/assimp-vc141-mt.dll" "%{cfg.targetdir}"'
			}
			
	group ""
	
	
	------Examples------------------------------------------------------
	
	group "Examples"
	project "ExampleApp"
		location "ExampleApp"
		kind "SharedLib"
		language "C#"

		targetdir ("JasEditor/assets/scripts")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files 
		{
			"%{prj.name}/src/**.cs", 
		}

		links
		{
			"Jasmine-ScriptCore"
		}

	group ""
