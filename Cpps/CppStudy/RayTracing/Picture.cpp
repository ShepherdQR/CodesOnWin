/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-01-17 21:55:53
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-01-18 23:34:30
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include "Picture.h"
#include "../../myTools/BasicTools.hpp"
#include "../../myTools/Vector3.h"
#include "../../myTools/Vector4.h"

#include <iostream>
#include <cstring>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"


void Picture::rainbow(const int iWidth, const int iHeight)
{
    auto lambdaPositionColor3 = [&](const int i, const int j){

        Vector3 ovecColor;
        ovecColor.e[0] = 255.999 * double(i) / (iWidth - 1);
        ovecColor.e[1] = 255.999 * double(j) / (iHeight - 1);
        ovecColor.e[2] = 255.999 * 0.25 ;

        return ovecColor;
    };

    Picture::_picture(iWidth, iHeight, lambdaPositionColor3, "RainBow3");


    auto lambdaPositionColor4 = [&](const int i, const int j){

        Vector4 ovecColor;
        ovecColor.e[0] = 255.999 * double(i) / (iWidth - 1);
        ovecColor.e[1] = 255.999 * double(j) / (iHeight - 1);
        ovecColor.e[2] = 255.999 * 0.25 ;
        ovecColor.e[3] = 0.5 *  (ovecColor.x() + ovecColor.y());

        return ovecColor;
    };

    Picture::_picture(iWidth, iHeight, lambdaPositionColor4, "RainBow4");

}


// void Picture::rainbow(const int iWidth, const int iHeight)
// {
//     int nChanel = 4;
//     unsigned char *data = new unsigned char[iWidth * iHeight * nChanel];
//     if (!data)
//         return;

//     //for (int j = iHeight - 1; j >= 0; --j)
//     for (int j = 0; j < iHeight; ++j)
//     {
//         for (int i = 0; i < iWidth; ++i)
//         {
//             auto r = double(i) / (iWidth - 1);
//             auto g = double(j) / (iHeight - 1);
//             auto b = 0.25;
//             int ir = static_cast<int>(255.999 * r);
//             int ig = static_cast<int>(255.999 * g);
//             int ib = static_cast<int>(255.999 * b);

//             // left-bottom is [0,0]
//             //r+ towards the right;
//             //g+ towards the up.
//             data[(iWidth * (iHeight-1-j) + i) * nChanel + 0] = ir;
//             data[(iWidth * (iHeight-1-j) + i) * nChanel + 1] = ig;
//             data[(iWidth * (iHeight-1-j) + i) * nChanel + 2] = ib;
//             data[(iWidth * (iHeight-1-j) + i) * nChanel + 3] = 0.5 *  (r+g) * 255;
//         }
//     }

//     std::string curTime = BasicTools::currentTime();
//     std::string outFilePath = "../outputs/RainBow_";
//     outFilePath.append(curTime);
//     outFilePath.append(".png");
//     int state = stbi_write_png(outFilePath.c_str(), iWidth, iHeight, nChanel, (void*)data, 0);
//     //std::cout <<state <<std::endl;

//     if (data)
//     {
//         delete data;
//         data = nullptr;
//     }
// }

std::string Picture::_fullPath(const std::string& iName)
{
    std::string curTime = BasicTools::currentTime();
    std::string outFilePath = "../outputs/";
    outFilePath.append(iName);
    outFilePath.append("_");
    outFilePath.append(curTime);
    outFilePath.append(".png");
    return outFilePath;
}

void Picture::_picture(const int iWidth, const int iHeight,
std::function<Vector3(const int iX, const int iY)> ifuncPositionColor, const std::string& iName)
{
    int nChanel = 3;

    unsigned char *data = new unsigned char[iWidth * iHeight * nChanel];
    if (data){
        //for (int j = iHeight - 1; j >= 0; --j)
        for (int j = 0; j < iHeight; ++j){
            for (int i = 0; i < iWidth; ++i){

                Vector3 color = ifuncPositionColor(i,j);

                // left-bottom is [0,0]
                //r+ towards the right;
                //g+ towards the up.
                data[(iWidth * (iHeight-1-j) + i) * nChanel + 0] = static_cast<int>(color.x());
                data[(iWidth * (iHeight-1-j) + i) * nChanel + 1] = static_cast<int>(color.y());
                data[(iWidth * (iHeight-1-j) + i) * nChanel + 2] = static_cast<int>(color.z());
            }
        }

        std::string outFilePath = Picture::_fullPath(iName);
        int state = stbi_write_png(outFilePath.c_str(), iWidth, iHeight, nChanel, (void*)data, 0);
        //std::cout <<state <<std::endl;

        delete data;
        data = nullptr;
    }
}

void Picture::_picture(const int iWidth, const int iHeight,
std::function<Vector4(const int iX, const int iY)> ifuncPositionColor, const std::string& iName)
{
    int nChanel = 4;

    unsigned char *data = new unsigned char[iWidth * iHeight * nChanel];
    if (!data)
        return;

    //for (int j = iHeight - 1; j >= 0; --j)
    for (int j = 0; j < iHeight; ++j){
        for (int i = 0; i < iWidth; ++i){

            Vector4 color = ifuncPositionColor(i,j);

            // left-bottom is [0,0]
            //r+ towards the right;
            //g+ towards the up.
            data[(iWidth * (iHeight-1-j) + i) * nChanel + 0] = color.x();
            data[(iWidth * (iHeight-1-j) + i) * nChanel + 1] = color.y();
            data[(iWidth * (iHeight-1-j) + i) * nChanel + 2] = color.z();
            data[(iWidth * (iHeight-1-j) + i) * nChanel + 3] = color.i();
            
        }
    }

    std::string outFilePath = Picture::_fullPath(iName);
    int state = stbi_write_png(outFilePath.c_str(), iWidth, iHeight, nChanel, (void*)data, 0);
    //std::cout <<state <<std::endl;

    if (data)
    {
        delete data;
        data = nullptr;
    }
}