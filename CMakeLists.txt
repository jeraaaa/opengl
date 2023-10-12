cmake_minimum_required(VERSION 3.7...3.27)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(SOURCES src/main.cpp)

project(gltest LANGUAGES CXX)

find_package(SDL2 REQUIRED)
include_directories(game ${SDL2_INCLUDE_DIRS})
link_libraries(${SDL2_LIBRARIES})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

add_executable(game ${SOURCES})