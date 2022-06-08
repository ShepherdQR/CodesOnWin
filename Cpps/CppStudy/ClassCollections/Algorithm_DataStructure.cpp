/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-06-08 21:36:02
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-06-08 23:28:48
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


#include"Algorithm_DataStructure.h"
#include<stack>



namespace Algorithm_DataStructure
{

    vector<int> SinglyLinkedList::algorithm_1_IntersectionOf2List(const SinglyLinkedList& ia, const SinglyLinkedList& ib){

        vector<int> ovec;

        SinglyLinkedList_Node* pa = ia._pHead;
        SinglyLinkedList_Node* pb = ib._pHead;

        while(pa && pb){
            if(pa->data<pb->data){
                pa = pa->pNext;
            }
            else if(pa->data>pb->data){
                pb = pb->pNext;
            }
            else{
                ovec.emplace_back(pa->data);
                pa = pa->pNext;
                pb = pb->pNext;
            }
        }
        while(pa){
            pa = pa->pNext;
            ovec.emplace_back(pa->data);
        }
        while(pb){
            pb = pb->pNext;
            ovec.emplace_back(pb->data);
        }
        
        return ovec;
    }

    // 快慢指针+stack实现
    bool SinglyLinkedList::algorithm_2_JudgePalindrome_1(const SinglyLinkedList& ilist){
        bool out(true);
        std::stack<int> stack;
        SinglyLinkedList_Node* plist = ilist._pHead;
        SinglyLinkedList_Node* plistFast = plist;
        while(plistFast){
            plistFast = plistFast->pNext;
            if(plistFast){
                plistFast = plistFast->pNext;
                stack.emplace(plist->data);
            }
            plist = plist->pNext;
        } cout << " ["<< plist->data << "] ";
        //{1,2,3,4,5}, stack[1,2], pList[4,5]
        //{1,2,3,9,2,1}, stack[1,2,3], pList[9,2,1]
        
        while(plist){
            cout << "AA" << stack.top() << "--" << plist->data <<  "aa ";
            if(stack.top() !=(plist->data))
            {
                out = false;
                break;
            }
            stack.pop();
            plist = plist->pNext;
        }
        return out;
    }

    bool SinglyLinkedList::algorithm_2_JudgePalindrome_2(const SinglyLinkedList& ilist){
        bool out(true);


        SinglyLinkedList_Node* plist = ilist._pHead;
        SinglyLinkedList_Node* plistFast = plist;
        while(plistFast && plistFast->pNext && plistFast->pNext->pNext){
            plistFast = plistFast->pNext->pNext;
            plist = plist->pNext;
        }//cout << plist->data << endl;

        auto lambdaReverse = [](SinglyLinkedList_Node*& iop){
            SinglyLinkedList_Node* pCur = iop;
            SinglyLinkedList_Node* pPrevious = nullptr;
            while(pCur){
                SinglyLinkedList_Node* pTemp = pCur->pNext;
                pCur->pNext = pPrevious;
                pPrevious = pCur;
                pCur = pTemp;
            }
            iop = pPrevious;
        };
        
        lambdaReverse(plist);

        SinglyLinkedList_Node* plistHead = ilist._pHead;
        SinglyLinkedList_Node* plistTail = plist;
        while(plistHead && plistTail){
            cout << "HH" <<  plistHead->data << "-" << plistTail->data << "tt ";
            if(plistHead->data !=plistTail->data){
                out =false;
                break;
            }
            plistHead = plistHead->pNext;
            plistTail = plistTail->pNext;
        }

        lambdaReverse(plist);

        return out;
    }

}


