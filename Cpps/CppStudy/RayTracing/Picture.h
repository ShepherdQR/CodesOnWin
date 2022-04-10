/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-01-17 21:45:29
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-02-01 22:34:57
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#pragma once

#include <functional>
#include <cstring>

enum class TypeRay{
    Sky = 0,
    Sphere = 1
};

class Vector3;
class Vector4;

class Picture{
public:

    // 
    static void sky(const double iRatio, const int iWidth, const TypeRay iTypeRay = TypeRay::Sky);

    static void rainbow(const int iWidth, const int iHeight);


private:

    static void _picture(const int iWidth, const int iHeight,
    std::function<Vector3(const int iX, const int iY)> ifuncPositionColor, const std::string& iName);

    static void _picture(const int iWidth, const int iHeight,
    std::function<Vector4(const int iX, const int iY)> ifuncPositionColor, const std::string& iName);

    static std::string _fullPath(const std::string& iName);

};
