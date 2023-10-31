workspace "Jasmine3D"
	architecture "x64"
	targetdir "build"
	startproject "JasEditor"
	
	configurations 
	{ 
		"Debug", 
        	"Release",
        	"Dist"
    	}
    
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	-- Include directories relative to root folder (solution directory)
	IncludeDir = {}
	IncludeDir["GLFW"] 		= "Jasmine/vendor/GLFW/include"
	IncludeDir["Glad"] 		= "Jasmine/vendor/Glad/include"
	IncludeDir["ImGui"] 		= "Jasmine/vendor/ImGui"
	IncludeDir["glm"] 		= "Jasmine/vendor/glm"
	IncludeDir["ImGuizmo"]	= "Jasmine/vendor/ImGuizmo"
	IncludeDir["entt"] 		= "Jasmine/vendor/entt/include"
	IncludeDir["FastNoise"]	= "Jasmine/vendor/FastNoise"
	IncludeDir["mono"] 		= "Jasmine/vendor/mono/include"
	IncludeDir["Box2D"] 		= "Jasmine/vendor/Box2D/include"
	
	LibraryDir = {}
	LibraryDir["mono"] = "vendor/mono/lib/mono-2.0-sgen.lib"
	
	
	------Dependencies--------------------------------------------------
	
	group "Dependencies"
	include "Jasmine/vendor/GLFW"
	include "Jasmine/vendor/Glad"
	include "Jasmine/vendor/ImGui"
	include "Jasmine/vendor/Box2D"
	group ""
	
	
	------Group-Core----------------------------------------------------------
	group "Core"
	
	------Project---------------
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
			"%{prj.name}/vendor/ImGuizmo/ImGuizmo.cpp",
			"%{prj.name}/vendor/FastNoise/**.cpp",
			"%{prj.name}/vendor/yaml-cpp/src/**.cpp",
			"%{prj.name}/vendor/yaml-cpp/src/**.h",
			"%{prj.name}/vendor/yaml-cpp/include/**.h"

    		}
    		
    		defines
		{
			"_CRT_SECURE_NO_WARNINGS",
			"IMGUI_DEFINE_MATH_OPERATORS",
			"NOMINMAX"
		}


    		includedirs
		{
			"%{prj.name}/src",
        		"%{prj.name}/vendor",
          		"%{prj.name}/vendor/assimp/include",
        		"%{prj.name}/vendor/spdlog/include",
        		"%{prj.name}/vendor/stb/include",
        		"%{prj.name}/vendor/yaml-cpp/include",
        		
        		"%{IncludeDir.GLFW}",
        		"%{IncludeDir.Glad}",
        		"%{IncludeDir.glm}",
        		"%{IncludeDir.ImGui}",
        		"%{IncludeDir.ImGuizmo}",
        		"%{IncludeDir.entt}",
        		"%{IncludeDir.FastNoise}",
        		"%{IncludeDir.mono}",
        		"%{IncludeDir.Box2D}"
     		}
    
    		links 
		{ 
        		"GLFW",
        		"Glad",
        		"ImGui",
        		"Box2D",
			"opengl32.lib",
			"%{LibraryDir.mono}"
    		}
    		
    		filter "files:Jasmine/vendor/yaml-cpp/src/**.cpp"
   		flags { "NoPCH" }
	
    
    		filter "files:Jasmine/vendor/ImGuizmo/**.cpp"
		flags { "NoPCH" }
		
		filter "files:Jasmine/vendor/FastNoise/**.cpp"
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
      
      ------Project--------------- 		
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
		
	
  	------Group-Tool-----------------------------------------------------------
  	group "Tool"
  	
  	------Project---------------
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
				'{COPY} "../Jasmine/vendor/assimp/bin/Debug/assimp-vc141-mtd.dll" "%{cfg.targetdir}"',
				'{COPY} "../Jasmine/vendor/mono/bin/mono-2.0-sgen.dll" "%{cfg.targetdir}"'
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
				'{COPY} "../Jasmine/vendor/assimp/bin/Release/assimp-vc141-mt.dll" "%{cfg.targetdir}"',
				'{COPY} "../Jasmine/vendor/mono/bin/mono-2.0-sgen.dll" "%{cfg.targetdir}"'
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
				'{COPY} "../Jasmine/vendor/assimp/bin/Release/assimp-vc141-mt.dll" "%{cfg.targetdir}"',
				'{COPY} "../Jasmine/vendor/mono/bin/mono-2.0-sgen.dll" "%{cfg.targetdir}"'
			}
			
	group ""
	
	
	------Group-Examples------------------------------------------------------
	group "Examples"
	
	------Project--------------
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
