/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-08-23 22:26:34
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2021-08-24 23:13:19
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#include "ClassMyString.h"
#include <cstring>
inline
ClassMyString::ClassMyString(const char* ipString)
:_pString(nullptr)
{
    if(ipString){
        int len = strlen(ipString);
        _pString = new char[len + 1];
        strcpy(_pString,ipString);
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
    
    _pString = new char[strlen(iString._pString) + 1];
    strcpy(_pString,iString._pString);
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
    _pString = new char[strlen(iString._pString) + 1];
    strcpy(_pString,iString._pString);

    return *this;
}


