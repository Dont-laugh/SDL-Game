set_project "SDL-Game"
set_version "0.1.0"
set_languages "c++17"

add_rules("mode.debug", "mode.release")
add_rules "plugin.vsxmake.autoupdate"
set_defaultmode "debug"
set_defaultarchs "x64"

add_requires("libsdl 2.x")

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
    add_packages "libsdl"

    add_includedirs "Engine/include"
    add_headerfiles("Engine/include/*.h", "Engine/include/*.hpp")
    add_files "Engine/src/*.cpp"

    set_targetdir "intermediate/binary"
    set_objectdir "intermediate/obj"
target_end()
