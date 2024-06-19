/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-09-16 21:36:04
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2024-06-15 14:44:20
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


#pragma once

#include <queue>
#include <chrono>
#include <mutex>
#include <thread>
#include <atomic>
#include <iostream>
#include <condition_variable>
#include <memory>
#include <limits>
#include <ranges>
#include <thread>
#include <mutex>
#include <chrono>
#include <numeric>
#include <list>

namespace Thread{

    auto func_999(){
        /* ===========

        use std:;atomic<bool> to implement mutex


        */

    }

    auto func_7()
    {
        using namespace std;

        if (1 & 0)
        {

            std::list<int> list;
            std::mutex mm;
            auto val{10};

           [[maybe_unused]] auto l1 = [&]
            {
                std::lock_guard g{mm};
                list.emplace_back(val);
            };
            [[maybe_unused]] auto l2 = [&]
            {
                std::scoped_lock g{mm};
                if(std::ranges::find(list, val)!= list.end())
                {
                    list.erase(list.begin());
                }
            };
             [[maybe_unused]] auto g = [&](auto&& F){
                // for(auto vv = std::views::iota(1,100)){
                //     F();
                // }
            };
        }
    }

    auto func_6(){
        using namespace std::literals;

        if(0 & 20230829)
        {
            auto i{10};
             auto l = [&i]{ std::cout << ++i << std::endl;};
            std::thread t{l};
            l();
            t.join();
        }

        if(0 & 20230829)
        {
            struct A{
                auto operator()()const{
                    puts("hi20230829");
                }
            };
            std::thread t{A{}};
            t.join();
            std::jthread jt{A{}};
        }

        if(0 & 20230829)
        {
            auto i{10};
            auto l = [&i]{ std::cout << ++i << std::endl;};
            auto m = [](auto ii){ std::cout << ++ii << std::endl;};
            std::jthread t1{m, std::ref(i)}; // 11
            std::jthread t2{m, i}; // 12
            l(); // 12
        }

        if(10 & 20230830)
        {

            if(0){
                [[maybe_unused]] auto i{10};

                struct A{
                    virtual void f(){puts("hi A");}
                };
                struct B: public A{
                    virtual void f(){puts("hi B");}
                };

                A a;
                B b;
                {std::jthread t{&A::f, &a};} // hi A
                {std::jthread t{&A::f, &b};} // hi B
                {std::jthread t{&B::f, &b};} // hi B
            }

            if(0){

                auto l = []{
                    for(auto i : std::views::iota(1,6)){
                        std::cout << i << std::endl;
                        std::this_thread::sleep_for(500ms);
                    }
                };

                std::jthread t1{l}, t2, t3; // thread starts from here
                puts("hi 1");
                std::this_thread::sleep_for(1000ms);
                t2 = std::move(t1);
                puts("hi 2");
                std::this_thread::sleep_for(1000ms);
                t2 = [](auto&& i){return std::move(i);}(t2);
                t3 = [](auto&& i){return std::move(i);}(t2);

                const auto numberMax{std::thread::hardware_concurrency()}; // 8
                std::cout << numberMax << std::endl;

            }

            if(0 & 1){
                const std::vector ll{1,2,3,4,5};
                auto head = ll.cbegin();
                std::advance(head, 20);
                if(head == ll.cend()){
                    puts("hi 1");
                }else if(head > ll.cend()){
                    std::cout << std::distance(head, ll.cend());
                }
            }
        }

        if(20230904){

            if(0 & 1){
                auto l = []<typename Iterator>
                (Iterator first, Iterator last){

                    typedef typename Iterator::value_type T;

                    auto ll = [](Iterator f1, Iterator f2, T& o){
                        o = std::accumulate(f1, f2, o);
                    };

                    const auto numberThreadHardware = std::thread::hardware_concurrency();
                    const auto numberThread = numberThreadHardware - 1;

                    const auto length = std::distance(first, last);
                    const auto blockSize = length / numberThread;
                    // std::cout << numberThread << ", " << blockSize << std::endl;

                    std::vector<T> result(numberThread);

                    std::vector<std::jthread> vecThread;
                    vecThread.reserve(numberThread);

                    auto blockHead = first;
                    for(size_t i{0}; i<numberThread; ++i){
                        auto blockTail = blockHead;
                        std::advance(blockTail, blockSize);
                        // vecThread[i] = std::jthread{
                        //     ll, blockHead, blockTail, std::ref(result[i])
                        // };
                        vecThread.emplace_back(
                            ll, blockHead, blockTail, std::ref(result[i])
                        );
                        blockHead = blockTail;
                    }
                    ll(blockHead, last, result[numberThread-1]);

                    // for(auto& cur: vecThread){
                    //     cur.join();
                    // }

                    // for(auto cur:result ){
                    //     std::cout << cur << std::endl;
                    // }

                  
                    auto out{0};
                    return std::accumulate(result.begin(), result.end(), out);
                };

                {
                    //std::vector<int> vv(10000);
                    //std::iota(vv.begin(), vv.end(),0);

                    auto vv = std::views::iota(1,1000);
                    //std::cout << vv[22] << ", " << vv.size() << std::endl;
                   
                    std::cout << std::this_thread::get_id() << std::endl;
                    std::cout << l(vv.begin(), vv.end()) << std::endl;
                }
            }

        }

    }



    auto func_5(){

        {
            std::atomic<int> counter{};

            std::vector<std::thread> vt;
            for(int i = 0; i <100;++i){
                vt.emplace_back([&]{
                    counter.fetch_add(1, std::memory_order_relaxed);
                });
            }

            for(auto& t:vt){
                t.join();
            }
            std::cout << counter << std::endl;
        }

        {
            std::atomic<int*> ptr{};
            int v{};
            std::thread producer{[&]{
                int* p{new int{20220916}};
                v = 1;
                ptr.store(p, std::memory_order_release);
            }};

            std::thread consumer{[&]{
                int*p{};
                while(!(p = ptr.load(std::memory_order_consume)));
                std::cout << "p = " << *p << std::endl;
                std::cout << "v = " << v << std::endl;
            }};

            producer.join();
            consumer.join();

        }

        {
            std::vector<int> v;
            std::atomic<int> flag{};
            std::thread release{[&]{
                v.push_back(1);
                flag.store(1, std::memory_order_release);
            }};

            std::thread acq_rel{[&]{
                int expect{1};
                while(!flag.compare_exchange_strong(expect, 2, std::memory_order_acq_rel)){
                    expect = 1;
                }
            }};

            std::thread acquire{[&]{
                while(flag.load(std::memory_order_acquire) < 2);
                std::cout << v.at(0) << std::endl;
            }};

            release.join();
            acq_rel.join();
            acquire.join();
        }

        {
            std::atomic<int> counter{0};
            std::vector<std::thread> vt;
            for(int i=0;i<100;++i){
                vt.emplace_back([&]{
                    counter.fetch_add(1, std::memory_order_seq_cst);
                });
            }
            for(auto& c: vt){
                c.join();
            }
            std::cout << counter << std::endl;
        }


            /*
                100
                p = 20220916
                v = 1
                1
                100
            */
    }

    auto func_4(){
        struct A{
            float x;
            int y;
            long long z;
        };

        std::atomic<A> a;
        //std::cout << std::boolalpha << a.is_lock_free() << std::endl;//undefined reference to `__atomic_is_lock_free'
    }

    auto func_3(){
        std::atomic<int> count{};

        std::thread t1{[&]{
            count.fetch_add(1);
        }};

        std::thread t2{[&]{
            count++;
            count =count*3;
        }};

        t1.join();
        t2.join();

        std::cout << count << std::endl; //6


    }



    auto func_2(){
        int n{};


        //volatile // this makes no difference
        int flag{};

        std::thread t1{[&]{
            while(flag!=1){
                std::cout << "n = " << n << std::endl;
            }
            int b{n};
            std::cout << "b = " << b << std::endl;
        }};

        std::thread t2{[&]{
            n = 6;
            flag = 1;
        }};

        t1.join();
        t2.join();
        // cout n for many times, then cout b = 6
    }


    auto func_1(){
        std::queue<int> queueProducer;
        std::mutex mtx;
        std::condition_variable cv;
        bool bNotify = false;

        auto producer = [&]{
            int i=1;
            while(i){
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                std::unique_lock<std::mutex> lock(mtx);
                std::cout << "P\t" << i << std::endl;
                queueProducer.push(i++);
                bNotify = true;
                cv.notify_all();
            }
        };

        auto consumer = [&]{
            std::unique_lock<std::mutex> lock(mtx);
            while(!bNotify){
                cv.wait(lock);
            }

            lock.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            lock.lock();

            if(!queueProducer.empty()){
                std::cout << "Consuming\t" << queueProducer.front() << std::endl;
                queueProducer.pop();
            }
            bNotify = false;
        };

        std::thread p(producer);
        std::thread cs[2]{
            std::thread{consumer},
            std::thread{consumer}
        };

        p.join();

        for(auto& cCur:cs){
            cCur.join();
        }
    }
}


