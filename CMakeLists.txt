cmake_minimum_required(VERSION 3.10)

project(Io_Multiplexing)

set(CMAKE_CXX_STANDARD 11)

include_directories(select/)
add_subdirectory(poll)
add_executable(main main.cpp)
target_link_libraries(main Poll)