/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-08-20 21:33:02
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2024-06-19 23:34:49
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#pragma once

#include <iostream>

template<class T>
class ClassMyComplex;


namespace namespaceClassMyComplex
{
    void __declspec(dllexport)  test();
}



template<class T>
class __declspec(dllexport) ClassMyComplex{
public:
    static void test();

public:
    ClassMyComplex(const T& iReal, const T& iImage);
    ClassMyComplex(const ClassMyComplex& other);
    ~ClassMyComplex();


    // Try the best to use reference as the io of functions.
    
    ClassMyComplex& operator =(const ClassMyComplex& other);
    ClassMyComplex& operator -=(const ClassMyComplex& other);
    
    template<typename U>
    ClassMyComplex& operator +=(const ClassMyComplex<U>& other);

    ClassMyComplex operator +(const ClassMyComplex& other);
    ClassMyComplex operator -(const ClassMyComplex& other);
    ClassMyComplex operator *(const ClassMyComplex& other);

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

    T& realRef()  { return _real;}
    T& imageRef() { return _image;}

private:
    T _real; // Do not set data member public.
    T _image;

    // The first parm will be changed, while the second one will not.
    template<class U>
    friend ClassMyComplex<U>& _doAssignmentMinus (ClassMyComplex<U>*, const ClassMyComplex<U>&);//do assignment minus

    template<typename U>
    friend ClassMyComplex<T>& __doapl (ClassMyComplex<T>*, const ClassMyComplex<U>&);//do assignment plus

    
    friend class ClassMyComplex<int>;
    friend class ClassMyComplex<double>;
};

// template<>
// class ClassMyComplex<int>{
//     template<typename U>
//     friend class ClassMyComplex;
// };

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
_doAssignmentMinus (ClassMyComplex<U>* ths, const ClassMyComplex<U>& r)
{
    std::cout << "-=" << std::endl;
    ths->_real -= r._real;
    ths->_image -= r._image;

    return *ths;
}


template<typename T, typename U>
inline ClassMyComplex<T>& 
__doapl (ClassMyComplex<T>* ths, const ClassMyComplex<U>& r)
{
    std::cout << "+=" << std::endl;
    //ths->_real += r._real;
    //ths->_image += r._image;
    
    ths->realRef() += r.real();
    ths->imageRef() += r.image();
    return *ths;
}

template<class U>
inline U real(const ClassMyComplex<U>& other)
{return other.real();}

template<class U>
inline U image(const ClassMyComplex<U>& other)
{return other.image();}

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
operator + (const ClassMyComplex<U>& x, double y) // const double& y
{
    return ClassMyComplex<U>(real(x)+ y,
    image(x) 
    );
}

template<class U>
inline ClassMyComplex<U>
operator + (double y,const ClassMyComplex<U>& x)
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


// operator ==
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

// operator !=
template<class U>
inline bool
operator != (const ClassMyComplex<U>& x,const ClassMyComplex<U>& y)
{
    return !(real(x) == real(y)
        && image(x) == image(y));
}
template<class U>
inline bool
operator != (const ClassMyComplex<U>& x, double y)
{
    return !(x==y);
}
template<class U>
inline bool
operator != (double y,const ClassMyComplex<U>& x)
{
    return !(y==x);
}

#include <cmath>
template<class T>
inline ClassMyComplex<T>
polar2Complex(double raidus, double theta)
{
    return {raidus * cos(theta) + raidus * sin(theta)};
}

template<class T>
inline ClassMyComplex<T>
conjugateOfComplex(const ClassMyComplex<T>& ivalue)
{
    return {ivalue.real(), -ivalue.image()};
}

template<class T>
inline T
normOfComplex(const ClassMyComplex<T>& ivalue)
{
    return ivalue.real() * ivalue.real() + ivalue.image() * ivalue.image();
}

