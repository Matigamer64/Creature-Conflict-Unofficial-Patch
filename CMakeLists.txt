cmake_minimum_required(VERSION 3.15)
# Set the Project Name
set(PROJECT_NAME ccpatch)
# Set the name of the target operating system.
set(CMAKE_SYSTEM_NAME Windows)

# Set our output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/binaries/${CMAKE_SYSTEM_NAME})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/binaries/${CMAKE_SYSTEM_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/binaries/${CMAKE_SYSTEM_NAME})

# Set our intermediate directories.
set(CMAKE_BINARY_DIR               ${CMAKE_CURRENT_SOURCE_DIR}/Intermediate/${CMAKE_BUILD_TYPE})
set(CMAKE_BUILD_FILES_DIRECTORY    ${CMAKE_CURRENT_SOURCE_DIR}/Intermediate/${CMAKE_BUILD_TYPE})

set(CMAKE_CXX_STANDARD 17)

# Set a definition for a debug build through CMake. Also includes GDB debugging information.
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -DDEBUG -ggdb3")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -DDEBUG -ggdb3")

# Set compile flags for release builds, this should strip the debug symbols and optimizes it.
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2 -s")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -s")

project(ccpatch)
add_library(ccpatch SHARED 
	dllmain.cpp
)
target_link_libraries(ccpatch PRIVATE psapi)
set(CMAKE_SHARED_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
set_target_properties(ccpatch PROPERTIES PREFIX "" OUTPUT_NAME ccpatch SUFFIX ".asi")
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E remove $<TARGET_FILE_DIR:${PROJECT_NAME}>/*.a)
endif()