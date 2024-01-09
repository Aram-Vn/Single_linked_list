cmake_minimum_required(VERSION 3.10)
project("SingleLinkedList")

# Unweighted graph
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(GLOB_RECURSE HPP_FILES "src/*.hpp")
file(GLOB_RECURSE HDR_FILES "src/*.h")

add_library(linked_list_app ${SRC_FILES} ${HPP_FILES} ${HDR_FILES})
