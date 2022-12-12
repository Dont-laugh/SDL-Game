set_project "SDL-Game"
set_version "0.1"
set_languages "c++17"

add_rules("mode.debug", "mode.release")
set_defaultmode("debug")
set_defaultarchs("macosx|arm64", "windows|x64")

if is_plat("windows") then
    add_rules "plugin.vsxmake.autoupdate"
end

add_requires("libsdl 2.x", "libsdl_image 2.x")

if is_mode("debug") then
    add_defines "DEBUG"
    set_symbols "debug"
    set_optimize "none"
else
    set_symbols "hidden"
    set_optimize "faster"
end

target "Engine"
    set_kind "binary"
    add_packages("libsdl", "libsdl_image")

    add_includedirs "Engine/include"
    add_headerfiles("Engine/include/*.h", "Engine/include/*.hpp")
    add_files "Engine/src/*.cpp"

    set_targetdir "intermediate/binary"
    set_objectdir "intermediate/obj"

    after_build(function()
        os.cp("Engine/assets", "intermediate/binary")
    end)
target_end()
