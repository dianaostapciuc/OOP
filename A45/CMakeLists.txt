cmake_minimum_required(VERSION 3.24)
project(a45_xdianaost)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a45_xdianaost
        dynamic_array.cpp
        dynamic_array.h domain.h domain.cpp repository.h repository.cpp services.h services.cpp ui.h ui.cpp tests.cpp)
