cmake_minimum_required(VERSION 3.16)

project(ponger VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx"
)

add_executable(ponger ${PROJECT_SOURCES})

set(SFML_STATIC_LIBRARIES ON)
find_package(SFML 3 COMPONENTS Graphics REQUIRED CONFIG)

target_link_libraries(ponger PRIVATE SFML::Graphics)

target_include_directories(ponger PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/includes"
)

