/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-03-10 20:50:39
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-03-12 23:08:55
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#pragma once


namespace Universe::BasicAlgorithm{

    class Saxpy final{
    public:

        /*
            z = a * b + c;
            1)  z = \boldsymbol a^T \cdot \boldsymbol b + 0     [dot product]
            2)  Saxpy
            2.1)    \boldsymbol z = a \cdot \boldsymbol b + \boldsymbol c       [ scalar * vector ]
            2.2)    \boldsymbol z = \boldsymbol A \cdot \boldsymbol b + \boldsymbol c   [ matrix * vector ]
            2.3)    \boldsymbol Z = \boldsymbol A \cdot \boldsymbol B + \boldsymbol C   [ matrix_mk * matrix_kn + matrix_mn ]

        */
        template<typename Scalar, int _Rows, int _Cols, int _Rows2, int _Cols2>
        Matrix<Scalar, _Rows, _Cols2>
        static solve_20230310 (
            const Matrix<Scalar, _Rows, _Cols>& iMatrix1,
            const Matrix<Scalar, _Rows2, _Cols2>& iMatrix2,
            const Matrix<Scalar, _Rows2, _Cols2>& iMatrix3){

            if(_Cols != _Rows2){
                return {};
            }

            return iMatrix1 * iMatrix2 + iMatrix3;
        }

    };

    class Slice final{
    public:

        template<bool RowOrCol, typename Scalar, int _Rows, int _Cols>
        constexpr auto static solve_20230312 (const Matrix<Scalar, _Rows, _Cols>& iMatrix){
            if constexpr (RowOrCol){
                return solve_20230312<Scalar, _Rows, _Cols, true>(iMatrix);
            }else{
                return solve_20230312<Scalar, _Rows, _Cols, false>(iMatrix);
            }
        }

    private:

        template<typename Scalar, int _Rows, int _Cols, bool RowOrCol>
        auto
        //std::vector<typename std::conditional<RowOrCol, Matrix<Scalar, 1, _Cols>, Matrix<Scalar, _Rows, 1> >::type>
        static solve_20230312 (const Matrix<Scalar, _Rows, _Cols>& iMatrix){
            using outelementT = typename std::conditional<RowOrCol, Matrix<Scalar, 1, _Cols>, Matrix<Scalar, _Rows, 1> >::type;
            // typedef typename std::conditional<RowOrCol, Matrix<Scalar, 1, _Cols>, Matrix<Scalar, _Rows, 1> >::type outelementT;

            std::vector<outelementT> out;
            out.reserve(RowOrCol? _Rows: _Cols);

            if constexpr(RowOrCol == true){
                //std::vector<decltype(iMatrix.retrieveRow(0))> out;
                //out.reserve(_Rows);
                for(int i=0;i<_Rows;++i){
                    out.emplace_back(iMatrix.retrieveRow(i));
                }
                // return out;
            }else {
                for(int i=0;i<_Cols;++i){
                    out.emplace_back(iMatrix.retrieveColumn(i));
                }
            }
            return out;
        }

        template<typename Scalar, int _Rows, int _Cols>
        auto static slice_Row_20230312 (const Matrix<Scalar, _Rows, _Cols>& iMatrix){
            return solve_20230312<Scalar, _Rows, _Cols, true>(iMatrix);
        }

        template<typename Scalar, int _Rows, int _Cols>
        auto static slice_Column_20230312 (const Matrix<Scalar, _Rows, _Cols>& iMatrix){
            return solve_20230312<Scalar, _Rows, _Cols, false>(iMatrix);
        }     
    };

    class OutProduct final{
    public:
        template<typename Scalar, int _Rows, int _Cols>
        static Matrix<Scalar, _Rows, _Cols> solve_20230312(
            const Matrix<Scalar, _Rows, 1>& iMatrix1,
            const Matrix<Scalar, 1, _Cols>& iMatrix2
        ){
            Matrix<Scalar, _Rows, _Cols> out;
            for(int i = 0; i <_Rows; ++i){
                for(int j = 0; j <_Cols; ++j){
                    out.at(i,j) = iMatrix1.at(i,0) * iMatrix2.at(0,j);
                }
            }
            return out;
        }
    };

    auto test_002(){
        Matrix<double, 3,1> m({
            {1.0},
            {2.0},
            {3.0}
            });
        Matrix<double, 1,2> n({
            {4.0,   5.0}
            });
        auto out = OutProduct::solve_20230312(m,n);
        std::cout << out << std::endl;

    }


    auto test_001(){ // Slice
        Matrix<double, 3,3> m({
            {8.0,   -3.0,   2.0},
            {4.0,  11.0,   -1.0},
            {6.0,  3.0,   12.0}
            });

        if(0){
            {
                auto p = m.retrieveRow(2);
                std::cout << p << std::endl;
            }

            {
                auto p = m.retrieveColumn(2);
                std::cout << p << std::endl;
            }
        }

        if(0){
            // for(const auto& cur: Slice::slice_Row_20230312(m)){
            //     std::cout << cur << std::endl;
            // }

            // for(const auto& cur: Slice::slice_Column_20230312(m)){
            //     std::cout << cur << std::endl;
            // }
        }

        for(const auto& cur: Slice::solve_20230312<true>(m)){
            std::cout << cur << std::endl;
        }

        for(const auto& cur: Slice::solve_20230312<false>(m)){
            std::cout << cur << std::endl;
        }
        
        
        
    }
}