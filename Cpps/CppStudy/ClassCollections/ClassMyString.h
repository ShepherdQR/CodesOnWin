/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-08-23 22:26:34
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2021-08-23 22:58:59
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#pragma once
#include <iostream>

class ClassMyString{
public:
    ClassMyString(const char* ipString = nullptr);
    ~ClassMyString();

    ClassMyString(const ClassMyString& iString);

    ClassMyString& operator=(const ClassMyString& iString);

    char* getStr() const{ return _pString;}

private:
    char* _pString;

};

std::ostream& operator<<(std::ostream& os, const ClassMyString& iString)
{
    os << iString.getStr();
    return os;
}
