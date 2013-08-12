project(sdatic)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


FIND_PACKAGE(Boost)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
ENDIF()


file(GLOB_RECURSE SOURCES include/*.h include/*.hpp src/*.cpp src/*.h src/*.hpp)

add_library(sdatic SHARED ${SOURCES})
add_executable(sdatic_console src/console.cpp)

target_link_libraries(sdatic_console sdatic)
