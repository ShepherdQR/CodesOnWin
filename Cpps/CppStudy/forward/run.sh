#! /bin/bash
#************
#  * @Author: Shepherd Qirong
#  * @Date: 2022-07-18 21:19:56
#  * @Github: https://github.com/ShepherdQR
#  * @LastEditors: Shepherd Qirong
#  * @LastEditTime: 2022-08-13 20:57:12
#  * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
#************
# -xc++-system-header -fmodules-ts ../studyF_Module.cc 
clear && cd ./build && g++ -std=c++2b -O0 -Wall -Wno-unused-variable ../Test.cpp && ./a.exe && cd ..