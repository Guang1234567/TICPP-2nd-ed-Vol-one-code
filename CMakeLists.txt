cmake_minimum_required(VERSION 3.12)
project(TICPP_2nd_ed_Vol_one_code)

set(CMAKE_CXX_STANDARD 14)

# cc1plus.exe: warning: command line option '-Wmissing-prototypes' is valid for C/ObjC but not for C++
# set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wconversion -Wcast-qual -Wshadow -Wpointer-arith -Wunreachable-code -Wstrict-prototypes -Wmissing-prototypes")
add_definitions(${GXX_COVERAGE_COMPILE_FLAGS})
set(GXX_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wconversion -Wcast-qual -Wshadow -Wpointer-arith -Wunreachable-code -Wstrict-prototypes")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GXX_COVERAGE_COMPILE_FLAGS}" )

include_directories(.)
include_directories(C02)
include_directories(C03)
include_directories(C04)
include_directories(C05)
include_directories(C06)
include_directories(C07)
include_directories(C08)
include_directories(C09)
include_directories(C10)
include_directories(C11)
include_directories(C12)
include_directories(C13)
include_directories(C14)
include_directories(C15)
include_directories(C16)


add_executable(sizeof C03/sizeof.cpp)

add_executable(static_cast C03/static_cast.cpp)

add_executable(PointersAndBrackets C03/PointersAndBrackets.cpp)

add_executable(ArrayArguments C03/ArrayArguments.cpp)
