/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-07-07 22:21:32
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-07-07 23:17:44
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


#include "DoubleLinkedList.h"
#include <iostream>
#include <format>


namespace Algorithm::DataStructure
{
    DoubleLinkedList::DoubleLinkedList(const std::vector<int> &ivec)
    {
        using spNode = std::shared_ptr<DoubleLinkedList_Node>;
        using wpNode = std::weak_ptr<DoubleLinkedList_Node>;

        if (ivec.empty()){
            std::cout << "Empty DoubleLinkedList" << std::endl;
        } else{
            _spHead = std::make_shared<DoubleLinkedList_Node>();
            if(!_spHead){
                return;
            }
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
}