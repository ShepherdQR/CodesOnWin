/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-06-24 23:16:39
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-06-24 23:58:42
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/





#pragma once

#include <vector>
#include <ctime>
#include <functional>
#include <numeric>
using namespace std;
//#include <thread>
//#include <tuple>




namespace case0002_ThreeSelection{
    // case0002_ThreeSelection::funcRefactoring20210614()
    // [T00002] Refactor. Using array of pointers. //[good]
    void funcRun(void*)
    {
        std::cout << "Game Starts..." << std::endl;
    }
    void funcEnd(void*)
    {
        std::cout << "Game Ends..." << std::endl;
    }
    void funcIn(void*)
    {
        const char *pStrChoices[4] =
            {"Game Starts.", "Game Ends.", "Invalid Number, try again."};
        void(*pFunc[3])(void*) = {funcRun, funcEnd, funcIn};
        char input(0);

        if (std::cin >> input){
            input = ((input >= 48) && (input <= 50)) ? input - 48 : 2;
            std::cout << "Your choice: " << pStrChoices[input] << std::endl;
            (*pFunc[input])(nullptr);
        }
    }
    void funcRefactoring20210614()
    {
        funcIn(nullptr);
    }
}






// [T00001] Refactor. Finding the missing number.
auto case0001_FindTheMissingNumber()
{
    // shuffering random; find the missing number.
    int numSize = 100;
    std::vector<int> vecNum;
    for(int i = 0; i<numSize; ++i)
        vecNum.push_back(i);
    vecNum[11] = 0;

    srand(time(0));
    for(int i = 0; i < numSize; ++i)
        swap(vecNum[ i + rand()%(numSize-i) ], vecNum[i]);

    for(int i = 0; i<numSize; ++i)
            std::cout << vecNum[i] << "\t";

    std::cout << "\nThe missing number is: " << [](std::vector<int>* ipVec){
        return (ipVec->size()-1)*ipVec->size()/2 - accumulate(ipVec->begin(),ipVec->end(),0); 
        }(&vecNum)  << std::endl;
}
