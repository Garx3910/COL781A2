cmake_minimum_required(VERSION 3.0)

project(a2)
set(CMAKE_CXX_STANDARD 11)

find_package(glm REQUIRED)
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

add_library(viewer src/hw.cpp src/viewer.cpp src/mesh.cpp src/parser.cpp deps/src/gl.c)
target_include_directories(viewer PUBLIC deps/include)
target_link_libraries(viewer glm::glm OpenGL::GL SDL2::SDL2)

add_executable(example src/example.cpp)
target_link_libraries(example viewer)

add_executable(mesh_example1 src/mesh_example1.cpp)
target_link_libraries(mesh_example1 viewer)

add_executable(mesh_example2 src/mesh_example2.cpp)
target_link_libraries(mesh_example2 viewer)

add_executable(parser_example src/parser_example.cpp)
target_link_libraries(parser_example viewer)

add_executable(mesh_smooth_example1 src/mesh_smooth_example1.cpp)
target_link_libraries(mesh_smooth_example1 viewer)

add_executable(mesh_smooth_example2 src/mesh_smooth_example2.cpp)
target_link_libraries(mesh_smooth_example2 viewer)