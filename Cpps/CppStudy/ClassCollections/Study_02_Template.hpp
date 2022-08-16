/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-06-24 23:37:40
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-08-16 21:53:10
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
_Pragma("once");

#include <numeric>
#include <vector>
#include <ctime>
#include <thread>
#include <functional>
#include <tuple>

using namespace std;


namespace study20220626{

    int val20220626 = 20220626;
    template<typename T>
    class A1:public T{public:
        void f(){cout << val20220626 << endl;}//这里变量是一个非待决名，不依赖于T
        void g(){cout << this->val20220626 << endl;}
    };

    class B1{public: int val20220626 = 1;};
    class C1{};

    auto func_3(){
        A1<B1>().f();//20220626
        A1<C1>().f();//20220626
        A1<B1>().g();//1
        //A1<C1>().g();//error: 'class study20220626::A1<study20220626::C1>' has no member named 'val20220626'
    }




    struct A{
        template <class T> class x{};
        using y=int;
    };
    struct B{ static int x,y;};
    int B::x = 1, B::y = 2;

    template<typename T>
    auto func_2_WhatIsTheTypeOfZ_v1(){
        int z = 0;
        {
            T::x<T::y> z;
            cout << typeid(z).name() << endl;
        }
    }

    auto func_2(){
        {
            typedef A T;
            int z = 0;
            { 
                T::x<T::y> z;
                cout << typeid(z).name() << endl;//N13study202206261A1xIiEE
            }
        }
        {
            typedef B T;
            int z = 0;
            { 
                T::x<T::y> z;
                cout << typeid(z).name() << endl;//i
            }
        }

        //这里，模板函数已经将T::x<T::y> z; 确定为是 m < n > z的形式了
        //func_2_WhatIsTheTypeOfZ_v1<A>();
        //error: dependent-name 'T:: x' is parsed as a non-type, but instantiation yields a type
        //error: dependent-name 'T:: y' is parsed as a non-type, but instantiation yields a type

        func_2_WhatIsTheTypeOfZ_v1<B>();//i


    }
}


// [T0004] constexpr
template<typename T>
auto displayTypeInformation(const T& iVal){
    if constexpr(std::is_integral<T>::value){
        return iVal+1;
    }else if constexpr(std::is_null_pointer<T>::value){
        static int cur(0);
        return &cur;
    }else{
        return iVal+0.04;
    }
}
constexpr int fibonacci(const int n){
    if(n==1 || n == 2){
        return 1;
    }
    return fibonacci(n-1)+ fibonacci(n-2);
}
auto func20220604_2(){
    cout << fibonacci(5) << endl;

    cout << displayTypeInformation(5)<< endl;
    cout << *displayTypeInformation(nullptr)<< endl;
    cout << displayTypeInformation(3.1)<< endl;
}


