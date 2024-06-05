cmake_minimum_required(VERSION 3.9)
project(GB_C++)

set(CMAKE_CXX_STANDARD 17)

set(cpr_DIR "D:/C-All-Projects/build/_deps/cpr-src/")

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba)
FetchContent_MakeAvailable(cpr)

add_executable(GB_C++ main.cpp)

find_package(cpr CONFIG REQUIRED)
include_directories(${CPR_INCLUDE_DIRS})
target_link_libraries(GB_C++ PRIVATE cpr::cpr)