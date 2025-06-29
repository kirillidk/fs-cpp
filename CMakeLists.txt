cmake_minimum_required(VERSION 3.20)
project(fs-lib VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(fs-lib src/file_manager.cpp)

target_include_directories(fs-lib PUBLIC include)