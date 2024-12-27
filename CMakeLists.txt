# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set the project name to 'splitgram'
project(splitgram)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find the required GTKmm package
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

# Add your source files (main.cpp and home.cc together)
set(SOURCES
    main.cpp
    includes/home.cc  # Include home.cc here so it's compiled and linked
)

# Add the executable (this will create the splitgram executable)
add_executable(splitgram ${SOURCES})

# Link the GTKmm libraries
target_link_libraries(splitgram PRIVATE ${GTKMM_LIBRARIES})

# Include necessary directories
target_include_directories(splitgram PRIVATE ${GTKMM_INCLUDE_DIRS} includes)

# Optionally, if you have additional include directories
# target_include_directories(splitgram PRIVATE includes)

# Install command if needed
# install(TARGETS splitgram DESTINATION /usr/local/bin)

