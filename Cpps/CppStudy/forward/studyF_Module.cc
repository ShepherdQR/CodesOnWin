/*
 * @Author: Shepherd Qirong
 * @Date: 2022-08-13 20:07:27
 * @Github: https://github.com/ShepherdQR
 * @LastEditors: Shepherd Qirong
 * @LastEditTime: 2022-09-28 21:20:29
 * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
 */



export module studyF_Module;


import <iostream>;

namespace Module{
    export auto func_1(){std::cout << 1 << std::endl;}
    export void func_2();
}

export class A{
public:
    static void f(const int i){printf("hello world%d\n",i);}
};
