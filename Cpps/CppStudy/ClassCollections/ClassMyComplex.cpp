/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-08-20 21:33:02
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2021-08-24 23:10:42
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


#include "ClassMyComplex.h"

template class ClassMyComplex<double>;

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
ClassMyComplex<T>& ClassMyComplex<T>::operator +=(const ClassMyComplex<T>& other)
{
    return __doapl(this, other);
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
std::ostream& operator <<(std::ostream& out, const ClassMyComplex<U>& other)
{
   return out<< "(" << other.real() << "," << other.image() << ")";
}