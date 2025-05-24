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
    src/window/window.cpp
    src/game_board/game_board.cpp
    src/brick/brick.cpp
    src/utils/utils.cpp
    src/paddle/paddle.cpp
)

set(HEADERS
  src/game/game.hpp
  src/window/window.hpp
  src/game_board/game_board.hpp
  src/brick/brick.hpp
  src/utils/utils.hpp
  src/paddle/paddle.hpp
)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} raylib)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)
