/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-08-23 22:26:34
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2024-06-16 11:05:55
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#include "./ClassMyString.h"
#include <cstring>

void ClassMyString::test()
{
    std::cout << "20240615" << std::endl;

    ClassMyString s1{"hello"};
    ClassMyString s2{"world"};
    ClassMyString s3{s1};
    
    std::cout << s1 << std::endl;
    s1 = s2;
    std::cout << s1 << std::endl;
}

inline
ClassMyString::ClassMyString(const char* ipString)
:_pString(nullptr)
{
    if(ipString){
        int len = strlen(ipString);
        _pString = new char[len + 1]{}; // initialize with 0
        memcpy(_pString,ipString, len*sizeof(char));
        // std::cout <<len <<  _pString << std::endl;
    }else{
        _pString = new char[1];
        *_pString = '\0';
    }
}

inline
ClassMyString::~ClassMyString()
{
    if(_pString){
        delete[] _pString;
        _pString = nullptr;
    }
}


inline
ClassMyString::ClassMyString(const ClassMyString& iString)
{
    //*this = iString;
    auto len = strlen(iString._pString);
    _pString = new char[ len+ 1]{};
    memcpy(_pString,iString._pString, len);
}


inline
ClassMyString& ClassMyString::operator=(const ClassMyString& iString)
{
    // self assignment
    if(this == &iString)
        return *this;

    if(_pString){
        delete[] _pString;
    }

    //兄弟之间互为friend
    auto len = strlen(iString._pString);
    _pString = new char[len + 1]{};
    memcpy(_pString,iString._pString, len);

    return *this;
}


