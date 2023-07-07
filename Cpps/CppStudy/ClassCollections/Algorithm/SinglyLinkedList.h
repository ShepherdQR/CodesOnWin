/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-06-27 22:56:31
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-07-07 21:59:50
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#pragma once
#include <ctime>
#include <vector>
#include <iostream>
#include <optional>

namespace Algorithm::DataStructure
{
    class SinglyLinkedList
    {
    public:
        struct SinglyLinkedList_Node
        {
            int data;
            SinglyLinkedList_Node *pNext = nullptr;
        } *_pHead = nullptr;

        static void test();

        explicit SinglyLinkedList(const std::vector<int> &ivec);
        explicit SinglyLinkedList(std::initializer_list<int> ilist);
        virtual ~SinglyLinkedList();

        auto head()const{return _pHead;}

        auto size()->int;

        void reverse();

        void display();


        static std::vector<int> algorithm_1_IntersectionOf2List(const SinglyLinkedList &ia, const SinglyLinkedList &ib);

        static bool algorithm_2_JudgePalindrome_1(const SinglyLinkedList &ilist);
        static bool algorithm_2_JudgePalindrome_2(const SinglyLinkedList &ilist);

        /** Returns the iIndex number backward*
         *  given {1,2,3,4,5}, list[0] = 1, and the list_back[0] = 5
         *  fast pointer + slow pointer
         */
        static std::optional<int> algorithm_3_kthNumberBackward(const SinglyLinkedList &ilist, const int iIndex);

    };
}
