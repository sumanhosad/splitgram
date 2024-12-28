cmake_minimum_required(VERSION 3.31)

#project name
project(Splitgram)

#specify c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#include directories
include_directories(includes)

#add executables
add_executable(Splitgram main.cpp src/home.cc)

# Find and link GTKMM
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
target_link_libraries(Splitgram ${GTKMM_LIBRARIES})

