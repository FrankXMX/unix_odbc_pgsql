cmake_minimum_required (VERSION 2.6)
project (otlodbc)

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_BUILD_TYPE Debug)
include_directories(./)
include_directories(/usr/local/unixodbc/include)

add_executable(otlodbc otlodbc.cpp)
link_directories("/usr/local/psqlodbc/lib")
target_link_libraries(otlodbc /usr/local/psqlodbc/lib/psqlodbca.so)