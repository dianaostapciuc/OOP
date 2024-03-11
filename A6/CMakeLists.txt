cmake_minimum_required(VERSION 3.24)
project(a6_xdianaost_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a6_xdianaost_1
        domain.cpp
        domain.h
        repository.cpp
        repository.h
        services.cpp
        services.h
        ui.cpp
        ui.h)
