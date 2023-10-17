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

	include "Jasmine/vendor/GLFW"
	include "Jasmine/vendor/Glad"
	include "Jasmine/vendor/ImGui"

	--------------------------------------------------------------------
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
			"%{prj.name}/src/**.cpp" 
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
        		"%{prj.name}/vendor/stb/include"
    		}
    
    		links 
		{ 
        		"GLFW",
        		"Glad",
        		"ImGui",
			"opengl32.lib"
    		}
    
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

  	--------------------------------------------------------------------
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
        		"Jasmine/src",
        		"Jasmine/vendor",
        		"%{IncludeDir.glm}"
    		}
	
		filter "system:windows"
        		systemversion "latest"
                
		defines 
		{ 
            	"JM_PLATFORM_WINDOWS"
		}
    
    		filter "configurations:Debug"
        		defines "JM_DEBUG"
        		symbols "on"
        		links
			{
				"Jasmine/vendor/assimp/bin/Debug/assimp-vc141-mtd.lib"
			}
                
    		filter "configurations:Release"
        		defines "JM_RELEASE"
        		optimize "on"
        		links
			{
				"Jasmine/vendor/assimp/bin/Release/assimp-vc141-mt.lib"
			}

    		filter "configurations:Dist"
        		defines "JM_DIST"
        		optimize "on"
        		links
			{
				"Jasmine/vendor/assimp/bin/Release/assimp-vc141-mt.lib"
			}

	--------------------------------------------------------------------
	project "Sandbox"
    		location "Sandbox"
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
        		"Jasmine/src",
        		"Jasmine/vendor",
        		"%{IncludeDir.glm}"
    		}
	
		filter "system:windows"
        		systemversion "latest"
                
		defines 
		{ 
            	"JM_PLATFORM_WINDOWS"
		}
    
    		filter "configurations:Debug"
        		defines "JM_DEBUG"
        		symbols "on"
        		links
			{
				"Jasmine/vendor/assimp/bin/Debug/assimp-vc141-mtd.lib"
			}
                
    		filter "configurations:Release"
        		defines "JM_RELEASE"
        		optimize "on"
        		links
			{
				"Jasmine/vendor/assimp/bin/Release/assimp-vc141-mt.lib"
			}

    		filter "configurations:Dist"
        		defines "JM_DIST"
        		optimize "on"
        		links
			{
				"Jasmine/vendor/assimp/bin/Release/assimp-vc141-mt.lib"
			}

