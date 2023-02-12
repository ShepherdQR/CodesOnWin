/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-07-10 22:03:35
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-02-12 22:43:46
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

//import studyF_Module;
#include<iostream>
#include"studyF_01_Basic.hpp"

//#include"studyF_04_Thread.hpp"
//#include"studyF_02_Template.hpp"
//#include"studyF_03_STL.hpp"

#include"../../myTools/Parser.h"

// test Mathematics begins ...
#include"../../Universe\Mathematics\basic\Matrix.h"
#include"../../Universe\Mathematics\test\testBasic.h"
// test Mathematics ends ...

//#include"studyF_ThreadPool.hpp"

auto main()->int{


    // bool ibCompile_YESGNUC11_3__and_NOclang15_0{false};
    // #ifndef __clang__
    //     ibCompile_YESGNUC11_3__and_NOclang15_0 = true;
    // #else

    // #ifdef __clang_major__ // __clang_major__   __clang_minor__
    //     ibCompile_YESGNUC11_3__and_NOclang15_0 = bool(__clang_major__>15);
    // #endif

    // #endif
    // std::cout << ibCompile_YESGNUC11_3__and_NOclang15_0 << std::endl;
    

    // [20230201, clang15.0 = 202101, gcc11.30 = 202100]
    std::cout <<__cplusplus <<std::endl;//[20220411, c++17][20220927, 202100]
	std::cout << "Hi<" << std::endl;

    #include"TestFF.hpp"

    std::cout << "\n>Bye." << std::endl;
    return 0;
}
