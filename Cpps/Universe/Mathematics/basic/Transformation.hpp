/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-03-07 21:07:11
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-03-07 21:09:30
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/



namespace Universe::Transformation{


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
