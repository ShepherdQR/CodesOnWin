#************
#  * @Author: Shepherd Qirong
#  * @Date: 2024-06-15 16:10:36
#  * @Github: https://github.com/ShepherdQR
#  * @LastEditors: Shepherd Qirong
#  * @LastEditTime: 2024-06-16 11:05:37
#  * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
#************

PROJECT(test_message)

include_directories(
${PROJECT_SOURCE_DIR}/OO
)

file(GLOB HEADER ${CMAKE_CURRENT_SOURCE_DIR}/OO/*.h)
file(GLOB SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/OO/*.cpp)
# file(GLOB SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(
    ${PROJECT_NAME}
    ${HEADER}
    ${SOURCE}
)