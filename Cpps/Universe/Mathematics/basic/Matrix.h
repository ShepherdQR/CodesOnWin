/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-02-12 21:19:41
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-02-12 22:34:47
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include <iostream>

namespace Universe{


template<typename T, int Size>
struct plainArray{


    T& operator[](int i) {return array[i];}
    T operator[](int i)const {return array[i];}
    T array[Size];
};


template<typename Scalar, int _Rows, int _Cols>
class Matrix{
public:
    Matrix(){}

    explicit Matrix(const std::initializer_list< std::initializer_list< Scalar >> & iList ){
        auto szRow = iList.size();
        auto itRow = iList.begin();

        for(long unsigned int i = 0; i < _Rows;++i){
            if(i>=szRow){
                break;
            }

            if(auto plistCol = itRow + i){

                auto szCol = plistCol->size();
                auto itCol = plistCol->begin();

                for(long unsigned int j = 0; j < _Cols;++j){
                    if(j>=szCol){
                        break;
                    }
                    _mArray[i*_Cols + j] = *(itCol+j);
                }
            }
        }
    }

    int sizeRow()const {return _Rows;}

    int sizeCol()const {return _Cols;}

    Scalar& at(int i, int j){return _mArray[i*_Cols + j];}

    Scalar at(int i, int j)const {return _mArray[i*_Cols + j];}

private:
    plainArray<Scalar, _Rows * _Cols> _mArray;
     
};

template<typename Scalar, int _Rows, int _Cols>
std::ostream& operator<<(std::ostream& os, const Matrix<Scalar, _Rows, _Cols>& iMatrix)
{
    for(int i=0; i<iMatrix.sizeRow();++i){
        for(int j=0; j<iMatrix.sizeCol();++j){
            os << iMatrix.at(i,j) << ", ";
        }
        os << std::endl;
    }

    return os;
}


}
