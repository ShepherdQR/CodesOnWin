/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-06-03 20:31:04
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-03-02 22:19:52
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#pragma once
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;



namespace Algorithm_DataStructure
{
    /**
     1)HashTable, 增删改查时间复杂度是O(1)，常数时间比较大。基础类型按值传递；非急促类型内部按引用传递。
     2）OredredTable，按Key维持有序，key需要可以比较。增删改查时间复杂度是O(logN)红黑树、AVL树、Size-Balance-Tree、跳表。

     */

    inline auto display(const vector<int>& ivec){
        for(auto cur:ivec){
            cout << cur << ", ";
        }cout << endl;
    }

    class SinglyLinkedList{

        struct SinglyLinkedList_Node{
            int data;
            SinglyLinkedList_Node* pNext=nullptr;
        }* _pHead = nullptr;

    public:        


        SinglyLinkedList(const vector<int>& ivec){
            if(ivec.size()>0){
                _pHead= new SinglyLinkedList_Node;
                _pHead->data = ivec[0];
            }
            SinglyLinkedList_Node* pCur = _pHead;
            for(int i=1;i!=ivec.size();++i){
                SinglyLinkedList_Node* pTemp = new SinglyLinkedList_Node;
                pTemp->data = ivec[i];
                pCur->pNext = pTemp;
                pCur = pTemp;
            }
        }

        SinglyLinkedList(std::initializer_list<int> ilist):SinglyLinkedList(std::vector<int>(ilist)){}

        ~SinglyLinkedList(){
            SinglyLinkedList_Node* pCur = _pHead;
            while(pCur){
                SinglyLinkedList_Node* pTemp = pCur;
                pCur = pCur->pNext;
                delete pTemp;
            }
        }

        void reverse(){
            SinglyLinkedList_Node* pCur = _pHead;
            SinglyLinkedList_Node* pPrevious = nullptr;
            while(pCur){
                SinglyLinkedList_Node* pTemp = pCur->pNext;
                pCur->pNext = pPrevious;
                pPrevious = pCur;
                pCur = pTemp;
            }
            _pHead = pPrevious;
        }

        void display(){
            SinglyLinkedList_Node* pCur = _pHead;
            while(pCur){
                cout << pCur->data << ", ";
                pCur = pCur->pNext;
            }cout << endl;
        }

        static vector<int> algorithm_1_IntersectionOf2List(const SinglyLinkedList& ia, const SinglyLinkedList& ib);

        static bool algorithm_2_JudgePalindrome_1(const SinglyLinkedList& ilist);
        static bool algorithm_2_JudgePalindrome_2(const SinglyLinkedList& ilist);
    };

    inline auto test_SinglyLinkedList(){
        printf("Test Basic.\n");
        SinglyLinkedList a({1,2,3,4,5});
        a.display();
        a.reverse();
        a.display();

        printf("Test Algorithm 01.\n");
        Algorithm_DataStructure::display(
            SinglyLinkedList::algorithm_1_IntersectionOf2List(
                SinglyLinkedList({1,2,3,4,5}),  SinglyLinkedList({0,2,3,3,5})
            )
        );

        printf("Test Algorithm 02_1.\n");
        cout << SinglyLinkedList::algorithm_2_JudgePalindrome_1({1,2,3,4,5}) << ", "
        << SinglyLinkedList::algorithm_2_JudgePalindrome_1({1,2,3,9,2,1}) << ", "
        << SinglyLinkedList::algorithm_2_JudgePalindrome_1({1,2,3,2,1}) << endl;//0,0,1

        printf("Test Algorithm 02_2.\n");

        SinglyLinkedList aA2_2_a({1,2,3,4,5});
        SinglyLinkedList aA2_2_b({1,2,3,3,2,1});
        cout << SinglyLinkedList::algorithm_2_JudgePalindrome_2(aA2_2_a) << ", "
        << SinglyLinkedList::algorithm_2_JudgePalindrome_2(aA2_2_b) << ", "
        << SinglyLinkedList::algorithm_2_JudgePalindrome_2({1,2,3,2,1}) << endl;//0,1,1
        aA2_2_a.display();
        aA2_2_b.display();
    }






    class Heap{
    public:
        enum class Type: bool{
            MaxHeap = true,
            MinHeap = false
        };

        int size()const{return _vec.size();}

        bool setNumber(const int iIndex, const int iNum){
            if(iIndex>=_vec.size()){
                return false;
            }
            int old = _vec[iIndex];
            _vec[iIndex] = iNum;
            if(old == iNum){
                return true;
            }

            if((old < iNum && (_typeIsGreater == Type::MaxHeap))
            ||(old > iNum && (_typeIsGreater != Type::MaxHeap))
            )
            {
                _heapInsert(iIndex);
                return true;
            }
            _heapify(iIndex);
            return true;
        }

        void display(){
            Algorithm_DataStructure::display(_vec);
        }
        Heap(Type iType, const vector<int>& ivec){
            _typeIsGreater = iType;
            int case_type = 1;
            if(case_type == 0){
                //O(N*logN)
                for(const auto& cur: ivec){
                    add(cur);
                    //Algorithm_DataStructure::display(_vec);
                }
            }
            else if (case_type == 1){
                _vec = ivec;

                //O(N)
                for(int i=_vec.size()-1;i>=0;--i){
                    _heapify(i);
                }
            }

        }
        
        // O(logN)
        void add(const int ival){
            _vec.push_back(ival);

            _heapInsert(_vec.size()-1);
        }

        // O(logN)
        int pop(){
            int out = _vec[0];
            _vec[0] = _vec.back();
            _vec.pop_back();

            _heapify(0);
            return out;
        }

    private:
        std::vector<int> _vec;
        Type _typeIsGreater;
        //MaxHeap, we need to make sure that parent > child, if not, swap.
        bool _bJudgeAndSwap(const int a, const int b){
            bool bSwap = (_typeIsGreater == Type::MaxHeap)? (_vec[a]<_vec[b]):(_vec[b]>_vec[a]);
            if(bSwap){
                swap(_vec[a], _vec[b]);
            }
            return bSwap;
        }

        void _heapInsert(const int iIndex){
            int idChild = iIndex;
            int idParent = (idChild-1)/2;
            while(_bJudgeAndSwap(idParent, idChild)){
                
                idChild = idParent;
                idParent = (idChild-1)/2;
            }
        }

        void _heapify(const int iIndex){
            int indexParent = iIndex;
            int indexChildL = 2*indexParent + 1;
            //int indexChildR = 2*indexParent + 2;

            int size = _vec.size();
            while(indexChildL<size){
                int indexSwap = indexChildL;
                if(indexChildL+1<size && (_vec[indexChildL] < _vec[indexChildL+1])){
                    indexSwap +=1;
                }
                if(!_bJudgeAndSwap(indexParent, indexSwap))
                {
                    break;
                }
                indexParent = indexSwap;
                indexChildL = 2*indexParent + 1;
            }
        }
    };
    inline auto test_Heap(){
        Heap(Heap::Type::MaxHeap, {5,3,6,7,7}).display();//77563

        Heap hp(Heap::Type::MaxHeap, {9,7,8,6,5,4,3,1});
        hp.pop();
        hp.display();//8746513
        int sz = hp.size();
        for(int i=0;i!=sz;++i){
            cout << hp.pop() << ", ";
        }cout << endl;
    }
    
}


