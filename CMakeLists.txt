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
  ~/apps/SDL/include/SDL2
)

link_directories (
  ${SHOOTER_BINARY_DIR}
  ~/apps/SDL/lib
)

add_library(engine SHARED
  src/core/game.cc
  src/core/graphics.cc
  src/core/point.cc
  src/core/pointf.cc
  src/core/rect.cc
  src/core/rectf.cc
  src/core/size.cc
  src/core/sizef.cc
  src/core/sounds.cc
  src/core/sprite.cc
  src/core/timer.cc
)

target_link_libraries (engine
  SDL2
  openal
  vorbisfile
)

add_executable (shooter
  src/enemy.cc
  src/entityfactory.cc
  src/explosion.cc
  src/introstate.cc
  src/main.cc
  src/player.cc
  src/playstate.cc
  src/projectile.cc
  src/star.cc
)

target_link_libraries (shooter
  engine
)
