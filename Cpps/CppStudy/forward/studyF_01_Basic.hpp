/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-07-10 22:08:32
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-07-10 22:50:15
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#pragma once

#include<iostream>
using namespace std;

namespace Basic{

    auto func_1(){

        struct S{
            int i;
            float j{};
            double d;
            //S():d(1.),i(2){}// The constructor disables the field designators
        };

        //S s1{i:1,d:3.2};//warning: use of GNU old-style field designator extension [-Wgnu-designator]
        S s2{.i=1,.j=2.};std::cout << s2.d << std::endl;
        
        S s3{.j = 2.};std::cout << s3.j << std::endl;
        S s4{.j = 2};std::cout << s4.j << std::endl;

        //S s4{.j = 3., .i=11};std::cout << s4.j << std::endl;//warning: ISO C++ requires field designators to be specified in declaration order;

        [](S is){
            cout << is.d << endl;
        }({.d = 5});
        
    }
}