#************
#  * @Author: Shepherd Qirong
#  * @Date: 2023-06-27 23:37:40
#  * @Github: https://github.com/ShepherdQR
#  * @LastEditors: Shepherd Qirong
#  * @LastEditTime: 2023-06-27 23:56:35
#  * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
#************
include_directories(../interface)
list (APPEND list_header  ${CMAKE_CUURRENT_SOURCE_DIR}/interface/.*h)
file(GLOB GGheader ${list_header})
list (APPEND list_cpp ${CMAKE_CUURRENT_SOURCE_DIR}/src/.*cpp)
file(GLOB GG_cpp ${list_cpp})


add_library(algorithm SHARED ${GGheader} ${GG_cpp})