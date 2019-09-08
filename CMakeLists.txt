cmake_minimum_required(VERSION 3.7)
project(blade)
set(CMAKE_BUILD_TYPE DEBUG)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(CGLM REQUIRED cglm)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

set(HEADERS
    src/blade.h
    src/io.h
)

set(SOURCE
    src/blade.c
    src/io.c
)

include_directories(
    ${OPENGL_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
    ${CGLM_INCLUDE_DIRS}
)

add_library(blade STATIC ${SOURCE})

target_link_libraries(blade
    ${OPENGL_LIBRARIES}
    ${GLFW_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${CGLM_LIBRARIES}
)

add_executable(bladeTest test/main.c)
add_dependencies(bladeTest blade)

target_link_libraries(bladeTest blade)
