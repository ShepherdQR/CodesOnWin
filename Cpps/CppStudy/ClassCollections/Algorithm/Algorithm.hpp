/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-07-01 21:02:53
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-07-07 22:38:27
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#pragma once

#include "Algorithm_Base.hpp"
#include "Algorithm_DataStructure.hpp"


#include "SinglyLinkedList.h"
#include "SinglyLinkedList.cpp"
#include "SinglyLinkedList_Algorithm.cpp"
#include "SinglyLinkedList_Test.cpp"

#include "DoubleLinkedList.h"
#include "DoubleLinkedList.cpp"
#include "DoubleLinkedList_Algorithm.cpp"
#include "DoubleLinkedList_Test.cpp"

namespace Algorithm
{
    auto test()->void{
        // Algorithm::DataStructure::SinglyLinkedList::test();
        Algorithm::DataStructure::DoubleLinkedList::test();
    }
}