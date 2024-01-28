--  ============================================================
--  Makefile / solution build rules for premake5
--  ============================================================

--  ============================================================
--  > cpp.make
--  ->  bin/cpp
--  ============================================================
workspace 'cpp'
    configurations { 'ci' }
    language    'C++'
    objdir      'obj/%{prj.name}'

    includedirs { '../code', '../../DSTW/specification' }

    filter { "action:gmake2" }
        buildoptions { '-std=c++2a -pedantic-errors' }
        -- buildoptions { '-std=c++17 -pedantic-errors' }
        linkoptions { '-pthread' }

    filter { "action:vs*" }
        buildoptions { '/std:c++17' }
        

    project 'cpp'
        kind        'ConsoleApp'
        targetdir   'bin'

        files { 
            '../code/**.cpp'
        }

        defines { 'NDEBUG' }
        optimize 'On'
