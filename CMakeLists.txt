cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(raysnek VERSION 0.1)

message(STATUS "Looking for raylib and fetching if necessary...")
find_package(raylib QUIET)
if(NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 4.5.0
    )
    FetchContent_MakeAvailable(raylib)
endif()

message(STATUS "Looking for raylib_cpp and fetching if necessary...")
find_package(raylib_cpp QUIET)
if(NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG v4.5.1
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})

set(SOURCES
    ${SOURCE_DIR}/main.cxx
    ${SOURCE_DIR}/Game.cxx
    ${SOURCE_DIR}/SceneManager.cxx)
configure_file(${SOURCE_DIR}/config.hxx.in ${SOURCE_DIR}/config.hxx)
add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_cpp)

find_program(IWYU_PATH NAMES include-what-you-use iwyu)
if(IWYU_PATH)
    message(STATUS "include-what-you-use found and enabled")
    set_property(
        TARGET raysnek
        PROPERTY CXX_INCLUDE_WHAT_YOU_USE ${IWYU_PATH}
    )
else()
    message(STATUS "include-what-you-use not found")
endif()

# TODO: implement iwyu-fix-includes support
