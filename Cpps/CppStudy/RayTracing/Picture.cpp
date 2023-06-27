/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-01-17 21:55:53
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-06-27 22:49:00
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include "Picture.h"
#include "../../myTools/BasicTools.hpp"
#include "../../myTools/Vector3.h"
#include "../../myTools/Vector4.h"
#include "../../myTools/Ray.h"
#include "../../myTools/BSpline.h"

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


void Picture::sky(const double iRatio, const int iWidth,
const TypeRay iTypeRay /*= TypeRay::Sky*/)
{
    // Image
    const double aspect_ratio = iRatio;
    const int image_width = iWidth;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    /*
             __ __ 
            |  .  |  <- the plane of the camera is part of z-
         y+ |__ __|
          |
          |__ __ x+
         / O
        /
       z+

    */

    // Camera, 
    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    Point3 origin(0, 0, 0);
    Vector3 horizontal = Vector3(viewport_width, 0, 0);
    Vector3 vertical = Vector3(0, viewport_height, 0);
    Point3 lower_left_corner = origin 
    - horizontal/2 - vertical/2 - Vector3(0, 0, focal_length);

    if(TypeRay::Sky == iTypeRay)
    {
        auto lambdaPositionColor3 = [&](const int i, const int j){
            double u = double(i) / (image_width - 1);
            double v = double(j) / (image_height - 1);
            Ray ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            Vector3 ovecColor = ray.sky()* 255;

            return ovecColor;
        };

        Picture::_picture(image_width, image_height, lambdaPositionColor3, "Sky3");

    }
    else if(TypeRay::Sphere == iTypeRay){

        Vector3 sphereCenter(0,0,-1);
        double sphereRadius(0.5);

        auto lambdaPositionColor4 = [&](const int i, const int j){

            double u = double(i) / (image_width - 1);
            double v = double(j) / (image_height - 1);
            Ray ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            Vector3 ovecColor = ray.sphere(sphereCenter, sphereRadius)* 255;

            return ovecColor;
        };

        Picture::_picture(image_width, image_height, lambdaPositionColor4, "Sphere");


    }

    else if(TypeRay::BSpline == iTypeRay){

        //BSpline bs({{10,0, 10},{20,0, 90} ,{40, 0,20},{60,0, 80},{80,0,5}},4);
        //BSpline bs({{10,1, -10},{20,2, -90} ,{40, 3,-20},{60,4, -80},{80,5,-5}},4);
        BSpline bs({{-0.5,-0.5,-1},{-0.2,0.2,-1} ,{0.1,-0.3,-1},{0.3, 0.0,-1},{0.5, 0.4,-1}},4);
        //BSpline bs({{0.10,0.10,-10},{0.20,0.90,-10} ,{0.40, 0.20,-10},{0.60,0.80,-10},{0.80,0.05,-10}},3);

        for(auto cur: *bs._uplistPoint){
            std::cout << cur << std::endl;
        }

        auto lambdaPositionColor5 = [&](const int i, const int j){

            double u = double(i) / (image_width - 1);
            double v = double(j) / (image_height - 1);
            Ray ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            Vector3 ovecColor = ray.BSpline(bs._uplistPoint)* 255;

            return ovecColor;
        };

        Picture::_picture(image_width, image_height, lambdaPositionColor5, "BSpline");


    }



}



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

    //int coutStep(0);
    unsigned char *data = new unsigned char[iWidth * iHeight * nChanel];
    if (data){
        //for (int j = iHeight - 1; j >= 0; --j)
        for (int j = 0; j < iHeight; ++j){
            for (int i = 0; i < iWidth; ++i){

                Vector3 color = ifuncPositionColor(i,j);

                // if(++coutStep<100){
                //     std::cout << color << std::endl;
                // }

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

        delete[] data;
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

    
        delete[] data;
        data = nullptr;
    
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
