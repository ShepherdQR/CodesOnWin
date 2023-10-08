/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-07-07 22:21:17
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-07-11 21:59:14
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


#pragma once
#include <vector>
#include <optional>
#include <memory>
#include <iostream>
#include <format>

namespace Algorithm::DataStructure
{

    /** Returns the iIndex number backward*
     *  SingleLine, doublely linked list
     *  Chained, circular, doublely linked list
     *  Sentinel, circular, doublely linked list, with sentinel
     */
    class DoubleLinkedList
    {
    public:
        struct DoubleLinkedList_Node;
        using spNode = std::shared_ptr<DoubleLinkedList_Node>;
        using wpNode = std::weak_ptr<DoubleLinkedList_Node>;

        struct DoubleLinkedList_Node
        {
            int data{};
            wpNode previous{};
            spNode next{};
            //wpNode next{}; // use wp, the value is temprory.
            ~DoubleLinkedList_Node(){
                std::cout << std::format("release {}!\n", data);
            }
        };
        

        static auto test();

        enum class ListType:char{
            Default = 0,
            SingleLine,         // head <-> node <-> tail
            Chained,            // head <-> node <-> tail <-> head
            Sentinel,           // p -> sentinel <-> head <-> node <-> tail <-> sentinel
            NumberListType
        };

        explicit DoubleLinkedList(const ListType iType, const std::vector<int> &ivec);
        explicit DoubleLinkedList(const ListType iType, std::initializer_list<int> ilist);
        ~DoubleLinkedList();

        auto head()const{return _spHead;}

        auto dump(const int iTimes);
        
    private:
        ListType _type{};
        spNode _spHead{};

    };

}