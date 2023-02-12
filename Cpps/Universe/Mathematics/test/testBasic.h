/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-02-12 21:44:08
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-02-12 22:43:56
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

//#include "..\basic\Matrix.h"

#include <iostream>

namespace TestBasic{

    using namespace Universe;

    auto func_999(){

    }

    auto func_1(){
        Matrix<int, 2,3> m1;
        Matrix<int, 3,2> m2({
            {1,2},
            {3,4},
            {5,6}
            });

        std::cout << m2 << std::endl;
        
    }


}