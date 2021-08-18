/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-08-02 16:15:02
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2021-08-18 22:50:53
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#include "./ClassCollections/NNGameMain.h"
#include "./ClassCollections/NNTensor.h"
#include <iostream>

/*
e:
cd E:\Codes\CodesOnWin\CodesOnWin\Cpps\NNGame
.\run.bat

*/


int main()
{
	double metric[4] = { 2,3,4,5 };
	std::vector<int>* pvecSpaceMetric = new std::vector<int>(4);
	for (int i = 0; i < 4; ++i)
		(*pvecSpaceMetric)[i] = metric[i];


	NNTensor myTensor(pvecSpaceMetric);

	return 0;
}

