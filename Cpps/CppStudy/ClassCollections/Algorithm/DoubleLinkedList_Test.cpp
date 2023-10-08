/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-07-07 22:21:53
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-07-11 21:52:09
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include "DoubleLinkedList.h"
#include <iostream>
#include <format>

namespace Algorithm::DataStructure
{
    auto DoubleLinkedList::test(){
        puts("Test Basic.\n");
        std::cout << std::format("Hello {}!\n", "world");

        if(0 & 20230710) {
            std::cout << std::format("Test {}!\n", 1);

            DoubleLinkedList{DoubleLinkedList::ListType::SingleLine,{1, 2, 3, 4, 5}}.dump(1);
            DoubleLinkedList{DoubleLinkedList::ListType::SingleLine,{1}}.dump(1);
            DoubleLinkedList{DoubleLinkedList::ListType::SingleLine,std::vector<int>{}}.dump(1);
        }

        if(10 & 20230710) {
            std::cout << std::format("Test {}!\n", 2);
            if(0 & 20230710){
                DoubleLinkedList list{DoubleLinkedList::ListType::Chained,
                    std::vector<int>{1, 2, 3, 4, 5}};
                list.dump(2);
            }
            DoubleLinkedList{DoubleLinkedList::ListType::Chained,{1, 2, 3, 4, 5}}.dump(1);
            DoubleLinkedList{DoubleLinkedList::ListType::Chained,{1}}.dump(1);
            DoubleLinkedList{DoubleLinkedList::ListType::Chained,std::vector<int>{}}.dump(1);
        }
    }
}