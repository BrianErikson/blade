cmake_minimum_required(VERSION 3.7)
project(blade)
set(CMAKE_BUILD_TYPE DEBUG)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

set(SOURCE_FILES src/blade.c src/blade.h src/io.c src/io.h)
include_directories(
        ${OPENGL_INCLUDE_DIRS}
        ${GLEW_INCLUDE_DIRS}
        ${GLFW_INCLUDE_DIRS}
        /usr/local/include/
)

add_library(blade STATIC ${SOURCE_FILES})

target_link_libraries(blade
        ${OPENGL_LIBRARIES}
        ${GLFW_LIBRARIES}
        ${GLEW_LIBRARIES}
        m
        /usr/local/lib/libgl-matrix.a
)

add_executable(bladeTest test/main.c)
add_dependencies(bladeTest blade)

target_link_libraries(bladeTest blade)
