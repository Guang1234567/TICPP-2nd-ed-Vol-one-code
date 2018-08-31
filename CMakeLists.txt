cmake_minimum_required(VERSION 3.12)
project(TICPP_2nd_ed_Vol_one_code)

set(CMAKE_CXX_STANDARD 14)

# cc1plus.exe: warning: command line option '-Wmissing-prototypes' is valid for C/ObjC but not for C++
# set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wconversion -Wcast-qual -Wshadow -Wpointer-arith -Wunreachable-code -Wstrict-prototypes -Wmissing-prototypes")
add_definitions(${GXX_COVERAGE_COMPILE_FLAGS})
set(GXX_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wconversion -Wcast-qual -Wshadow -Wpointer-arith -Wunreachable-code")
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


add_executable(sizeof_C03 C03/sizeof.cpp)

add_executable(static_cast C03/static_cast.cpp)

add_executable(PointersAndBrackets C03/PointersAndBrackets.cpp)

add_executable(ArrayArguments C03/ArrayArguments.cpp)

add_executable(CommandLineArgs C03/CommandLineArgs.cpp)

add_executable(ArgsToInts C03/ArgsToInts.cpp)

add_executable(FloatingAsBinary C03/FloatingAsBinary.cpp C03/printBinary.cpp)

add_executable(Specify C03/Specify.cpp)

add_executable(PointerArithmetic C03/PointerArithmetic.cpp)

add_executable(ComplicatedDefinitions C03/ComplicatedDefinitions.cpp)

add_executable(CLibTest C04/CLibTest.cpp C04/CLib.cpp)

add_executable(CppLibTest_C04 C04/CppLibTest.cpp C04/CppLib.cpp)

add_executable(Sizeof C04/Sizeof.cpp C04/CppLib.cpp C04/CLib.cpp)

add_executable(StackTest C04/StackTest.cpp C04/CppLib.cpp C04/Stack.cpp)

add_executable(NestFriend C05/NestFriend.cpp)

add_executable(CppLibTest_C05 C05/CppLibTest.cpp C05/CppLib.cpp)

add_executable(TestSharePointer C05/TestSharePointer.cpp)

add_executable(Boolean C03/Boolean.cpp)

add_executable(Constructor1 C06/Constructor1.cpp)

add_executable(Nojump C06/Nojump.cpp)

add_executable(Stash2Test C06/Stash2Test.cpp C06/Stash2.cpp C06/Stash2.h)

add_executable(AutoDefaultConstructor C06/AutoDefaultConstructor.cpp)
