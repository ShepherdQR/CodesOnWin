/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-08-20 21:33:02
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2024-06-19 23:37:04
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


#include "ClassMyComplex.h"

template class ClassMyComplex<double>;


template<class T>
void
ClassMyComplex<T>::test()
{
    std::cout << "20240616" << std::endl;
    auto cc = ClassMyComplex<int>(1,2);
    std::cout << "20240619" << cc << std::endl;

    ClassMyComplex<int> a1{1,2}, a2{3,4};
    ClassMyComplex<double> b1{-3.0,-4.0};
    a1 += a2;
    std::cout << "a1 += a2: " << a1 << std::endl;
    a1 += b1;
    std::cout << "a1 += b1: " << a1 << std::endl;
    a1 -= a1;
    std::cout << "a1 -= a1: " << a1 << std::endl;

    std::cout << "-a2: " << -a2 << std::endl;

    /*
        20240616
        20240619(1,2)
        +=
        a1 += a2: (4,6)
        +=
        a1 += b1: (1,2)
        -=
        a1 -= a1: (0,0)
        -a2: (-3,-4)
    */

}


template<class T>
ClassMyComplex<T>::ClassMyComplex(const T& iReal, const T& iImage)
:_real(iReal),_image(iImage)
{
}

template<class T>
ClassMyComplex<T>::ClassMyComplex(const ClassMyComplex<T>& other)
:_real(other._real),_image(other._image)
{
    //_real = other.real();
    //_image = other.image();
}
template<class T>
ClassMyComplex<T>::~ClassMyComplex()
{
}

template<class T>
ClassMyComplex<T>& ClassMyComplex<T>::operator =(const ClassMyComplex<T>& other)
{
    if(&other != this){
        _real = other.real();
        _image = other.image();
    }

    return *this;
}

template<class T>
ClassMyComplex<T>& ClassMyComplex<T>::operator -=(const ClassMyComplex<T>& other)
{
    return _doAssignmentMinus(this, other);
}

template< typename T> //class T,
template< typename U>
ClassMyComplex<T>& ClassMyComplex<T>::operator +=(const ClassMyComplex<U>& other)
{
    return __doapl<T,U>(this, other);
}

template<class T>
ClassMyComplex<T> ClassMyComplex<T>::operator +(const ClassMyComplex<T>& other)
{
    return ClassMyComplex<T>(_real +other.real() ,_image +other.image()  );
}
template<class T>
ClassMyComplex<T> ClassMyComplex<T>::operator -(const ClassMyComplex<T>& other)
{
    return ClassMyComplex<T>(_real - other.real() ,_image - other.image()  );
}
template<class T>
ClassMyComplex<T> ClassMyComplex<T>::operator *(const ClassMyComplex<T>& other)
{
    return ClassMyComplex<T>(
        _real * other.real() - _image * other.image() ,
        _real * other.image() + _image * other.real()
        );
}

template<class T>
ClassMyComplex<T>& ClassMyComplex<T>::operator ++()
{
    ++_real;
    return *this;
}
template<class T>
ClassMyComplex<T> ClassMyComplex<T>::operator ++(int)
{
    ClassMyComplex<T> ComplexOld(*this);
    ++(*this);
    return ComplexOld;
}

template<class U>
ClassMyComplex<U> operator +(const U& iReal, const ClassMyComplex<U>& other)
{
    return ClassMyComplex<U>(iReal +other.real(), other.image());
}

template<class U>
ClassMyComplex<U> operator -(const U& iReal, const ClassMyComplex<U>& other)
{
    return ClassMyComplex<U>(iReal - other.real(), other.image());
}



template<class U>
std::ostream& 
operator <<(std::ostream& out, const ClassMyComplex<U>& other)
{
   return out<< "(" << other.real() << "," << other.image() << ")";
}



void namespaceClassMyComplex::test(){
    ClassMyComplex<int>::test();
}
