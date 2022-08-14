/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-08-13 19:12:45
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-08-15 00:37:43
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#pragma once



#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <string>
#include <ranges>

namespace STL{

    //using namespace std;

    auto func_999(){
        //advance(p,n) do n times ++p
        // distance(first, last) 
    }

    auto func_8(){


        std::pair<int, std::string_view> pairs[]{
            {4,"33"},
            {1,"22"},
            {-2,"11"},
            {-3,"00"},
        };
        std::ranges::sort(pairs, std::ranges::less{},[](const auto& p){return p.first * p.first;});//sort by projection, 16,1,4,9
        for( auto cur: pairs ){
            std::cout << cur.first << ", " << cur.second << std::endl;
        }/*1, 22       -2, 11      -3, 00      4, 33*/

        for( auto cur: pairs 
            |   std::views::filter([](const auto& p){return p.first !=2;})
            |   std::views::transform([](auto& p){p.first = p.first*p.first+100; return p;})
            |   std::views::take(2)
        ){
            std::cout << cur.first << ", " << cur.second << std::endl;
        }/*101, 22      104, 11 */
    }

    auto func_7(){

        auto lambdaTuple = [](const int iID){
            if(iID ==0){
                //return std::tuple<int, char, std::string>{1,'a',"aa"};
                return std::make_tuple(0,'a',"aa");//{int, char, const char*}
            }
            if(iID ==1){
                return std::make_tuple(1,'b',"bb");
            }
            if(iID ==2){
                return std::make_tuple(2,'c',"cc");
            }

            return std::make_tuple(0,'0',"00");
        };

        
        {
            auto val = lambdaTuple(0);
            auto v0 = std::get<0>(val);
            auto v1 = std::get<1>(val);
            auto v2 = std::get<2>(val);
            std::cout << v0 << ", " << v1 << ", " << v2 << "\n";//1, a, aa
        }

        {
            int v0{};
            char v1{};
            std::string v2{};
            std::tie(v0, v1, v2) = lambdaTuple(1);
            std::cout << v0 << ", " << v1 << ", " << v2 << "\n";//1, b, bb
        }

        {
            auto [v0,v1,v2] = lambdaTuple(2);
            std::cout << v0 << ", " << v1 << ", " << v2 << "\n";//2, c, cc
        }

        std::cout << std::get<int>(lambdaTuple(22)) << std::endl;//0
        std::cout << std::get<char>(lambdaTuple(22)) << std::endl;//0
        //std::cout << std::get<std::string>(lambdaTuple(22)) << std::endl;//error: static assertion failed: the type T in std::get<T> must occur exactly once in the tuple
        std::cout << std::get<const char*>(lambdaTuple(22)) << std::endl;//00

    }


    auto func_6(){
        std::unordered_map<int, char> hashTable{
            {1,'a'},
            {2,'b'},
            {3,'c'},
        };
        for(const auto& cur: hashTable){
            std::cout << cur.first << ", " << cur.second << std::endl;
        }
        /*
        3, c
        2, b
        1, a
        */


    }

    auto func_5(){//20220813 three ways to access std::array

        auto lLast = []<typename T>(T* ipHead, int iLength){
            return ipHead[--iLength];
        };
        std::array<int,4> arr{0,1,2,3};
        printf("%d\n", lLast(&arr[0], arr.size()));//3

        std::sort(arr.begin(), arr.end(), std::greater<int>());
        printf("%d\n", lLast(arr.data(), arr.size()));//0

    }


    
    auto func_4(){// vector
        {//initialization, 20210811
            int size = 6;
            std::vector<int> vecOut(size);
            for(const auto& cur:vecOut){
                std::cout << cur << std::endl;//six zeros
            }
            
            auto lambdaPrint = [&vecOut]{
                printf("capacity-size:%lu,%lu\n", vecOut.capacity(), vecOut.size());
            };

            lambdaPrint();//capacity-size:6,6

            vecOut.clear();
            lambdaPrint();//capacity-size:6,0

            vecOut.shrink_to_fit();
            lambdaPrint();//capacity-size:0,0
        }

        if(0)
        { // Test IO
            std::vector<std::vector<int>> matrix;
            int valX{}, valY{};

            while(std::cin>>valX >> valY){
                matrix.push_back({valX, valY});
            }

            for(auto vectorCur:matrix){
                std::cout << vectorCur[0] << "\t" << vectorCur[1] << std::endl;
            }
        }
    }


    template<typename T, typename InI, typename OutI>
    void func_3_Sort20210824(InI first, InI last, OutI result){
        std::vector<T> vecOri;
        for(;first!=last;++first)
            vecOri.push_back(*first);
        std::sort(vecOri.begin(), vecOri.end());
        std::copy(vecOri.begin(), vecOri.end(), result);
    }
    auto func_3(){

        double array[5] = {2,10,1,7,4};
        func_3_Sort20210824<double>(array, array+5, std::ostream_iterator<double>(std::cout, " "));
        std::cout << std::endl;

        func_3_Sort20210824<int>(std::istream_iterator<int>(std::cin),
        std::istream_iterator<int>(),
        std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;


    }



    auto func_2(){
        // input, until end(default is ctrl+z) IO20210824
        std::transform(std::istream_iterator<double>(std::cin), std::istream_iterator<double>(),
        std::ostream_iterator<double>(std::cout, "\t"), 
        [](const double& ival){return ival*ival;}
        );
    }

    auto func_1(){
        //Transform20210824
        std::vector<int> num{2,3,5,7,11};
        std::transform(num.begin(), num.end(), 
        std::ostream_iterator<int>(std::cout, " "), std::negate<int>());std::cout << std::endl;
    }

}
