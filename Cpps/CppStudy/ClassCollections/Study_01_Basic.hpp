/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-06-26 20:57:45
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-06-29 21:26:11
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


#pragma once


using namespace std;


namespace study20220626{

    auto func_5(){
        const char* s = "hi";//c++ const char[3]
        //char *s = "hi";//c char[3]
    }

    auto func_4(){
        size_t a = 10, *pA = nullptr;
        cout << sizeof (int) * a << endl;//40, 这里对于sizeof特殊规定右侧的表达式不默认使用强制类型转换，要想强制类型转换需要加括号
        cout << sizeof ((int) * pA) << endl;//4

        long long b1=1, b2 = 2, *pB3 = nullptr;
        cout << sizeof b1 << endl;//8
        cout << sizeof ((int) b2 )<< endl;//4
        cout << sizeof *pB3 << endl;//8
        //cout << sizeof (int) *pB3 << endl;//error: invalid operands of types 'long long unsigned int' and 'long long int*' to binary 'operator*'
        cout << sizeof ((int) *pB3) << endl;//4

        int c = 100, *pC = nullptr;
        cout << (sizeof (int)) *c << endl;//400
        //cout << (sizeof (int)) *pC << endl;//invalid operands of types 'long long unsigned int' and 'int*' to binary 'operator*'

    }

    auto func_1(){

        class A{public:
            virtual void final(int override)=0;
        };

        class B final: public A{public:
            virtual void final(int override)final override{
                cout << "oo " << override << endl;
            }
        };

        class C final{
        };

        if(auto upB = make_unique<B>()) {
            upB->final(1);
        }
    }

}
