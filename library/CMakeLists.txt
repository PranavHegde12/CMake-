cmake_minimum_required(VERSION 3.0)
project(my_library_project)

# Source files
set(SOURCE_FILES
    f.cpp
)

# Create the shared library
add_library(my_library SHARED ${SOURCE_FILES})

# Optionally, include the header files
target_include_directories(my_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})









