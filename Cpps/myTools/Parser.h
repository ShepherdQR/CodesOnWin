/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-09-18 13:11:22
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-09-18 13:55:17
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

//Parser.h
#pragma once


#include <array>
#include <chrono>

class Parser{

public:

    static const std::array<int , 6>& objs(){
        static const std::array<int , 6> sout{0, 1,2,3,4,5};
        return sout;
    }
    const std::array<int, 6>& _obj{objs()};


    const std::array<int , 6>& objs_R(){
        return _obj;
    }


    void test(){

        printf("\t%d\n", _obj[2]);


        // function returning const A& beats the one returning static const A&
        // when call many times, [const A&][fast]  VS [static const A&][slow]
        Parser p;
        {   // 2931 microseconds
            std::chrono::system_clock::time_point t1 = std::chrono::system_clock::now();
            size_t total{0};
            for(int i=0;i<1000000;++i){
                total += p.objs().size();
            }
            std::chrono::system_clock::time_point t2 = std::chrono::system_clock::now();
            std::cout << duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microseconds." << std::endl;
        }
        {   // 2816 microseconds
          std::chrono::system_clock::time_point t1 = std::chrono::system_clock::now();
            size_t total{0};
            for(int i=0;i<1000000;++i){
                total += p.objs_R().size();
            }
            std::chrono::system_clock::time_point t2 = std::chrono::system_clock::now();
            std::cout << duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microseconds." << std::endl;
        }
    }

};
