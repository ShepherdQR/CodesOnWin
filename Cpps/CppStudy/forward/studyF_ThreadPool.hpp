/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-07-25 21:44:22
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-07-25 22:10:09
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#include <iostream>
#include <future>
#include <thread>
#include <chrono>

/*================================================================
https://blog.csdn.net/xiongya8888/article/details/100135227
https://www.runoob.com/w3cnote/cpp-std-thread.html
https://blog.csdn.net/Echo_dia/article/details/100520433

*/


namespace ThreadPool{
    
    namespace V1{
        void f(std::promise<int>& ip){
            //puts("Waiting...");
            std::this_thread::sleep_for(std::chrono::seconds(3));

            int val {20220725};

            ip.set_value(val);

            std::this_thread::sleep_for(std::chrono::seconds(3));
            //puts("Exit...");
        }

        auto func_1(){

            std::promise<int> p;

           
            std::future<int> yyf = p.get_future();

            std::thread th(f, std::ref(p));

            int val = yyf.get();
            std::cout << val << std::endl;

            th.join();
            
        }   

    }

    auto func_1(){
        V1::func_1();

    }


}