gitVersioningCommand = "git describe --tags --dirty --always"
gitCurrentBranchCommand = "git symbolic-ref -q --short HEAD"

-- Quote the given string input as a C string
function cstrquote(value)
	if value == nil then
		return "\"\""
	end
	result = value:gsub("\\", "\\\\")
	result = result:gsub("\"", "\\\"")
	result = result:gsub("\n", "\\n")
	result = result:gsub("\t", "\\t")
	result = result:gsub("\r", "\\r")
	result = result:gsub("\a", "\\a")
	result = result:gsub("\b", "\\b")
	result = "\"" .. result .. "\""
	return result
end

dependencies = {
	basePath = "./dependencies"
}

function dependencies.load()
	dir = path.join(dependencies.basePath, "premake/*.lua")
	deps = os.matchfiles(dir)

	for i, dep in pairs(deps) do
		dep = dep:gsub(".lua", "")
		require(dep)
	end
end

function dependencies.imports()
	for i, proj in pairs(dependencies) do
		if type(i) == 'number' then
			proj.import()
		end
	end
end

function dependencies.projects()
	for i, proj in pairs(dependencies) do
		if type(i) == 'number' then
			proj.project()
		end
	end
end

newoption {
	trigger = "copy-to",
	description = "Optional, copy the DLL to a custom folder after build, define the path here if wanted.",
	value = "PATH"
}

-- dependencies.load()

workspace "Proxima"
	startproject "Proxima"
	location "./build"
	objdir "%{wks.location}/obj"
	targetdir "%{wks.location}/bin/%{cfg.platform}/%{cfg.buildcfg}"

	configurations {"Debug", "Release"}

	language "C++"
	cppdialect "C++latest"

	architecture "x86"
	platforms "Win32"

	systemversion "latest"
	symbols "On"
	staticruntime "On"
	editandcontinue "Off"
	warnings "Extra"
	characterset "MBCS"

	flags {"NoIncrementalLink", "NoMinimalRebuild", "MultiProcessorCompile", "No64BitChecks"}

	filter "platforms:Win*"
		defines {"_WINDOWS", "WIN32"}
	filter {}

	filter "configurations:Release"
		optimize "Size"
		buildoptions {"/GL"}
		linkoptions {"/IGNORE:4702", "/LTCG"}
		defines {"NDEBUG"}
		flags {"FatalCompileWarnings", "FatalLinkWarnings"}

	filter {}

	filter "configurations:Debug"
		optimize "Debug"
		defines {"DEBUG", "_DEBUG"}
	filter {}

	project "Proxima"
		kind "SharedLib"
		targetname "steam_api"
		language "C++"
		links { "iphlpapi" }
		-- rules { "ProtobufCompiler" }
		files {
			"./src/**.rc",
			"./src/**.h*",
			"./src/**.cpp",
			"./src/**.proto"
		}
		includedirs {
			"%{prj.location}/src",
			"./src",
			"./lib/include"
		}
		resincludedirs {
			"$(ProjectDir)src" -- fix for VS IDE
		}

		-- Pre-compiled header
		pchheader "pch.h" -- must be exactly same as used in #include directives
		pchsource "src/pch.cpp" -- real path

		dependencies.imports()

		-- Post-build
		if _OPTIONS["copy-to"] then
			saneCopyToPath = string.gsub(_OPTIONS["copy-to"] .. "\\", "\\\\", "\\")
			postbuildcommands {
				"if not exist \"" .. saneCopyToPath .. "\" mkdir \"" .. saneCopyToPath .. "\"",
			}

			if _OPTIONS["copy-pdb"] then
				postbuildcommands {
					"copy /y \"$(TargetDir)*.pdb\" \"" .. saneCopyToPath .. "\"",
				}
			end

			-- This has to be the last one, as otherwise VisualStudio will succeed building even if copying fails
			postbuildcommands {
				"copy /y \"$(TargetDir)*.dll\" \"" .. saneCopyToPath .. "\"",
			}
		end


group "External Dependencies"
dependencies.projects()
