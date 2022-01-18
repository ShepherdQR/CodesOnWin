/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-01-17 21:45:29
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-01-18 23:25:44
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#pragma once

#include <functional>
#include <cstring>

class Vector3;
class Vector4;

class Picture{
public:

    static void rainbow(const int iWidth, const int iHeight);


private:

    static void _picture(const int iWidth, const int iHeight,
    std::function<Vector3(const int iX, const int iY)> ifuncPositionColor, const std::string& iName);

    static void _picture(const int iWidth, const int iHeight,
    std::function<Vector4(const int iX, const int iY)> ifuncPositionColor, const std::string& iName);

    static std::string _fullPath(const std::string& iName);

};
