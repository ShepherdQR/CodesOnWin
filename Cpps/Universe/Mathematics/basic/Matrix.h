/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-02-12 21:19:41
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-03-08 22:01:57
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
    Matrix(){
        for(int i = 0; i < _Rows * _Cols;++i){
            _mArray[i] = 0;
        }
    }

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

    int sizeColumn()const {return _Cols;}

    Scalar& at(int i, int j){return _mArray[i*_Cols + j];}

    //void set(int i, int j, const Scalar& ival){_mArray[i*_Cols + j] = ival;};
   
    Scalar at(int i, int j)const {return _mArray[i*_Cols + j];}


    template</*typename Scalar,*/ int _Rows2, int _Cols2>
    Matrix<Scalar, _Rows, _Cols2>
    operator * (const Matrix<Scalar, _Rows2, _Cols2>& iMatrix)const{
        Matrix<Scalar, _Rows, _Cols2> out;
        if(_Rows2 != _Rows)
        {
            // error
            return out;
        }

        for(int i=0; i<_Rows;++i){
            for(int j=0; j<_Cols2;++j){
                Scalar cur{};
                for(int k=0; k<_Cols;++k){
                    cur += this->at(i,k) * iMatrix.at(k,j);
                }
                
                out.at(i,j) = cur;
            }
        }
        return out;
    }

    Matrix<Scalar, _Rows, _Cols>
    dotProduct (const Matrix<Scalar, _Rows, _Cols>& iMatrix)const{
        Matrix<Scalar, _Rows, _Cols> out;
        for(int i=0; i<_Rows;++i){
            for(int j=0; j<_Cols;++j){
                out.at(i,j) = this->at(i,j) * iMatrix.at(i,j);
            }
        }
        return out;
    }

    Matrix<Scalar, _Rows, _Cols>
    operator + (const Matrix<Scalar, _Rows, _Cols>& iMatrix)const{
        Matrix<Scalar, _Rows, _Cols> out;
        for(int i=0; i<_Rows;++i){
            for(int j=0; j<_Cols;++j){
                out.at(i,j) = this->at(i,j) + iMatrix.at(i,j);
            }
        }
        return out;
    }


    Matrix<Scalar, _Rows, _Cols>
    operator - (const Matrix<Scalar, _Rows, _Cols>& iMatrix)const{
        Matrix<Scalar, _Rows, _Cols> out;
        for(int i=0; i<_Rows;++i){
            for(int j=0; j<_Cols;++j){
                out.at(i,j) = this->at(i,j) - iMatrix.at(i,j);
            }
        }
        return out;
    }

    Matrix<Scalar, _Rows, _Cols>&
    operator= (const Matrix<Scalar, _Rows, _Cols>& iMatrix){

        if(&iMatrix == this){
            return *this;
        }

        for(int i=0; i<_Rows;++i){
            for(int j=0; j<_Cols;++j){
                this->at(i,j) = iMatrix.at(i,j);
            }
        }
        return *this;
    }

    Scalar norm(const int iBase){
        Scalar out{};

        if(iBase == 1){
            for(int i=0; i<_Rows;++i){
                for(int j=0; j<_Cols;++j){
                    out +=  std::abs(this->at(i,j)) ;
                }
            }
        }
        else if(iBase == 2){
            for(int i=0; i<_Rows;++i){
                for(int j=0; j<_Cols;++j){
                    out += this->at(i,j) * this->at(i,j) ;
                }
            }
        }
        
        return out;
    }

    Matrix<Scalar, _Cols, _Rows>
    transposition ()const{
        Matrix<Scalar, _Cols, _Rows> out;
        for(int i=0; i<_Rows;++i){
            for(int j=0; j<_Cols;++j){
                out.at(j,i) = this->at(i,j);
            }
        }
        return out;
    }

private:
    plainArray<Scalar, _Rows * _Cols> _mArray;
     
};

template<typename Scalar, int _Rows, int _Cols>
std::ostream& operator<<(std::ostream& os, const Matrix<Scalar, _Rows, _Cols>& iMatrix)
{
    for(int i=0; i<_Rows;++i){
        for(int j=0; j<_Cols;++j){
            os << iMatrix.at(i,j) << ", ";
        }
        os << std::endl;
    }

    return os;
}

template<typename Scalar, int _Rows, int _Cols>
Matrix<Scalar, _Rows, _Cols>
operator*(const Scalar& iScalar, const Matrix<Scalar, _Rows, _Cols>& iMatrix)
{
    Matrix<Scalar, _Rows, _Cols> out = iMatrix;
    for(int i=0; i<_Rows;++i){
        for(int j=0; j<_Cols;++j){
            out.at(i,j) *= iScalar;
        }
    }

    return out;
}


}
