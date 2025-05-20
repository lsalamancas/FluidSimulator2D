cmake_minimum_required(VERSION 3.10)
project(FluidSimulator2D)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

cmake_policy(SET CMP0072 NEW)  # Prefer GLVND (modern OpenGL)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(fluid_sim src/main.cpp src/Renderer.cpp)
target_link_libraries(fluid_sim OpenGL::GL glfw GLEW)


