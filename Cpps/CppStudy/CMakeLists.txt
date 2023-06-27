#************
#  * @Author: Shepherd Qirong
#  * @Date: 2021-06-14 22:17:32
#  * @Github: https://github.com/ShepherdQR
#  * @LastEditors: Shepherd Qirong
#  * @LastEditTime: 2023-06-28 00:06:19
#  * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
#************


cmake_minimum_required(VERSION 3.10 FATAL_ERROR)


#SET(CMAKE_C_COMPILER "C:/Softwares/Cygwin64/bin/gcc.exe")
#SET(CMAKE_CXX_COMPILER "C:/Softwares/Cygwin64/bin/gcc++.exe")





#SET(CMAKE_C_COMPILER "C:/Softwares/llvm/llvm1507/LLVM/bin/clang.exe")
#SET(CMAKE_CXX_COMPILER "C:/Softwares/llvm/llvm1507/LLVM/bin/clang.exe")
# SET (CMAKE_CXX_FLAGS                "-Wall -std=c++2b")

# add_compile_options(-std=c++2b)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
message("-- CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message("-- CMAKE_CXX_COMPILER_VERSION: ${CMAKE_CXX_COMPILER_VERSION}")

PROJECT(CppStudy VERSION 1.0)

#add_compile_options(-fcoroutines)
#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "-O2 -DASIO_STANDALONE -Werror")
#set(CMAKE_CXX_FLAGS "-pthread")


# include_directories(${PROJECT_SOURCE_DIR})
# add_subdirectory(./ClassCollections)
# add_subdirectory(./RayTracing)
# add_subdirectory(../myTools)
# list (APPEND list_cpp_executable  *.cpp)
# # list (APPEND list_cpp_executable  ./ClassCollections/*.cpp)
# # list (APPEND list_cpp_executable  ./RayTracing/*.cpp)
# # file(GLOB cpp_executable ${list_cpp_executable})
# add_executable(main  ${cpp_executable} )
# target_link_libraries (a b c)


include_directories(./ClassCollections)
include_directories(./RayTracing)
include_directories(../myTools)
include_directories(../Universe/Mathematics/basic)
include_directories(../Universe/Mathematics/test)
include_directories(./Universe/Algorithm/interface)
# include_directories(./Universe/Algorithm/src)


add_subdirectory(./Universe/Algorithm/src)


list (APPEND list_cpp_executable  *.cpp)

# list (APPEND list_cpp_shared  ../Universe/Algorithm/src/*.cpp)
list (APPEND cpp_executable  ./ClassCollections/*.cpp)
list (APPEND cpp_executable  ./RayTracing/*.cpp)
file(GLOB cpp_executable ${list_cpp_executable})

add_executable(main ${cpp_executable} )
target_link_libraries(main algorithm)


################################


# target_include_directories(TestForward PUBLIC
#                            "${PROJECT_BINARY_DIR}"
#                            )

#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
#add_library(GLAD "./openglstudying/include/glad.c")

#message("Building the main cpp: " ${cpp_executable})

#file(GLOB cpp_executable *.cpp)

#file(GLOB cpp_class ./ClassCollections/*.cpp)
#include_directories(./ClassCollections)

# ./openglstudying/include/stb_image.cpp

#${OPENGL_LIBRARIES} ${GLUT_LIBRARY} glfw GLAD ${PCL_LIBRARIES}
#target_link_libraries(main)