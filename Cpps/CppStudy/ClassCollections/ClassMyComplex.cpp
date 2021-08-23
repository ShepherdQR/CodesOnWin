/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-08-20 21:33:02
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2021-08-23 22:25:56
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


#include "ClassMyComplex.h"

ClassMyComplex::ClassMyComplex(const T& iReal, const T& iImage)
:_real(iReal),_image(iImage)
{
}

ClassMyComplex::ClassMyComplex(const ClassMyComplex& other)
:_real(other._real),_image(other._image)
{
    //_real = other.real();
    //_image = other.image();
}

ClassMyComplex::~ClassMyComplex()
{
}

ClassMyComplex& ClassMyComplex::operator =(const ClassMyComplex& other)
{
    if(&other != this){
        _real = other.real();
        _image = other.image();
    }

    return *this;
}
ClassMyComplex& ClassMyComplex::operator +=(const ClassMyComplex& other)
{
    return __doapl(this, other);
}


ClassMyComplex ClassMyComplex::operator +(const ClassMyComplex& other)
{
    return ClassMyComplex(_real +other.real() ,_image +other.image()  );
}

ClassMyComplex ClassMyComplex::operator +(const ClassMyComplex& other)
{
    return ClassMyComplex(_real - other.real() ,_image - other.image()  );
}



ClassMyComplex& ClassMyComplex::operator ++()
{
    ++_real;
    return *this;
}

ClassMyComplex ClassMyComplex::operator ++(int)
{
    ClassMyComplex ComplexOld(*this);
    ++(*this);
    return ComplexOld;
}

ClassMyComplex operator +(const T& iReal, const ClassMyComplex& other)
{
    return ClassMyComplex(iReal +other.real(), other.image());
}
ClassMyComplex operator -(const T& iReal, const ClassMyComplex& other)
{
    return ClassMyComplex(iReal - other.real(), other.image());
}

std::ostream& operator <<(std::ostream& out, const ClassMyComplex& other)
{
   return out<< "(" << other.real() << "," << other.image() << ")";
}