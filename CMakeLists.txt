cmake_minimum_required(VERSION 3.20)

project(game)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(RAYLIB_VERSION 5.5)
find_package(raylib ${RAYLIB_VERSION} QUIET)
if (NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED)
    set(FETCHCONTENT_QUIET NO)
    FetchContent_MakeAvailable(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
  endif()
endif()

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
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)
