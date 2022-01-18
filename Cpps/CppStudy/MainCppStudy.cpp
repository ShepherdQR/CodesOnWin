/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-01-10 10:59:00
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-01-17 22:49:50
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include <iostream>
#include"./ClassCollections/StudyCollection_01.hpp"
#include"./ClassCollections/StudyCollection_STL_01.hpp"


#include <vector>
#include <cstring>
#include <stdio.h>
#include <cmath>
/*
e:
cd E:\Codes\CodesOnWin\CodesOnWin\Cpps\CppStudy
.\run.bat

*/

#include"./RayTracing/Picture.h"

using namespace std;
int main() {

	//std::cout <<__cplusplus <<std::endl;



	//stlSort20210824();
	//stlIO20210824();
	//stl20210824();

	Picture::rainbow(256, 256);



    std::cout << "\nProgram ends." << std::endl;
	//system("pause");
	return 0;
}
