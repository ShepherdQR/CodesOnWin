
// #pragma once
_Pragma("once");

#include <iostream>
#include <functional>
#include <memory>

namespace Basic{


    auto func_999_Mark3(){


    }

    auto func_63(){
        // 1. display information in compile time
        // #error "hi"
        // static_assert(false, "hi");

        // #error "hi"
        std::cout << sizeof (unsigned int) << std::endl; // 4
        std::cout << sizeof 4 << std::endl; // 4
        // static_assert(true, "hi"); // no output
        // static_assert(sizeof (unsigned int) != sizeof 4, "hi");

        // 2. final disables the rePureVirtual in the derived classes.
        class A{
            virtual void f() = 0;
            virtual void g() = 0;
        };

        class B:A{
            virtual void f() final;
            virtual void g(){};
        };

        class C:B{
            // virtual void f() = 0; // error: declaration of 'f' overrides a 'final' function
            virtual void g() = 0;
        };


    }



    auto func_62(){
        // long long, more than 64 bit

        unsigned long long l1 = ULLONG_MAX;//18446744073709551615
        long long l2 = LLONG_MAX; //9223372036854775807 

        printf("%llu\n", l1);
        printf("%lld\n", l2);


    }


    auto func_61_1()->const char*{
        std::cout << __func__ << std::endl; // func_61_1
        return __func__;
    }
    auto func_61(){

        auto l = []{
            return __func__;
        };

        std::cout << l() << std::endl; // operator()
        std::cout << func_61_1() << std::endl; //func_61_1
    }

    auto func_60(){

        struct A{
            int i{0};
            int j{11};
        };

        [[maybe_unused]]A a{0,2}, b{.j=2};
        std::cout << b.i << std::endl;
    }

    auto func_59(){ // 20230211
        // study20220626
        {   // 1. sizeof
            using namespace std;
            size_t a = 10, *pA = nullptr;
            cout << sizeof (int) * a << endl;//40, 这里对于sizeof特殊规定右侧的表达式不默认使用强制类型转换，要想强制类型转换需要加括号
            cout << sizeof ((int) * pA) << endl;//4

            long long b1=1, b2 = 2, *pB3 = nullptr;
            cout << sizeof b1 << endl;//8
            cout << sizeof ((int) b2 )<< endl;//4
            cout << sizeof *pB3 << endl;//8
            //cout << sizeof (int) *pB3 << endl;//error: invalid operands of types 'long long unsigned int' and 'long long int*' to binary 'operator*'
            cout << sizeof ((int) *pB3) << endl;//4

            [[maybe_unused]]int c = 100, *pC = nullptr;
            cout << (sizeof (int)) *c << endl;//400
            //cout << (sizeof (int)) *pC << endl;//invalid operands of types 'long long unsigned int' and 'int*' to binary 'operator*'
        }

        {   // 2. type of litral
            [[maybe_unused]]const char* s = "hi";//c++ const char[3]
            //char *s = "hi";//c char[3]
        }

        {   // 3. final, override can be used as the name of variable
            struct A{
                virtual void final(int override)=0;
            };

            struct B final : A{
                virtual void final(int override)final override{
                    std::cout << "oo " << override << std::endl;
                }
            };

            class C final{};

            if(auto upB = std::make_unique<B>()){
                upB->final(1); // oo 1
            }
        }



    }

    namespace namespace_func_58{
        //  study20220626
        int val20220626 = 20220626;
        template<typename T>
        class A1:T{
        public:
            void f(){std::cout << val20220626 << std::endl;}//这里变量是一个非待决名，不依赖于T
            void g(){std::cout << this->val20220626 << std::endl;}
        };

        auto test_func_58(){
            struct B1{int val20220626 = 1;};
            struct C1{};

            A1<B1>().f();//20220626
            A1<C1>().f();//20220626
            A1<B1>().g();//1
            //A1<C1>().g();//error: 'class study20220626::A1<study20220626::C1>' has no member named 'val20220626'
        }
    }
    auto func_58(){
        namespace_func_58::test_func_58();
    }

    namespace namespace_func_57{
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
                //T::x<T::y> z; // here is: a < b > c
                std::cout << typeid(z).name() << std::endl;
            }
        }

        auto test_func_57(){
            {
                typedef A T;
                [[maybe_unused]]int z = 0;
                { 
                    T::x<T::y> z;
                    std::cout << typeid(z).name() << std::endl;//N5Basic17namespace_func_571A1xIiEE
                }
            }
            {
                [[maybe_unused]]typedef B T;
                int z = 0;
                { 
                    // here is: a < b > c
                    //T::x<T::y> z; // warning: comparisons like ‘X<=Y<=Z’ do not have their mathematical meaning [-Wparentheses]

                    std::cout << typeid(z).name() << std::endl;//i
                }
            }

            //这里，模板函数已经将T::x<T::y> z; 确定为是 m < n > z的形式了
            // func_2_WhatIsTheTypeOfZ_v1<A>();
            //error: dependent-name 'T:: x' is parsed as a non-type, but instantiation yields a type
            //error: dependent-name 'T:: y' is parsed as a non-type, but instantiation yields a type

            func_2_WhatIsTheTypeOfZ_v1<B>();//i

        }
    }
    auto func_57(){
        namespace_func_57::test_func_57();
    }


    namespace namespace_func_56{
        // [T0004] constexpr func20220604_2
        template<typename T>
        auto displayTypeInformation1(const T& iVal){
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
    }

    auto func_56(){

        // constexpr std::function<int(const int)> lambdaFibonacci // error
        std::function<int(const int)> lambdaFibonacci = [&](const int n){
            if(n==1 || n == 2){
                return 1;
            }
            return lambdaFibonacci(n-1)+ lambdaFibonacci(n-2);
        };
        std::cout << lambdaFibonacci(5) << std::endl;// 1 1 2 3 5

        constexpr auto displayTypeInformation = []<typename T>(const T& iVal){
            if constexpr(std::is_integral<T>::value){
                return iVal+1;
            }else if constexpr(std::is_null_pointer<T>::value){
                static int cur(0);
                return &cur;
            }else{
                return iVal+0.04;
            }
        };

        std::cout << displayTypeInformation(5)<< std::endl;
        std::cout << *displayTypeInformation(nullptr)<< std::endl;
        std::cout << displayTypeInformation(3.1)<< std::endl;

    }
}
