cmake_minimum_required(VERSION 3.20)

project(game)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib REQUIRED)

set(SOURCES
    src/main.cpp
    src/game.cpp
    src/grid.cpp
    src/screen.cpp
)

set(HEADERS
    src/game.hpp
    src/grid.hpp
    src/screen.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} raylib)