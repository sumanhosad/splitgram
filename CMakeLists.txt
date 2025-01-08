cmake_minimum_required(VERSION 3.31)

# Project name
project(Splitgram)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(includes)

# Add executables
add_executable(Splitgram app.cpp src/home.cc)
add_executable(server server.cpp src/server.cc)
add_executable(client client.cpp src/client.cc)
add_executable(crypto crypto.cpp src/cryptography.cc)

# Find and link GTKMM
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
target_link_libraries(Splitgram ${GTKMM_LIBRARIES})

# Find and link Crypto++
find_library(CRYPTOPP_LIBRARY cryptopp REQUIRED)
include_directories(/usr/include/cryptopp)
include_directories(/usr/include/openssl)
link_directories(/usr/lib)


