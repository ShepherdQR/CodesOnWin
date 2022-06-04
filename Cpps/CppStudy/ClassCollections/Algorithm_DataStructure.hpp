/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-06-03 20:31:04
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-06-04 10:55:31
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#pragma once
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;



namespace Algorithm_DataStructure
{







    auto display(const vector<int>& ivec){
        for(auto cur:ivec){
            cout << cur << ", ";
        }cout << endl;
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


    auto test(){
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


