/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-02-12 21:44:08
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-06-27 21:36:39
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


//#include "./Mathematics/basic/Matrix.h"
//#include "./Mathematics/basic/Algorithm.hpp"
#include "../basic/Matrix.h"
#include "../basic/Algorithm.hpp"

#include <iostream>

namespace TestBasic{

    using namespace Universe;

    auto func_999(){

    }

    auto func_5(){

        //Universe::BasicAlgorithm::test_002();
        Universe::MatrixFactory::test_001();

    }


    auto func_4(){

        Matrix<double, 3,3> m({
            {8.0,   -3.0,   2.0},
            {4.0,  11.0,   -1.0},
            {6.0,  3.0,   12.0}
            });

        std::cout << 2.0*m << std::endl;
    }

    auto func_3(){
        Matrix<double, 3,3> m({
            {8.0,   -3.0,   2.0},
            {4.0,  11.0,   -1.0},
            {6.0,  3.0,   12.0}
            });
        Matrix<double, 3,1> b({
            {20.0},
            {33.0},
            {36.0}
            });

        auto ans = Iteration::JacobiIteration::solve_01(m,b);
        std::cout << ans << std::endl;
        // ans: [3, 2, 1]^T
        /*
            [times, diff]   15      2.13186e-06
            3,
            2,
            0.999999,
        */
    }

    auto func_2(){
        Matrix<double, 4,4> m({
            {1.,2.,3.,4.},
            {1.,2.,0.,-5.},
            {3.,-1.,-1.,0.},
            {1.,0.,1.,2.}
            });
        Matrix<double, 4,1> b({
            {-3.},
            {1.},
            {1.},
            {-1.}
            });

        auto ans = Elimination::GaussianElimination::solve_01(m,b);
        std::cout << ans << std::endl;
        // ans: 1/12,-1/6,-7/12,-1/4
        /*
            0.0833333,
            -0.166667,
            -0.583333,
            -0.25,
        */
    }


    auto func_1(){
        Matrix<int, 2,3> m1;
        Matrix<int, 3,2> m2({
            {1,2},
            {3,4},
            {5,6}
            });

        std::cout << m2 << std::endl;

        Transformation::ElementaryTransformation::rowScaleOneRow(m2,1,10);
        std::cout << m2 << std::endl;
    }


}