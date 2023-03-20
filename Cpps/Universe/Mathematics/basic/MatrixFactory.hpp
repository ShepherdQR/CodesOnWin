/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-03-20 21:29:32
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-03-20 22:10:08
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


#pragma once


namespace Universe::MatrixFactory{

    class BandMatrix final{

        /*
            iLowerBandwidth:    i>j+iLowerBandwidth ==> a_{ij} = 0
            iUpperBandwidth:    j>i+iUpperBandwidth ==> a_{ij} = 0
            for example: iLowerBandwidth=1, iUpperBandwidth=2
            1, 1, 1, 0, 0,
            1, 1, 1, 1, 0,
            0, 1, 1, 1, 1,
            0, 0, 1, 1, 1,
            0, 0, 0, 1, 1,
            0, 0, 0, 0, 1,
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,

            iLowerBandwidth, iUpperBandwidth:
                    0               0       :   diagonal
        */
        template<typename Scalar, int _Rows, int _Cols>
        static Matrix<Scalar, _Rows, _Cols>solve_20230320(
        int iLowerBandwidth, int iUpperBandwidth){
            Matrix<Scalar, _Rows, _Cols> out;

            if(iLowerBandwidth<_Rows && iUpperBandwidth< _Cols){
                for(int i=0;i<_Rows;++i){
                    for(int j=0;j<_Cols;++j){
                        out.at(i,j) = bool(!((i>j+iLowerBandwidth) || (j>i+iUpperBandwidth)));
                    }
                }
            }

            return out;
        }

    public:

        template<typename Scalar, int _Rows, int _Cols>
        static Matrix<Scalar, _Rows, _Cols> band(int iLowerBandwidth, int iUpperBandwidth){
            return solve_20230320<Scalar, _Rows, _Cols>(iLowerBandwidth, iUpperBandwidth);
        }

        template<typename Scalar, int _Rows, int _Cols>
        static Matrix<Scalar, _Rows, _Cols> diagonal(){
            return solve_20230320<Scalar, _Rows, _Cols>(0, 0);
        }

        template<typename Scalar, int _Rows, int _Cols>
        static Matrix<Scalar, _Rows, _Cols> upperBidiagonal(){
            return solve_20230320<Scalar, _Rows, _Cols>(0, 1);
        }

        template<typename Scalar, int _Rows, int _Cols>
        static Matrix<Scalar, _Rows, _Cols> lowerBidiagonal(){
            return solve_20230320<Scalar, _Rows, _Cols>(1,0);
        }

        template<typename Scalar, int _Rows, int _Cols>
        static Matrix<Scalar, _Rows, _Cols> tridiagonal(){
            return solve_20230320<Scalar, _Rows, _Cols>(1, 1);
        }


        template<typename Scalar, int _Rows, int _Cols>
        static Matrix<Scalar, _Rows, _Cols> upperTriangular(){
            return solve_20230320<Scalar, _Rows, _Cols>(0, _Cols-1);
        }

        template<typename Scalar, int _Rows, int _Cols>
        static Matrix<Scalar, _Rows, _Cols> lowerTriangular(){
            return solve_20230320<Scalar, _Rows, _Cols>(_Rows-1, 0);
        }

        template<typename Scalar, int _Rows, int _Cols>
        static Matrix<Scalar, _Rows, _Cols> upperHessenberg(){
            return solve_20230320<Scalar, _Rows, _Cols>(1, _Cols-1);
        }

        template<typename Scalar, int _Rows, int _Cols>
        static Matrix<Scalar, _Rows, _Cols> lowerHessenberg(){
            return solve_20230320<Scalar, _Rows, _Cols>(_Rows-1, 1);
        }



    };



    auto test_001(){
        // auto out = BandMatrix::band<int,8,5>(1,2);
        // auto out = BandMatrix::diagonal<int,8,5>();
        // auto out = BandMatrix::upperBidiagonal<int,8,5>();
        // auto out = BandMatrix::lowerBidiagonal<int,8,5>();
        // auto out = BandMatrix::tridiagonal<int,8,5>();
        // auto out = BandMatrix::upperTriangular<int,8,5>();
        // auto out = BandMatrix::lowerTriangular<int,8,5>();
        // auto out = BandMatrix::upperHessenberg<int,8,5>();
        auto out = BandMatrix::lowerHessenberg<int,8,5>();
        std::cout << out << std::endl;
    }

}