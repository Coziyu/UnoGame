cmake_minimum_required(VERSION 3.0.0)

set(PROJECT_NAME PongGame)
project(${PROJECT_NAME} VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_compile_options(
-Wall
-Wextra
-Wshadow 
-Wnon-virtual-dtor
-Wpedantic
-pedantic
)

set(SOURCEFILES
src/main.cpp
src/state_manager.cpp
src/example_state.cpp
src/state_interface.cpp
src/program.cpp
)

set(HEADERFILES
include/state_manager.hpp
include/example_state.hpp
include/state_interface.hpp
include/program.hpp
)

add_executable(${PROJECT_NAME} ${SOURCEFILES})
target_include_directories(${PROJECT_NAME} PRIVATE include/)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)

find_package(ImGui-SFML CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ImGui-SFML::ImGui-SFML)