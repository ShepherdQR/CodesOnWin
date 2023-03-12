/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-03-07 21:09:57
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-03-07 22:38:51
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#pragma once

namespace Universe::Iteration{

    class IterationBase{
    protected:
        inline static int _times{1000};
        inline static double _threholdDiff{0.00001};
        inline static double _threholdAbsolute{0.000001};

    };

    class JacobiIteration final: IterationBase{
    public:

        // solve equation Ax = b, where A is square.
        /**
                A = D-L-U
                (D-L-U) x = b
            ==> Dx' -Lx - Ux = b   ==>     x' = D^(-1)(L+U)x + D^(-1)b      || Jacobi
            ==> Dx' -Lx' - Ux = b   ==>     x' = (D-L)^(-1)Ux + (D-L)^(-1)b      || G-S
        */
        template<typename Scalar, int _Rows, int _Cols>
        static Matrix<Scalar, _Rows, 1>
        solve_01(Matrix<Scalar, _Rows, _Cols>& imatrix, 
            Matrix<Scalar, _Rows, 1>& iB)
        {
            Matrix<Scalar, _Rows, 1> result;
            

            Matrix<Scalar, _Rows, _Cols> D_revert, L, U;

            // 1. form D, L, U
            for(int i=0; i< _Rows; ++i){
                for(int j=0; j< _Cols; ++j){
                    auto cur = imatrix.at(i,j);
                    if(j == i){
                        if(std::abs(cur -0.0) <= _threholdAbsolute){
                            // error
                            return result;
                        }
                        D_revert.at(i,j) = 1.0 / cur;
                    }else if(j< i){
                        L.at(i,j) = -cur;
                    }else{
                        U.at(i,j) = -cur;
                    }
                }
            }

            Matrix<Scalar, _Rows, 1> resultPrevious;

            // Matrix<Scalar, _Rows, 1> resultPrevious({
            // {3.0},
            // {2.0},
            // {1.0}
            // });

            //std::cout << D_revert << std::endl;
            //std::cout << L << std::endl;
            //std::cout << U << std::endl;

            Matrix<Scalar, _Rows, 1> resultNext;
            auto ll =  D_revert * (L + U)* resultPrevious ;
            auto rr = D_revert * iB;

            resultNext = D_revert * (L + U) * resultPrevious + D_revert * iB;


            auto resultDiff = resultNext - resultPrevious;
            int times{};
            auto diff{resultDiff.norm(1) };
            while( times++ < _times &&     diff > _threholdDiff){
                resultPrevious = resultNext;
                resultNext = D_revert * (L + U) * resultPrevious + D_revert * iB;
                resultDiff = resultNext - resultPrevious;
                diff = resultDiff.norm(1);
            }

            std::cout << "[times, diff]\t" << times << "\t" << diff << std::endl;

            if(diff> _threholdDiff)
            {
                // error
                return result;
            }

            return resultNext;
        }

    };

}