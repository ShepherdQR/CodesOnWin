/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-08-22 22:48:31
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2021-08-22 23:16:16
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include "Singleton.h"




// using smartPointer and mutex
/*

在某些平台（与编译器和指令集架构有关），双检锁会失效！
https://www.drdobbs.com/cpp/c-and-the-perils-of-double-checked-locki/184405726
*/
#include <iostream>
#include <memory> // shared_ptr
#include <mutex>  // mutex
std::shared_ptr<SingletonA> SingletonA::m_instance_ptr = nullptr;
std::mutex SingletonA::m_mutex;

SingletonA::SingletonA()
{
    std::cout<<"Constructor called!"<<std::endl;
}

SingletonA::~SingletonA()
{
    std::cout<<"Destructor called!"<<std::endl;
}

std::shared_ptr<SingletonA> SingletonA::getInstance()
{
  if(m_instance_ptr==nullptr){
        std::lock_guard<std::mutex> lk(m_mutex);
            if(m_instance_ptr == nullptr){
              m_instance_ptr = std::shared_ptr<SingletonA>(new SingletonA);
        }
    }
    return m_instance_ptr;
}

void testSingletonA20210822()
{
    std::shared_ptr<SingletonA> spInstance1 = SingletonA::getInstance();
    std::shared_ptr<SingletonA> spInstance2 = SingletonA::getInstance();
}
////////////////////////////////
////////////////////////////////
////////////////////////////////


/**
Meyers' Singleton提出，
所用到的特性是在C++11标准中的Magic Static特性：
If control enters the declaration concurrently while the variable is being initialized, the concurrent execution shall wait for completion of the initialization.

*/
#include <iostream>

SingletonB::SingletonB()
{
    std::cout<<"Constructor called!"<<std::endl;
}

SingletonB::~SingletonB()
{
    std::cout<<"Destructor called!"<<std::endl;
}

SingletonB& SingletonB::getInstance()
{
    static SingletonB instance;
    return instance;
}

void testSingletonB20210822(){
    SingletonB& instance_1 = SingletonB::getInstance();
    SingletonB& instance_2 = SingletonB::getInstance();
}
