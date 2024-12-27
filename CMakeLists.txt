# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Splitgram)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find the required GTKmm package
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

# Add your source files
set(SOURCES
    main.cpp
    includes/Home.cc
)

# Add the executable
add_executable(main ${SOURCES})

# Link the GTKmm libraries
target_link_libraries(main PRIVATE ${GTKMM_LIBRARIES})

# Include the necessary directories
target_include_directories(main PRIVATE ${GTKMM_INCLUDE_DIRS} includes)

# Optionally, if you have additional include directories
# target_include_directories(main PRIVATE includes)

# Install command if needed
# install(TARGETS main DESTINATION /usr/local/bin)

