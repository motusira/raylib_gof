cmake_minimum_required(VERSION 3.20)

project(game)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib REQUIRED)

set(SOURCES
    src/main.cpp
    src/game/game.cpp
    src/grid/grid.cpp
    src/window/window.cpp
    src/cam/cam.cpp
    src/ui/ui.cpp
    src/input_handler/input_handler.cpp

)

set(HEADERS
    src/game/game.hpp
    src/grid/grid.hpp
    src/window/window.hpp
    src/cam/cam.hpp
    src/ui/ui.hpp
    src/input_handler/input_handler.hpp
    src/raygui.h
)

set(CMAKE_CXX_FLAGS "-Wstrict-prototypes -Wall -Wextra -Wmissing-prototypes")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} raylib)