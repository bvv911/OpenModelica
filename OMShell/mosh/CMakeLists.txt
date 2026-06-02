


# We have our own module for this. CMake does not provide one yet.
find_package(Readline REQUIRED)

set(OMSHELL_TERMINAL_SOURCES src/mosh.cpp
                             src/omcinteractiveenvironment.cpp
                             src/options.cpp)

add_executable(OMShell-terminal ${OMSHELL_TERMINAL_SOURCES})

target_link_libraries(OMShell-terminal PRIVATE OpenModelicaCompiler)
target_link_libraries(OMShell-terminal PRIVATE Readline::Readline)
# Include paths only — runtime symbols live in libOpenModelicaCompiler (MSVC: do not link omc::simrt::runtime).
target_link_libraries(OMShell-terminal PRIVATE omc::simrt::runtime::headers)

if(MSVC)
  # Import MetaModelica/runtime symbols from the OMC DLL (see omc_init.h / openmodelica.h).
  target_compile_definitions(OMShell-terminal PRIVATE IMPORT_INTO=1)
  target_compile_definitions(OMShell-terminal PRIVATE WIN32_LEAN_AND_MEAN)
endif()

# This one belongs in its own component. It does not have anything to do
# with OMShell (GUI) and should be installable separately.
install(TARGETS OMShell-terminal
        COMPONENT omshellterminal)
