/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-07-10 22:08:32
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-07-13 00:23:39
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#pragma once

#include<iostream>
#include<memory>
#include<vector>
#include<array>
using namespace std;

//clang -std=c++2b
//151
namespace Basic{


    auto func_5(){
        auto l = []{};
        auto m = l;
        decltype(l) ddl;
        decltype([]{}) ddl2;

        // warning: 'fopen' is deprecated: This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
        // auto myDeleter = [](FILE*f){fclose(f);};
        // auto file=std::unique_ptr<FILE, decltype(myDeleter)>(
        //     fopen("TestTxt.txt", "w"), myDeleter
        // );

        // lambda has default constructor
        auto file=std::unique_ptr<FILE, decltype([](FILE*f){fclose(f);})>(
            fopen("TestTxt.txt", "w")
        );

    }

    auto func_4(){
        // why don't more standard library utilities use Auto return types, they say its not as good for spin a friendliness.

        auto l = [](const auto& p){ 
            std::cout << std::to_address(p) << "\n";
        };

        // heap: address big -> small; stack upwards
        if(auto sp = std::make_unique<int>(1)){
            l(sp);//0000023FDED9FFB0
            int x{2};
            l(&x);//000000411E8FFBA0
        }
        if(auto sp = std::make_unique<int>(2)){
            l(sp);//0000023FDED9FF10
            int x{3};
            l(&x);//000000411E8FFB88
        }

        std::vector<int> vec{1,2,3};
        l(vec.begin());//0000023FDED9E1B0
        l(vec.begin()+1);//0000023FDED9E1B4

    }


    auto func_3(){

        // we tested -O3, cannot be optimized to "mov eax,8"
        std::array data{1,2,3};
        auto total{0};
        for(std::size_t p = 0; const auto& c:data){
            total += (c*p++);
        }
        std::cout << total << std::endl;


        struct S{
            std::array<int, 4> data{1,2,3,4};
            const auto& get(){return data;}
        };
        auto getS =[]{return S{};};
        auto total_2{0};
        // here the nested calls may cause lifetime issures. But with clang c++2b, it works allright.
        for(std::size_t p = 0; const auto& c:getS().get()){
            total_2 += (c*p++);
        }
        std::cout << total_2 << std::endl;

        auto total_3{0};std::size_t p = 0;
        // However, only one ";" is supported in for
        for(auto s = getS();  const auto& c:s.get()){
        //for(auto s = getS(); std::size_t p = 0; const auto& c:s.get()){//error: expected expression
            total_3 += (c*p++);
        }
        std::cout << total_3 << std::endl;

    }


    
    auto func_2(){// template-like lambda
        auto l = []<typename T1, typename T2>(T1 t1, auto t2, 
        const std::vector<T2>& ivec){
            std::cout << t1 << " " << t2 << ivec.size() << "\n" << endl;
        };

        l(20220712, "hi", std::vector{1,2,3});
        //l(20220712, "hi", {1,2,3});//no matching function for call to object of type '(lambda  l )'

    }


    // struct S_func_1{
    //     static auto s_dd;//error: declaration of variable 's_dd' with deduced type 'auto' requires an initializer
    // };auto S_func_1::s_dd = 2*3;

    auto func_1(){//field designators

        struct S{
            //auto dd;//error: 'auto' not allowed in non-static struct member
            //static auto s_dd;//error: static data member 's_dd' not allowed in local struct 'S'
            int ii:3 = 0;
            unsigned int i;
            float j{};
            double d;
            //S():d(1.),i(2){}// The constructor disables the field designators
        };

        //S s1{i:1,d:3.2};//warning: use of GNU old-style field designator extension [-Wgnu-designator]
        S s2{.i=1,.j=2.};std::cout << s2.d << std::endl;
        
        S s3{.j = 2.};std::cout << s3.j << std::endl;
        S s4{.j = 2};std::cout << s4.j << std::endl;

        //S s4{.j = 3., .i=11};std::cout << s4.j << std::endl;//warning: ISO C++ requires field designators to be specified in declaration order;

        //S s5{.i=-1,.j=2.};std::cout << s5.d << std::endl;//error: constant expression evaluates to -1 which cannot be narrowed to type 'unsigned int'

        [](S is){
            cout << is.d << endl;
        }({.d = 5});

        auto s6 = S{
            .i = 6,
            //.i = 2222,//warning: initializer overrides prior initialization of this subobject
            .j = []{return 66;}()
        };std::cout << s6.i << ", " << s6.j <<  std::endl;
        
    }
}