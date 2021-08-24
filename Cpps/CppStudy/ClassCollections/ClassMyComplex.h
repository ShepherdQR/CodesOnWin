/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-08-20 21:33:02
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2021-08-24 23:11:35
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

    template<class U>
    friend ClassMyComplex<U> operator +(const U & iReal, const ClassMyComplex<U> & other);

    template<class U>
    friend ClassMyComplex<U> operator -(const U & iReal, const ClassMyComplex<U> & other);

    template<class U>
    friend std::ostream& operator <<(std::ostream& out, const ClassMyComplex<U>& other);


    ClassMyComplex& operator ++();
    ClassMyComplex operator ++(int);
    
    /*
    相同class的各个objects互为friends
    */
    int func1(const ClassMyComplex& iParm)
    {return iParm._real + iParm._image;}

    T real() const { return _real;}
    T image() const;

private:
    T _real; // Do not set data member public.
    T _image;

    // The first parm will be changed, while the second one will not.
    template<class U>
    friend ClassMyComplex<U>& __doapl (ClassMyComplex<U>*, const ClassMyComplex<U>&);//do assignment plus

};

/*
If get() without being decorated with const,
when we use like this:
const A a; a.get();
this makes error.
*/
template<class T>
inline T ClassMyComplex<T>::image() const { return _image;}

template<class U>
inline ClassMyComplex<U>& 
__doapl (ClassMyComplex<U>* ths, const ClassMyComplex<U>& r)
{
    ths->_real += r._real;
    ths->_image += r._image;
    return *ths;
}

template<class U>
inline U real(const ClassMyComplex<U>& other)
{return other._real;}

template<class U>
inline U image(const ClassMyComplex<U>& other)
{return other._image;}

template<class U>
inline ClassMyComplex<U>
operator + (const ClassMyComplex<U>& x, const ClassMyComplex<U>& y)
{
    return ClassMyComplex<U>(real(x)+ real(y),
    image(x)+ image(y)
    );
}

template<class U>
inline ClassMyComplex<U>
operator + (const ClassMyComplex<U>& x, const double& y)
{
    return ClassMyComplex<U>(real(x)+ y,
    image(x) 
    );
}

template<class U>
inline ClassMyComplex<U>
operator + (const double& y,const ClassMyComplex<U>& x)
{
    return ClassMyComplex<U>(real(x)+ y,
    image(x) 
    );
}
template<class U>
inline ClassMyComplex<U>
operator + (const ClassMyComplex<U>& x)
{
    return x;
}
template<class U>
inline ClassMyComplex<U>
operator - (const ClassMyComplex<U>& x)
{
    return ClassMyComplex<U>(-real(x), -image(x) );
}
template<class U>
inline ClassMyComplex<U>
conj (const ClassMyComplex<U>& x)
{
    return ClassMyComplex<U>(real(x), -image(x) );
}

template<class U>
inline bool
operator == (const ClassMyComplex<U>& x,const ClassMyComplex<U>& y)
{
    return real(x) == real(y)
        && image(x) == image(y);
}
template<class U>
inline bool
operator == (const ClassMyComplex<U>& x, double y)
{
    return real(x) == y && image(x) == 0;
}
template<class U>
inline bool
operator == (double y,const ClassMyComplex<U>& x)
{
    return real(x) == y && image(x) == 0;
}








