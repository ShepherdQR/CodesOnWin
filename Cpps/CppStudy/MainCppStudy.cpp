/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-01-10 10:59:00
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-04-22 21:56:18
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include <iostream>
#include"./ClassCollections/StudyCollection_01.hpp"
//#include"./ClassCollections/StudyCollection_STL_01.hpp"
#include"./RayTracing/Picture.h"

#include <vector>
#include <cstring>
#include <stdio.h>
#include <cmath>
/*
e:
cd E:\Codes\CodesOnWin\CodesOnWin\Cpps\CppStudy
.\run.bat

*/




// void func(std::function<int(const int&)> func)
// {
// 	std::cout << func(2) << std::endl;
// }



using namespace std;
int main() {

	
	
	#include"TestStudy.hpp"
	

	//#include "TestRayTracing.hpp"


	//std::cout <<__cplusplus <<std::endl;//20220411, c++17

	// int x = 2;
	// //func([=](const int& iX){return iX * iX;}(x));
	// func([=](const int& iX){return iX * iX;});

	//return 0;

	//stlSort20210824();
	//stlIO20210824();
	//stl20210824();



	void f(int i);

	f(10);


	  cout << (int*)((void*) &f  ) << "---";




    std::cout << "\nProgram ends." << std::endl;
	//system("pause");
	return 0;
}


void f(int i)
{
	cout << i << endl;
}
