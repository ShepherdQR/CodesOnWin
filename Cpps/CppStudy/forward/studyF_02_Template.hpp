/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-07-19 21:40:02
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-08-16 21:51:41
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/



#pragma once

#include<iostream>
#include<type_traits>
#include<memory>
#include<vector>
#include<array>
#include<string>
#include<functional>
#include<algorithm>
#include<set>
#include<span>
#include<map>
#include<variant>






namespace Template{
    using namespace std;

    auto func_999(){

    }



    template<typename Key, typename Value, typename Compare>
    auto func_10_MakeMap(Compare x){
        return std::map<Key, Value, Compare>(x);
    }
    auto func_10(){
        ////20220624    make_map 可以被返回值优化掉。
        auto m = func_10_MakeMap<int, int>([](int x, int y){
            return x > y;
        });
        m[1] = 11; m[2] = 22; m[3] = 33;
        for (auto x : m) { 
            printf("%d->%d\n", x.first, x.second); 
        } // 2->22      \n      1->11
        
    }


    void func_9_T(){
        printf(".\n");
    }
    template<typename T, typename... Ts>
    void func_9_T(T t, Ts... ts){
        std::cout << t << "\t";
        return func_9_T(ts...);
    }
    auto func_9(){//20220624    Args... args
        func_9_T(1,"hi", true, std::string{"hello"});
    }

    auto func_8(){
        //20220624  simple template
        auto l = []<typename T>(T it){
            std::cout << it << std::endl;
        };
        l(1);
        l(std::string{"hi"});
    }

    

    template <size_t n, typename... T>
    constexpr std::variant<T...> func_7_tupleIndex_I(
        const std::tuple<T...> &tp1, size_t i){
        if constexpr (n >= sizeof...(T))
        {
            throw std::out_of_range("out of range.\n");
        }
        if (i == n)
        {
            return std::variant<T...>{
                std::in_place_index<n>, std::get<n>(tp1)};
        }
        return func_7_tupleIndex_I<
            (n < sizeof...(T) - 1 ? n + 1 : 0)>(tp1, i);
    }

    template<typename... T> 
    constexpr std::variant<T...> func_7_tupleIndex(
        const std::tuple<T...>& tp, size_t i
    ){
        return func_7_tupleIndex_I<0>(tp,i);
    }

    template<typename T0, typename... Ts> 
    std::ostream& operator<<(std::ostream & s,
        std::variant<T0, Ts...> const &v
    ){
        std::visit([&](auto&& x){s<< x;}, v);
        return s;
    }

    auto func_7(){// runtime index of std::tuple
        auto t{std::make_tuple(1,2,'a',true)};
        int i{2};
        std::cout << func_7_tupleIndex(t,i) << std::endl;

        auto t2{std::make_tuple(1,2,'a',true)};

        auto newT{std::tuple_cat(t, std::move(t2))};

        auto lambdaLength = []<typename T>(T& itp){
            return std::tuple_size<T>::value;
        };

        for(int i{0};i!=lambdaLength(newT);++i){
            std::cout << func_7_tupleIndex(newT,i) << std::endl;
        }






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


