/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-06-03 20:31:04
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-06-27 23:24:29
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#pragma once
#include <ctime>
#include <vector>
#include <iostream>

#include "SinglyLinkedList.h"

namespace Algorithm_DataStructure
{
    /**
     1)HashTable, 增删改查时间复杂度是O(1)，常数时间比较大。基础类型按值传递；非急促类型内部按引用传递。
     2）OredredTable，按Key维持有序，key需要可以比较。增删改查时间复杂度是O(logN)红黑树、AVL树、Size-Balance-Tree、跳表。

     */

    inline auto display(const std::vector<int>& ivec){
        for(auto cur:ivec){
            std::cout << cur << ", ";
        }std::cout << std::endl;
    }

    auto test11()->void{
        Algorithm::DataStructure::SinglyLinkedList a{1};
        Algorithm::DataStructure::SinglyLinkedList r5{1};
        Algorithm::DataStructure::SinglyLinkedList::test();
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
        Heap(Type iType, const std::vector<int>& ivec){
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
                std::swap(_vec[a], _vec[b]);
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
            std::cout << hp.pop() << ", ";
        }std::cout << std::endl;
    }
    
}


