#************
#  * @Author: Shepherd Qirong
#  * @Date: 2021-06-14 22:17:32
#  * @Github: https://github.com/ShepherdQR
#  * @LastEditors: Shepherd Qirong
#  * @LastEditTime: 2022-01-17 22:55:43
#  * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
#************


cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
PROJECT(CppStudy)


include_directories(./ClassCollections)
include_directories(./RayTracing)
include_directories(../myTools)

list (APPEND list_cpp_executable  *.cpp)
list (APPEND list_cpp_executable  ./ClassCollections/*.cpp)
list (APPEND list_cpp_executable  ./RayTracing/*.cpp)

file(GLOB cpp_executable ${list_cpp_executable})

add_executable(main  ${cpp_executable} )



################################
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
#add_library(GLAD "./openglstudying/include/glad.c")

#message("Building the main cpp: " ${cpp_executable})

#file(GLOB cpp_executable *.cpp)

#file(GLOB cpp_class ./ClassCollections/*.cpp)
#include_directories(./ClassCollections)

# ./openglstudying/include/stb_image.cpp

#${OPENGL_LIBRARIES} ${GLUT_LIBRARY} glfw GLAD ${PCL_LIBRARIES}
#target_link_libraries(main)