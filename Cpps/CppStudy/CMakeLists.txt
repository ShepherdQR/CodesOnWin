#************
#  * @Author: Shepherd Qirong
#  * @Date: 2021-06-14 22:17:32
#  * @Github: https://github.com/ShepherdQR
#  * @LastEditors: Shepherd Qirong
#  * @LastEditTime: 2021-08-18 21:53:37
#  * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
#************


cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
PROJECT(CppStudy)

#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
#add_library(GLAD "./openglstudying/include/glad.c")


file(GLOB cpp_executable *.cpp)

file(GLOB cpp_class ./ClassCollections/*.cpp)
include_directories(./ClassCollections)

message("Building the main cpp: " ${cpp_executable})
add_executable(main ${cpp_executable} ${cpp_class})

# ./openglstudying/include/stb_image.cpp

target_link_libraries(main)
#${OPENGL_LIBRARIES} ${GLUT_LIBRARY} glfw GLAD ${PCL_LIBRARIES}