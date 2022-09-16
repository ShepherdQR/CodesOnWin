/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-09-16 21:36:04
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-09-16 23:10:33
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

namespace Thread{

    auto func_999(){
        /* ===========

        use std:;atomic<bool> to implement mutex


        */

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


