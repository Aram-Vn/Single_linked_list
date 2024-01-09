cmake_minimum_required(VERSION 3.10)
project("SingleLinkedList" LANGUAGES CXX)

#Single_linked_list  graph
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(GLOB_RECURSE HPP_FILES "src/*.hpp")
file(GLOB_RECURSE HDR_FILES "src/*.h")

add_library(Single_linked_list ${SRC_FILES} ${HPP_FILES} ${HDR_FILES})
