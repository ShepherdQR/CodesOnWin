/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-02-14 22:41:33
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-02-20 23:55:17
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

namespace Universe{


namespace Elimination{

    class GaussianElimination final{
    public:

        // solve equation Ax = b, where A is square.
        template<typename Scalar, int _Rows, int _Cols>
        static Matrix<Scalar, _Rows, 1>
        solve_01(Matrix<Scalar, _Rows, _Cols>& imatrix, 
            Matrix<Scalar, _Rows, 1>& iB)
        {
            Matrix<Scalar, _Rows, 1> outVector;

            Matrix<Scalar, _Rows, _Cols+1> matrixLocal;
            for(int i=0; i< _Rows; ++i){
                for(int j=0; j< _Cols; ++j){
                    matrixLocal.at(i,j) = imatrix.at(i,j);
                }
                matrixLocal.at(i,_Rows) = iB.at(i,0);
            }

            for(int j=0; j< _Cols; ++j){

                int indexLT{j};// left top index
        
                // 1. retrieve number 
                int indexDevided{j};
                while(indexDevided < _Rows && !matrixLocal.at(indexDevided,j)){
                    ++indexDevided;
                }
                if(indexDevided == _Rows){
                    return outVector;
                }

                // 2. modify line j when necessary
                if(indexDevided != indexLT){
                    // Scalar val{matrixLocal.at(indexDevided,j)};
                    for(int jj=indexLT; jj< _Cols+1; ++jj){
                        matrixLocal.at(indexLT,jj) += matrixLocal.at(indexDevided,jj);
                        //matrixLocal.at(indexLT,jj) /= matrixLocal.at(indexLT,indexLT);
                    }
                }

                for(int i=j+1; i<_Rows; ++i){
                    Scalar valTop{matrixLocal.at(indexLT,indexLT)};
                    Scalar valBottom{matrixLocal.at(i,indexLT)};

                    for(int jj=indexLT; jj< _Cols+1; ++jj){

                        matrixLocal.at(i,jj) = 
                        matrixLocal.at(i,jj) * valTop - matrixLocal.at(indexLT,jj) * valBottom;
                    }
                }
            }

            // std::cout << matrixLocal << std::endl;
            /*
                1, 2, 3, 4, -3,
                0, -7, -13, -21, 14,
                0, 0, -21, -63, 28,
                0, 0, 0, -168, 42,
            */

            for(int i = _Rows-1;i>=0;--i){
                int indexRB = i; // right bottom of the A matrix, Ax = b
                if(!matrixLocal.at(indexRB,indexRB) ){
                    continue;
                }

                Scalar valueRB = matrixLocal.at(indexRB,_Cols) / matrixLocal.at(indexRB,indexRB);

                for(int ii = indexRB-1;ii>=0;--ii){
                    matrixLocal.at(ii,_Cols) = matrixLocal.at(ii,_Cols) 
                    - valueRB *  matrixLocal.at(ii,indexRB);
                    matrixLocal.at(ii,indexRB) = 0;
                }
                matrixLocal.at(indexRB,indexRB) = 1;
                matrixLocal.at(indexRB,_Cols) = valueRB;

            }
            //std::cout << matrixLocal << std::endl;
            /*
                1, 0, 0, 0, 0.0833333,
                0, 1, 0, 0, -0.166667,
                0, 0, 1, 0, -0.583333,
                0, 0, 0, 1, -0.25,
            */

            for(int i = 0; i< _Rows; ++i){
                outVector.at(i,0) = matrixLocal.at(i,_Cols);
            }

            return outVector;

        }
    };

}


namespace Transformation{



    class ElementaryTransformation final{
    public:

        // line transformation
        /** Construct
         * 1. one scalar times one line
         * 2. one scalar times one line, then add to the other line
         * 3. switch two lines
         */

        template<typename Scalar, int _Rows, int _Cols>
        static bool rowScaleOneRow(Matrix<Scalar, _Rows, _Cols>& imatrix, 
            const int iRow,
            const Scalar& iScale){

            auto row = imatrix.sizeRow();
            if(!iScale || iRow < 0 || iRow >=row){
                return false;
            }
            for(int i=0;i<imatrix.sizeColumn();++i){
                //imatrix.set(iRow,i, iScale* imatrix.at(iRow,i));
                imatrix.at(iRow,i) *= iScale;
            }
            return true;
        }
        

    };



}






}


