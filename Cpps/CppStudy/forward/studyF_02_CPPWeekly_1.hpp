/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2024-06-19 23:41:03
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2024-06-20 00:16:02
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

// #pragma once
_Pragma("once");

#include <iostream>
#include <functional>
#include <memory>
#include <limits>
#include <ranges>


namespace CPPWeekly{


    auto func_999_Mark3(){


    }

    auto func_001(){
        std::cout << "20240619" << std::endl;
        /*
        refactor:
        1. class member change
        
        1.1 string only using as .cstr(), replaced with: constexpr const char* const

        1.2 vector only store 11 keys, replaced with:
        const array<T,11>&, and generate a static function AA to generate the array, the static array is within the scope of function AA. 

        1.3 T[][], replaced with:
            using array<array<bool>,a>b> = TT
            static constexpr TT F3();// generates local the array of type TT;
            static const TT& F4();//
            returns the local array of type static const TT = F3();
            T[][] -> const TT& temp = F4();

        Q1: array fill each element with false, is function fill constexpr now? If not, who to accomplish in a constexpr way?
        
        
        */ 
    }


}
