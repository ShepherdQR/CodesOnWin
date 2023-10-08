/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-07-07 22:21:32
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-07-11 21:53:06
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


#include "DoubleLinkedList.h"
#include <iostream>
#include <format>


namespace Algorithm::DataStructure
{
    DoubleLinkedList::DoubleLinkedList(const ListType iType, const std::vector<int> &ivec)
    {
        if (ivec.empty()){
            std::cout << "Empty DoubleLinkedList" << std::endl;
            return;
        }

        using spNode = std::shared_ptr<DoubleLinkedList_Node>;
        using wpNode = std::weak_ptr<DoubleLinkedList_Node>;

        _type = iType;

        switch (_type)
        {
        case DoubleLinkedList::ListType::SingleLine:
        {
            if((_spHead = std::make_shared<DoubleLinkedList_Node>())){
                _spHead->data = ivec[0];
                spNode spPrevious{_spHead};

                for(int i=1;i<ivec.size();++i){
                    if(spPrevious){
                        if (auto spCur{std::make_shared<DoubleLinkedList_Node>()}){
                            spCur->data = ivec[i];
                            spPrevious->next = spCur;
                            spCur->previous = spPrevious;
                            spPrevious = spCur;
                        }
                    }
                }   
            }
        }
        break;

        case DoubleLinkedList::ListType::Chained:
        {
            if((_spHead = std::make_shared<DoubleLinkedList_Node>())){
                _spHead->data = ivec[0];
                spNode spPrevious{_spHead};

                for(int i=1;i<ivec.size();++i){
                    if(spPrevious){
                        if (auto spCur{std::make_shared<DoubleLinkedList_Node>()}){
                            spCur->data = ivec[i];
                            spPrevious->next = spCur;
                            spCur->previous = spPrevious;
                            spPrevious = spCur;
                        }
                    }
                }
                spPrevious->next = _spHead;
                _spHead->previous = spPrevious;
            }
        }
            break;
        default:
            break;
        }
    }

    DoubleLinkedList::DoubleLinkedList(const ListType iType, std::initializer_list<int> ilist) 
    : DoubleLinkedList(iType, std::vector<int>(ilist)) {}
    
    DoubleLinkedList::~DoubleLinkedList(){

        switch (_type){
        case DoubleLinkedList::ListType::SingleLine:{
            // can control release order
            if(0 && _spHead){
                _spHead->next ={}; // release order: node, tail, head
            }
            break;
        }
        case DoubleLinkedList::ListType::Chained:{
            if(_spHead){
                // _spHead->next ={}; // release order: node, tail, head
                _spHead.reset(); // release order: head, node, tail
            }
            break;
        }

        default:
            break;
        }

    }

    auto DoubleLinkedList::dump(const int iTimes){

        if(iTimes>=1){
            if(auto spHeadRaw{this->head()}){
                int loopTimes{iTimes};
                std::cout << spHeadRaw->data << ", ";
                //auto spHead{wpHead.lock()};
                auto spHead{spHeadRaw->next};
                while(spHead){
                    if(spHead == spHeadRaw){
                        --loopTimes;
                        std::cout << std::endl;
                    }
                    if(loopTimes <=0){
                        break;
                    }
                    std::cout << spHead->data << ", ";
                    //spHead = (spHead->next).lock();
                    spHead = spHead->next;
                }std::cout << std::endl << std::endl;
            }
        }
    }
}