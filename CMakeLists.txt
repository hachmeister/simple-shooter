cmake_minimum_required (VERSION 2.6)

project(SHOOTER)

# Set default build type.
if (CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "[Debug|Release|RelWithDebInfo|MinSizeRel]" FORCE)
endif()

# Set default install prefix.
if (CMAKE_INSTALL_PREFIX STREQUAL "/usr/local")
  set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}")
endif()

# Set flags.
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

include_directories(
  ${SHOOTER_SOURCE_DIR}/include
  ~/apps/sdl-2.0/include/SDL2
)

link_directories (
  ${SHOOTER_BINARY_DIR}
  ~/apps/sdl-2.0/lib
)

add_executable (shooter
  src/enemy.cc
  src/entityfactory.cc
  src/game.cc
  src/graphics.cc
  src/main.cc
  src/player.cc
  src/rect.cc
  src/shooter.cc
  src/sprite.cc
  src/star.cc
  src/timer.cc
  src/vector2.cc
)

target_link_libraries (shooter
  SDL2
)
