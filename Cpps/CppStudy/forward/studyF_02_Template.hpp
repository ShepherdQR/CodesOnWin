/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-07-19 21:40:02
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-07-23 22:57:55
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/



#pragma once

#include<iostream>
#include<type_traits>
#include<memory>
#include<vector>
#include<array>
#include<string>
#include <functional>
#include <algorithm>
#include<set>
#include<span>
#include<map>






namespace Template{
    using namespace std;

    auto func_999(){

    }

    auto func_6(){
        std::map<std::string, long long int> m{
            {"a", 1},
            {"b", 2},
            {"c", 3},
        };

        auto l = []<typename Key, typename Value, typename F>
        (std::map<Key, Value>& m, F foo){
            for(auto&&[key, value]: m){
                value = foo(key);
            }
        };
        l(m, [](std::string key){
            return std::hash<std::string>{}(key);
        });
        for(auto&&[key, value]: m){
            std::cout << key << ", " << value << std::endl;
        }
    }



    // cout << enum_class_member << endl
    template<typename T>
    std::ostream& operator<<(
        typename std::enable_if<std::is_enum<T>::value,
        std::ostream>::type& stream, const T& e)
    {
        return stream << static_cast<typename std::underlying_type<T>::type>(e);
    }
    auto func_5(){
        enum class A{
        aa = 1};
        cout << A::aa << endl;
    }
  


    template<typename T, int BufSize>
    struct A_f4{
        T _[BufSize]{};
    };
    auto func_4(){
        A_f4<char, 10> buf{"123456789"};
        for(std::span s{buf._}; const auto& cur:s){
            puts(&cur);
        }puts("-");
    }
    /* ===========
        Hi<
        123456789
        23456789
        3456789
        456789
        56789
        6789
        789
        89
        9

        -
        >Bye.    
    */

    template<auto V> auto func_3_1(){
        std::cout << V << std::endl;
    }
    auto func_3(){
        func_3_1<10>();
    }


    template<typename T>
    auto func_1_1(T t){// t works well on lambda and function
        return t();
    }
    int func_1_1a();
    int func_1_1b(){return 1;}


    template<typename T>
    auto func_1_2(T t)
    requires requires{&T::operator();}
    {// t works on lambda, but not on function
        return t();
    }

    template<typename T> concept C_has_call_operator = requires{
        &T::operator();
    };

    template<typename T>
    auto func_1_3(T t)
    requires C_has_call_operator<T>
    {// t works on lambda, but not on function
        return t();
    }    

    auto func_1(){
        func_1_1([]{});
        //func_1_1(func_1_1a);//undefined reference to `Template::func_1_2()'
        func_1_1(func_1_1b);

        func_1_2([]{});
        //func_1_2(func_1_1b);//error: no matching function for call to ‘func_1_2(int (&)())’

        func_1_3([]{});
        //func_1_3(func_1_1b);//error: no matching function for call to ‘func_1_3(int (&)())’

    }

}



namespace template_Variadic{
    using namespace std;

    
    template<typename... Ts> class func_2_A1;
    class func_2_A1<int, std::vector<double> >;


    // 1. recursive template
    template<typename T>
    void func_2_f1(T t){
        cout << t << " " << std::endl;
    }
    template<typename T, typename... Ts>
    void func_2_f1(T t, Ts... args){
        cout << t;
        func_2_f1(args...);
    }

    // 2. variable parameter template
    template<typename T, typename... Ts>
    void func_2_f2(T t, Ts... args){
        cout << t;
        if constexpr (sizeof...(args)>0){
            func_2_f2(args...);
        }
    }

    // 3. Initialize list expansion
    template<typename T, typename... Ts>
    auto func_2_f3(T value, Ts... args) {
        std::cout << value;
        (void) std::initializer_list<T>{([&args] {
            std::cout << args;
        }(), value)...};
    }

    // // parameter pack expansion
    // template<typename C, typename... Args>
    // auto bind_v(C ic, Args... args){
    //     //return [=](){
    //     return [_ic = std::move(ic), ..._args = std::move(args)](){
    //         return _ic(_args...);
    //     };
    // }
    // parameter pack expansion
 
    // 5. Initialize list expansion
    template<typename ... T>
    auto func_2_f5(T ... t) {
        return (t + ...);
    }   
    
    
    auto func_2_(){
        func_2_f1(1," hi.\n");
        func_2_f2(2," hi.\n");
        func_2_f3(3," hi.\n");

        auto f4 = []<typename T, typename... Ts>
        (auto&& me, T t, Ts... args){
            cout << t;
            if constexpr (sizeof...(args)>0){
                me(me, args...);
            }
        };
        f4(f4, 4," hi.\n");

        cout << func_2_f5(1,2,3) << endl;
        cout << 
        []<typename... A>(A... args){
            return (args + ...);
        }(1,2,3) << endl;
        

    }


}


