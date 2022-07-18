/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-06-24 23:16:39
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-07-18 21:56:31
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/





#pragma once

#include <vector>
#include <ctime>
#include <functional>
#include <numeric>
using namespace std;
//#include <thread>
//#include <tuple>


namespace EBO{
    template<typename R, typename F, typename G>
    class composed_fg
    {
    public:
        composed_fg(const F& f, const G& g)
        : f(f)
        , g(g)
        {}

        template<typename T>
        R operator ()(const T& t) const
        {
            return f(g(t));
        }
    private:
        F f;
        G g;
    };

    //结构选择，将类结构的可变部分放入公共基类或基类目标并使用一个元程序在它们之间选择

     
#include <type_traits>
 
using namespace std;
 
template<typename F, bool F_empty, typename G, bool G_empty>
struct storage;
 
template<typename F, typename G>
struct storage<F, false, G, false>
{
    storage(F const& f, G const& g) : f_(f), g_(g) {}
    F const& f() { return f_; }
    G const& g() { return g_; }
private:
    F f_;
    G g_;
};
 
template<typename F, typename G>
struct storage<F, false, G, true> : private G
{
    storage(F const& f, G const& g) : G(g), f_(f) {}
    F const& f() { return f_; }
    G const& g() { return *this; }
private:
    F f_;
};
 
template<typename F, typename G>
struct storage<F, true, G, true> : private F, private G
{
    storage(F const& f, G const& g) : F(f), G(g) {}
    F const& f() { return *this; }
    G const& g() { return *this; }
};
 
template<typename F, typename G>
struct storage<F, true, G, false> : private F
{
    storage(F const& f, G const& g) : F(f), g_(g) {}
    F const& f() { return *this; }
    G const& g() { return g_; }
 
private:
    G g_;
};
 
template<typename R, typename F, typename G>
struct compose_fg : storage<F, is_empty<F>::value, G, is_empty<G>::value>
{
    using base = storage<F, is_empty<F>::value, G, is_empty<G>::value>;
    compose_fg(F const& f, G const& g) : base(f, g)
    {
 
    }
 
    template<typename T>
    R operator()(T const& x) const
    {
        F const& f_ = this->f();
        G const& g_ = this->g();
 
        return f_(g_(x));
    }
};
}

namespace case0002_ThreeSelection{
    // case0002_ThreeSelection::funcRefactoring20210614()
    // [T00002] Refactor. Using array of pointers. //[good]
    void funcRun(void*)
    {
        std::cout << "Game Starts..." << std::endl;
    }
    void funcEnd(void*)
    {
        std::cout << "Game Ends..." << std::endl;
    }
    void funcIn(void*)
    {
        const char *pStrChoices[4] =
            {"Game Starts.", "Game Ends.", "Invalid Number, try again."};
        void(*pFunc[3])(void*) = {funcRun, funcEnd, funcIn};
        char input(0);

        if (std::cin >> input){
            input = ((input >= 48) && (input <= 50)) ? input - 48 : 2;
            std::cout << "Your choice: " << pStrChoices[input] << std::endl;
            (*pFunc[input])(nullptr);
        }
    }
    void funcRefactoring20210614()
    {
        funcIn(nullptr);
    }
}






// [T00001] Refactor. Finding the missing number.
auto case0001_FindTheMissingNumber()
{
    // shuffering random; find the missing number.
    int numSize = 100;
    std::vector<int> vecNum;
    for(int i = 0; i<numSize; ++i)
        vecNum.push_back(i);
    vecNum[11] = 0;

    srand(time(0));
    for(int i = 0; i < numSize; ++i)
        swap(vecNum[ i + rand()%(numSize-i) ], vecNum[i]);

    for(int i = 0; i<numSize; ++i)
            std::cout << vecNum[i] << "\t";

    std::cout << "\nThe missing number is: " << [](std::vector<int>* ipVec){
        return (ipVec->size()-1)*ipVec->size()/2 - accumulate(ipVec->begin(),ipVec->end(),0); 
        }(&vecNum)  << std::endl;
}
