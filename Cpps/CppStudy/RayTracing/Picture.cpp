/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-01-17 21:55:53
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-01-17 23:00:00
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include "Picture.h"
#include "../../myTools/BasicTools.hpp"



#include <iostream>
#include <cstring>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"


void Picture::rainbow(const int iWidth, const int iHeight)
{



    int nChanel = 4;
    unsigned char *data = new unsigned char[iWidth * iHeight * nChanel];
    if (!data)
        return;

    //for (int j = iHeight - 1; j >= 0; --j)
    for (int j = 0; j < iHeight; ++j)
    {
        for (int i = 0; i < iWidth; ++i)
        {
            auto r = double(i) / (iWidth - 1);
            auto g = double(j) / (iHeight - 1);
            auto b = 0.25;
            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            data[(iWidth * (iHeight-1-j) + i) * nChanel + 0] = ir;
            data[(iWidth * (iHeight-1-j) + i) * nChanel + 1] = ig;
            data[(iWidth * (iHeight-1-j) + i) * nChanel + 2] = ib;
            data[(iWidth * (iHeight-1-j) + i) * nChanel + 3] = 255;
        }
    }

    std::string curTime = BasicTools::currentTime();
    std::string outFilePath = "../outputs/RainBow_";
    outFilePath.append(curTime);
    outFilePath.append(".png");
    int state = stbi_write_png(outFilePath.c_str(), iWidth, iHeight, nChanel, (void*)data, 0);
    //std::cout <<state <<std::endl;

    if (data)
    {
        delete data;
        data = nullptr;
    }
}
