/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-09-03 21:20:32
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-10-13 23:23:04
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#pragma once

#include <iostream>
#include <mutex>
#include <thread>
#include <future>
#include <bitset>
#include <cstddef>//std::to_integer<T>(b)
// #include "./Library/fmt-9.0.0/include/fmt/core.h" //https://fmt.dev/latest/index.html
// #include "./Library/fmt-9.0.0/include/fmt/format.h"
// #include "./Library/fmt-9.0.0/include/fmt/format-inl.h"

#include <cmath>
#include <compare>
#include <algorithm>

namespace Basic{


    auto func_998(){

        /* ===========
        msvc _MSC_VER
        clang __clang__
        gcc __GNUC__

        */

    }


    auto f_func_49_1(int&)       -> int{return 42;};
    auto f_func_49_1(int const&) -> double{return 3.14;};
    auto func_49(){
        // https://en.cppreference.com/w/cpp/compiler_support

        {   // [23:1] [P1102R2] [Make () more optional for lambdas]

            std::string strCur {"abc"};
            auto noSean = [sLocal = std::move(strCur)] mutable {
                sLocal += "d";
                std::cout << sLocal << '\n'; 
            };
            noSean();

        }

        {   // [23:2] [P2036R3] [Change scope of lambda trailing-return-type][no compiler support yet]

            //This paper proposes that name lookup in the trailing-return-type of a lambda first consider that lambda’s captures before looking further outward. 
            //That is, treat the trailing-return-type like the function body rather than treating it like a function parameter.


            //  Today, both lambdas return int.
            {
                //auto f_func_49_1(int&)       -> int{return 42;};
                //auto f_func_49_1(int const&) -> double{return 3.14;};
                int i{};

                auto should_capture = [=]() -> decltype(f_func_49_1(i)) {
                    return f_func_49_1(i);
                };
                auto should_not_capture = [=]() -> decltype(f_func_49_1(i)) {
                    return 42;
                };
                std::cout << should_capture() << std::endl; //3 [should return 3.14]
                std::cout << should_not_capture() << std::endl; //42 [ill-formed]
            }
        }

        {   // [23:3] [P2173R1][Attributes on lambdas]

            auto l=[][[nodiscard]]{return 42;};
            l(); //warning: ignoring return value
            auto fetch = l();
            
        }

        {   // [20:1] [P0409R2][Allow lambda-capture [=, this]]
            // [=, *this] by value
            // [=, this] by reference

            struct A{
                int _a{};
            public:
                A(){
                    auto l = [=,*this]mutable{printf("%d\n",++_a);};   
                    l();                                //1
                    l();                                //2
                    printf("%d\n",_a);                  //0
                    [=,this]{printf("%d\n",++_a);}();   //1
                    printf("%d\n",_a);                  //1
                }
            } _;
        }

    }

    class A_func_48{
    public:
        static  constexpr int a[2]{1,2};
        int b[2]{};
        int c[a[1]]{3,4};
        double d[4] = {1,2};
        double e[4] = {1,2.0};
        std::array<int,3> f{1,2,3};
        std::vector<int> g{1,2,3};
    };
    auto func_48(){

        auto l = [](const auto& t){std::cout << t << "\t";};
        A_func_48 a;
        std::ranges::for_each(a.a,l);std::cout << std::endl;
        std::ranges::for_each(a.b,l);std::cout << std::endl;
        std::ranges::for_each(a.c,l);std::cout << std::endl;
        std::ranges::for_each(a.d,l);std::cout << std::endl;
        std::ranges::for_each(a.e,l);std::cout << std::endl;
        std::ranges::for_each(a.f,l);std::cout << std::endl;
        std::ranges::for_each(a.g,l);std::cout << std::endl;
        /* ===========
            1       2
            0       0
            3       4
            1       2       0       0
            1       2       0       0
            1       2       3
            1       2       3
        */
    }

    auto func_47(){
        union f{
            auto g(int i)->void{printf("%d\n", i);}
        };
        //f::g(42);
    }

    auto func_46_1(int i){
        puts("hi");
    }

    auto func_46(){
        // no warning at all using my compailer

        std::cout << 
        [](auto l1, [[maybe_unused]] auto l2){
            return 42;
        }(1,"hi") << std::endl;

        struct A{
            static void f(int i1, [[maybe_unused]] int i2){
                puts("hi");
            }
        };
        A::f(1,2);
        A::f(1,22);

        func_46_1(42);


    }

    auto func_45(){
        // three-way comparison operator

        for(const auto& cur: {0,1,2,3}){
            const int base{1};

            // std::strong_ordering, std::weak_ordering

            std::strong_ordering result{cur<=>base};
            if (result == std::strong_ordering::less) { std::cout << "less" << std::endl; }
            if (result == std::strong_ordering::greater) { std::cout << "greater" << std::endl; }
            if (result == std::strong_ordering::equal) { std::cout << "equal" << std::endl; }
            
            std::cout << "<<<\t " << cur << " VS " << base << std::endl;
            std::cout << "std::is_lt(result)\t" << std::is_lt(result) << std::endl;
            std::cout << "std::is_lteq(result)\t" << std::is_lteq(result) << std::endl;
            std::cout << "std::is_eq(result)\t" << std::is_eq(result) << std::endl;
            std::cout << "std::is_gt(result)\t" << std::is_gt(result) << std::endl;
            std::cout << "std::is_gteq(result)\t" << std::is_gteq(result) << std::endl;
             std::cout << "\t\t>>>"<< std::endl;

            // switch(int i{};result){//error: switch quantity not an integer
            //     using std::strong_ordering;
            //     case less : ++i;
            //     case greater : ++i;
            //     case equal : printf("%d\n", ++i);
            // }
        }
    }

    auto func_44(){
        enum class A{a, b, c, d};
        A a1{A::b};
        switch(a1){
            using enum A;
            case a: a1 = b; break;
            case b: a1 = c; [[fallthrough]];
            case c: a1 = d; break;
            default:break;
        }
        if(auto l=[](A&& ia){
            printf("\t%d\n", static_cast<int>(ia));
        };a1 == A::d){
            l(std::move(a1)); // 3
        }
    }

    auto func_43(){
        //fmt::print("hi{}", 42);
        auto f = 3.141'5926'54f;
        std::byte b{42};
        std::cout << std::to_integer<int>(b)  << ", " << sizeof(b) << std::endl;//42,1
        printf("dd%f\n", f);

        std::cout << std::numeric_limits<int>::max() << std::endl;
        std::cout << std::numeric_limits<int>::min() << std::endl;

        float myINF{static_cast<float>(1.0/0.0)};
        std::cout << std::isnan(myINF) << std::endl; //0
        std::cout << std::isinf(myINF) << std::endl; //1
        std::cout << (myINF>0.0) << std::endl; //1
        std::cout << (myINF<0.0) << std::endl; //0
        std::cout << (myINF== std::numeric_limits<float>::infinity()) << std::endl; //1

    }

    auto func_42(){

        // use of a->b && a->b->c, only on idempotent function
        // idempotent function: f(f(x)) == f(x)

        struct A{
             std::unique_ptr<int> f(){
                ++a;
                return std::make_unique<int>(1);
            }
            int a{11};
        };

        if(A a, *a1{&a};a1 && a1->f() && *(a1->f()) == 1){
            printf("%d\n", a1->a);
        }
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