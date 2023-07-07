/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-06-27 23:00:16
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-07-07 21:53:22
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include "SinglyLinkedList.h"
#include <stack>

namespace Algorithm::DataStructure
{
    using namespace std;

    SinglyLinkedList::SinglyLinkedList(const std::vector<int> &ivec)
    {
        if (ivec.size() == 0){
            std::cout << "Empty SinglyLinkedList" << std::endl;
        }

        if (ivec.size() > 0){
            _pHead = new SinglyLinkedList_Node;
            _pHead->data = ivec[0];
        }
        SinglyLinkedList_Node *pCur = _pHead;
        for (int i = 1; i < ivec.size(); ++i){
            SinglyLinkedList_Node *pTemp = new SinglyLinkedList_Node;
            pTemp->data = ivec[i];
            pCur->pNext = pTemp;
            pCur = pTemp;
        }
    }

    SinglyLinkedList::SinglyLinkedList(std::initializer_list<int> ilist) : SinglyLinkedList(std::vector<int>(ilist)) {}

    SinglyLinkedList::~SinglyLinkedList(){
        SinglyLinkedList_Node *pCur = _pHead;
        while (pCur){
            SinglyLinkedList_Node *pTemp = pCur;
            pCur = pCur->pNext;
            delete pTemp;
        }
    }

    void SinglyLinkedList::reverse(){
        SinglyLinkedList_Node *pCur = _pHead;
        SinglyLinkedList_Node *pPrevious = nullptr;
        while (pCur){
            SinglyLinkedList_Node *pTemp = pCur->pNext;
            pCur->pNext = pPrevious;
            pPrevious = pCur;
            pCur = pTemp;
        }
        _pHead = pPrevious;
    }

    void SinglyLinkedList::display(){
        SinglyLinkedList_Node *pCur = _pHead;
        while (pCur){
            std::cout << pCur->data << ", ";
            pCur = pCur->pNext;
        }
        std::cout << std::endl;
    }

    auto SinglyLinkedList::size()->int{
        int out{};
        auto pCur{_pHead};
        while(pCur){
            ++out;
            pCur = pCur->pNext;
        }
        return out;
    }
}
