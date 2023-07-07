/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-07-07 22:21:53
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-07-07 23:08:32
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include "DoubleLinkedList.h"
#include <iostream>


namespace Algorithm::DataStructure
{
    auto DoubleLinkedList::test(){
        puts("Test Basic.\n");
        std::cout << std::format("Hello {}!\n", "world");

        {
            std::cout << std::format("Test {}!\n", 1);
            DoubleLinkedList list{std::vector<int>{1, 2, 3, 4, 5}};
            if(auto spHead{list.head()}){
                while(spHead){
                    std::cout << spHead->data << ", ";
                    spHead = spHead->next;
                }std::cout << std::endl;
            }
        }

    }
}