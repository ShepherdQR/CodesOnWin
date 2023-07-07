/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-07-01 21:37:45
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-07-01 21:38:35
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


#pragma once
#include <ctime>
#include <vector>
#include <iostream>

namespace Algorithm
{
    inline auto dumpVector(const std::vector<int>& ivec){
        for(auto cur:ivec){
            std::cout << cur << ", ";
        }std::cout << std::endl;
    }
}

