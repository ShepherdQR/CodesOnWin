/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-06-27 22:56:31
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-06-27 23:22:08
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#pragma once
#include <ctime>
#include <vector>
#include <iostream>

namespace Algorithm::DataStructure
{
    
    inline auto dumpVector(const std::vector<int>& ivec){
        for(auto cur:ivec){
            std::cout << cur << ", ";
        }std::cout << std::endl;
    }

    class SinglyLinkedList
    {
        struct SinglyLinkedList_Node
        {
            int data;
            SinglyLinkedList_Node *pNext = nullptr;
        } *_pHead = nullptr;

    public:
        static void test();

        SinglyLinkedList(const std::vector<int> &ivec)
        {
            if (ivec.size() > 0)
            {
                _pHead = new SinglyLinkedList_Node;
                _pHead->data = ivec[0];
            }
            SinglyLinkedList_Node *pCur = _pHead;
            for (int i = 1; i != ivec.size(); ++i)
            {
                SinglyLinkedList_Node *pTemp = new SinglyLinkedList_Node;
                pTemp->data = ivec[i];
                pCur->pNext = pTemp;
                pCur = pTemp;
            }
        }

        SinglyLinkedList(std::initializer_list<int> ilist) : SinglyLinkedList(std::vector<int>(ilist)) {}

        ~SinglyLinkedList()
        {
            SinglyLinkedList_Node *pCur = _pHead;
            while (pCur)
            {
                SinglyLinkedList_Node *pTemp = pCur;
                pCur = pCur->pNext;
                delete pTemp;
            }
        }

        void reverse()
        {
            SinglyLinkedList_Node *pCur = _pHead;
            SinglyLinkedList_Node *pPrevious = nullptr;
            while (pCur)
            {
                SinglyLinkedList_Node *pTemp = pCur->pNext;
                pCur->pNext = pPrevious;
                pPrevious = pCur;
                pCur = pTemp;
            }
            _pHead = pPrevious;
        }

        void display()
        {
            SinglyLinkedList_Node *pCur = _pHead;
            while (pCur)
            {
                std::cout << pCur->data << ", ";
                pCur = pCur->pNext;
            }
            std::cout << std::endl;
        }

        static std::vector<int> algorithm_1_IntersectionOf2List(const SinglyLinkedList &ia, const SinglyLinkedList &ib);

        static bool algorithm_2_JudgePalindrome_1(const SinglyLinkedList &ilist);
        static bool algorithm_2_JudgePalindrome_2(const SinglyLinkedList &ilist);

    };
}
