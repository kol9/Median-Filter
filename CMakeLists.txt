cmake_minimum_required(VERSION 3.16)
project(MedianFilter)

set(CMAKE_CXX_STANDARD 11)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(MedianFilter main.cpp MedianFilter.h MedianFilter.cpp)
target_link_libraries(MedianFilter ${OpenCV_LIBS})