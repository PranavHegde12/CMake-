cmake_minimum_required(VERSION 3.0)
project(main_project)

set(MAIN_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

set(LIBRARY_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../library")

set(LIBRARY_BUILD_DIR "${LIBRARY_SOURCE_DIR}/build")

add_library(
    my_library SHARED IMPORTED
)

set_target_properties(my_library PROPERTIES IMPORTED_LOCATION "${LIBRARY_BUILD_DIR}/libmy_library.so")

add_executable(main_executable ${MAIN_SOURCE_DIR}/main.cpp)

target_include_directories(main_executable PRIVATE "${LIBRARY_SOURCE_DIR}")

target_link_libraries(main_executable PRIVATE my_library)

