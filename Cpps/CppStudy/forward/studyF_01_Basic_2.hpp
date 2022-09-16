/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-09-03 21:20:32
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-09-16 23:48:57
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#pragma once

#include <iostream>
#include <mutex>
#include <thread>
#include <future>


namespace Basic{


    auto func_998(){

        /* ===========
        msvc _MSC_VER
        clang __clang__
        gcc __GNUC__

        */

    }

    auto func_41(){
        struct A1{
            char a;
            int b;
            double c;
            long long d;
        };

        struct  alignas(max_align_t)   A2{
            char a;
            int b;
            double c;
            long long d;
        };

        std::cout << alignof(A1) << std::endl;//8
        std::cout << alignof(A2) << std::endl;//16


    }

    std::string operator"" _wow1(const char* ipchar, size_t len){
        return std::string{ipchar} + "_ww1";
    }
    std::string operator"" _wow2(unsigned long long l){
        return std::to_string(l) + "_ww2";
    }

    auto func_40(){
        std::string str{R"(c\t\t\t)"};
        std::cout << str << std::endl;//c\t\t\t

        auto str1 = "abc"_wow1;
        auto str2 = 2_wow2;
        std::cout << str1 << std::endl; // abc_ww1
        std::cout << str2 << std::endl; // 2_ww2


    }



    auto func_39_1_Throw(){throw true;}
    auto func_39_1_Throw_NO() noexcept {}
    auto func_39(){

        auto lambdaThrow = []{
            func_39_1_Throw();
        };
        auto lambdaThrow_NO = []noexcept{
            func_39_1_Throw_NO();
        };

        {


            std::cout << noexcept(func_39_1_Throw()) << std::endl; //0
            std::cout << noexcept(func_39_1_Throw_NO()) << std::endl; //1
            std::cout << noexcept(lambdaThrow()) << std::endl; //0
            std::cout << noexcept(lambdaThrow_NO()) << std::endl; //1
        }

        {

            auto l = [i{0}](std::function<void(void)> iFunc)mutable{
                ++i; 
                try{
                    iFunc();
                } catch(...){
                    std::cout << "Throw: " << i << std:: endl;
                }
            };

            l(func_39_1_Throw); //Throw: 1
            l(func_39_1_Throw_NO); // no catch
            l(lambdaThrow); //Throw: 3
            l(lambdaThrow_NO); // no catch

        } 
        



    }


    auto func_37(){
        
        std::packaged_task<int()> task([](){return 20220903;});
      
        std::future<int> result = task.get_future();
        std::thread(std::move(task)).detach();
        
        puts("waiting...") ;

        result.wait(); // block until future has arrived
        // output result
        std::cout << "done!" << std:: endl << "future result is " << result.get() << std::endl;
    }



    int func_36_value{1};

    auto func_36_1(int iv){
        static std::mutex m;
        //std::lock_guard<std::mutex> lock(m);
        //func_36_value = iv;
        std::unique_lock<std::mutex> lock(m);
        func_36_value = iv;
        std::cout << func_36_value << std::endl;
        lock.unlock();

        lock.lock();
        func_36_value +=1;
        std::cout << func_36_value << std::endl;

    }

    auto func_36(){

        std::thread t([]{std::cout << "hi" << std::endl;});
        t.join();

        std::thread t1(func_36_1,2), t2(func_36_1,3);
        t1.join();// 2,3
        t2.join();//3,4

    }


}