--  ============================================================
--  Makefile build rules for premake5:
--  ============================================================


--  ============================================================
--  > cpp.make
--  module tests and system tests at once runtime
--  ->  bin/cpp
--  ============================================================
workspace 'cpp'
    configurations { 'ci' }
    language    'C++'
    objdir      'obj/%{prj.name}'

--    buildoptions { '-std=c++2a -pedantic-errors -fconcepts' }
    filter { "action:gmake2" }
        buildoptions { '-std=c++17 -pedantic-errors -fconcepts' }
    filter { "action:vs*" }
        buildoptions { '/std:c++17' }
        
    linkoptions { '-pthread' }

    project 'cpp'
        kind        'ConsoleApp'
        targetdir   'bin'

        files { 
            '../code/**.cpp'
        }

        defines { 'NDEBUG' }
        optimize 'On'
