cmake_minimum_required(VERSION 3.7...3.27)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(gltest LANGUAGES CXX)

add_executable(game ${PROJECT_SOURCE_DIR}/src/main.cpp)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(game ${SDL2_LIBRARIES} SDL2_image::SDL2_image ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES})
target_include_directories(game PUBLIC ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/src)