cmake_minimum_required(VERSION 3.17)
project(GB_C++)

set(CMAKE_CXX_STANDARD 20)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(GB_C++ main.cpp)

target_link_libraries(GB_C++ PRIVATE nlohmann_json::nlohmann_json)
