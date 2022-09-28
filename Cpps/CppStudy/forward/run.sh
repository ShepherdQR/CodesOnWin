#! /bin/bash
#************
#  * @Author: Shepherd Qirong
#  * @Date: 2022-07-18 21:19:56
#  * @Github: https://github.com/ShepherdQR
#  * @LastEditors: Shepherd Qirong
#  * @LastEditTime: 2022-09-28 22:10:51
#  * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
#************
# -xc++-system-header -fmodules-ts ../studyF_Module.cc 
# -I./Library/fmt-9.0.0/include -I./Library/fmt-9.0.0/include/src 
# -Wno-unused-variable 
clear && cd ./build && g++ -std=c++2b -O0 -Wall ../Test.cpp && ./a.exe && cd ..