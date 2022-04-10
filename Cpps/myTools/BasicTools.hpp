/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-01-17 22:46:19
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-02-01 22:33:43
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-01-17 22:46:19
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-01-17 22:56:16
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#pragma once

#include <ctime>
#include <cstring>
#include <sstream>
#include <chrono>
#include <iomanip>

class BasicTools{

public:
    static std::string currentTime();
};


std::string BasicTools::currentTime()
{
    time_t t=std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::stringstream ss;
    ss<<std::put_time(std::localtime(&t),"%Y%m%d_%H%M%S");
    std::string strTime = ss.str();
	//std::cout << strTime << std::endl;
    return strTime;
}