cmake_minimum_required(VERSION 3.24)
project(a7_xdianaost_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a7_xdianaost_1
        domain.cpp
        domain.h
        repository.cpp
        repository.h
        services.cpp
        services.h
        ui.cpp
        ui.h file_repo.h exceptions.h exceptions.cpp csv_repo.h csv_repo.cpp html_repo.h html_repo.cpp validators.h validators.cpp file_repo.cpp)
