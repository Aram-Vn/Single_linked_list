# CMakeLists.txt

cmake_minimum_required(VERSION 3.12)
project(Single_linked_list)

#add compile_commands.json for vscode
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

# Add the source files
set(SOURCES
    src/Single_linked_list.h
    src/Single_linked_list_impl.hpp
    src/main.cpp
)

# Create an executable
add_executable(Single_linked_list_app ${SOURCES})