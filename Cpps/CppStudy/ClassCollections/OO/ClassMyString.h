/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-08-23 22:26:34
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2024-06-15 17:02:00
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#pragma once
#include <iostream>

class __declspec(dllexport) ClassMyString{
public:
    explicit ClassMyString(const char* ipString = nullptr);
    ~ClassMyString();

    ClassMyString(const ClassMyString& iString);

    ClassMyString& operator=(const ClassMyString& iString);

    char* getStr() const{ return _pString;}

    static void test();

private:
    char* _pString;
};

inline
std::ostream& operator<<(std::ostream& os, const ClassMyString& iString)
{
    os << iString.getStr();
    return os;
}
