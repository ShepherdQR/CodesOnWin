/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-08-20 21:33:02
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2021-08-23 22:11:41
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#pragma once

#include <iostream>

template<class T>
class ClassMyComplex{

public:
    ClassMyComplex(const T& iReal, const T& iImage);
    ClassMyComplex(const ClassMyComplex& other);
    ~ClassMyComplex();


    // Try the best to use reference as the io of functions.
    ClassMyComplex& operator =(const ClassMyComplex& other);
    ClassMyComplex& operator +=(const ClassMyComplex& other);

    ClassMyComplex operator +(const ClassMyComplex& other);
    ClassMyComplex operator -(const ClassMyComplex& other);

    friend ClassMyComplex operator +(const T& iReal, const ClassMyComplex& other);
    friend ClassMyComplex operator -(const T& iReal, const ClassMyComplex& other);
    friend std::ostream& operator <<(std::ostream& out, const ClassMyComplex& other);


    ClassMyComplex& operator ++();
    ClassMyComplex operator ++(int);
    
    /*
    相同class的各个objects互为friends
    */
    int func1(const ClassMyComplex& iParm)
    {return iparm._real + iparm._imag;}

    T real() const { return _real;}
    T image() const;

private:
    T _real; // Do not set data member public.
    T _image;

    // The first parm will be changed, while the second one will not.
    friend ClassMyComplex& __doapl (ClassMyComplex*, const ClassMyComplex&);//do assignment plus

};

/*
If get() without being decorated with const,
when we use like this:
const A a; a.get();
this makes error.
*/
inline T ClassMyComplex::image() const { return _image;}

inline ClassMyComplex& 
__doapl (ClassMyComplex* ths, const ClassMyComplex& r)
{
    ths->_real += r._real;
    ths->_image += r._image;
    return *ths;
}

inline T real(const ClassMyComplex& other)
{return other._real;}

inline T image(const ClassMyComplex& other)
{return other._image;}

inline ClassMyComplex
operator + (const ClassMyComplex& x, const ClassMyComplex& y)
{
    return ClassMyComplex(real(x)+ real(y),
    image(x)+ image(y)
    );
}


inline ClassMyComplex
operator + (const ClassMyComplex& x, const double& y)
{
    return ClassMyComplex(real(x)+ y,
    image(x) 
    );
}

inline ClassMyComplex
operator + (const double& y,const ClassMyComplex& x)
{
    return ClassMyComplex(real(x)+ y,
    image(x) 
    );
}

inline ClassMyComplex
operator + (const ClassMyComplex& x)
{
    return x;
}

inline ClassMyComplex
operator - (const ClassMyComplex& x)
{
    return ClassMyComplex(-real(x), -image(x) );
}

inline ClassMyComplex
conj (const ClassMyComplex& x)
{
    return ClassMyComplex(real(x), -image(x) );
}


inline bool
operator == (const ClassMyComplex& x,const ClassMyComplex& y)
{
    return real(x) == real(y)
        && image(x) == image(y;)
}

inline bool
operator == (const ClassMyComplex& x, double y)
{
    return real(x) == y && image(x) == 0;
}

inline bool
operator == (double y,const ClassMyComplex& x)
{
    return real(x) == y && image(x) == 0;
}








