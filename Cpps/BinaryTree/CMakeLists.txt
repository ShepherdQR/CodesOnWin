

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
PROJECT(MyBinaryTree)

#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")



#add_library(GLAD "./openglstudying/include/glad.c")

file(GLOB cpp_executable *.cpp)
file(GLOB cpp_class ./ClassCollections/*.cpp)

include_directories(./ClassCollections) #ָ��ͷ�ļ�Ŀ¼

message("Building the main cpp: " ${cpp_executable})
add_executable(main ${cpp_executable} ${cpp_class})
# ./openglstudying/include/stb_image.cpp



target_link_libraries(main )#${OPENGL_LIBRARIES} ${GLUT_LIBRARY} glfw GLAD ${PCL_LIBRARIES}