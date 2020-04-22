cmake_minimum_required(VERSION 3.1.0)

project(FloatXTest VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cc)
target_include_directories(main PUBLIC lib/FloatX/src lib/eigen ${CMAKE_CURRENT_LIST_DIR})