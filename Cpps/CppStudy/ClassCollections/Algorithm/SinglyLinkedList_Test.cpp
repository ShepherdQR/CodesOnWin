/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-07-07 21:57:04
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-07-07 22:37:38
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include "SinglyLinkedList.h"
#include <stack>
#include <iostream>


namespace Algorithm::DataStructure
{
    using namespace std;

    void SinglyLinkedList::test(){
        puts("Test Basic.\n");

        if(20230701){ // algorithm_3_kthNumberBackward
            {
                std::cout << "\t\t=== test 1" << std::endl;
                SinglyLinkedList a({1, 2, 3, 4, 5});
                a.display();
                auto sz{a.size()};
                std::cout << sz << std::endl;
                for(const auto cur:{0,1,2,3,4,5,-1}){
                    auto result{SinglyLinkedList::algorithm_3_kthNumberBackward(a, cur)};
                    std::cout << result.value_or(20230707) << std::endl;
                } // 5,4,3,2,1,20230707,20230707
            }

            {
                std::cout << "\t\t=== test 2" << std::endl;
                for(const auto cur:{-1,0,1}){
                    auto result{SinglyLinkedList::algorithm_3_kthNumberBackward(
                        SinglyLinkedList{42}, cur)};
                    std::cout << result.value_or(20230707) << std::endl;
                }// 20230707, 42, 20230707
            }

            {
                std::cout << "\t\t=== test 4" << std::endl;
                for(const auto cur:{-1,0,1}){
                    auto result{SinglyLinkedList::algorithm_3_kthNumberBackward(
                        SinglyLinkedList{{}}, cur)};
                    std::cout << result.value_or(20230707) << std::endl;
                }// 20230707, 0, 20230707
            }

            {
                std::cout << "\t\t=== test 5" << std::endl;
                for(const auto cur:{-1,0,1}){
                    auto result{SinglyLinkedList::algorithm_3_kthNumberBackward(
                        SinglyLinkedList{vector<int>{}}, cur)};
                    std::cout << result.value_or(20230707) << std::endl;
                }// Empty 20230707, Empty 20230707,Empty 20230707,
            }
        }

        if(0){
            SinglyLinkedList a({1, 2, 3, 4, 5});
            a.display();
            a.reverse();
            a.display();
        }

        if(0){
            printf("Test Algorithm 01.\n");
            Algorithm::dumpVector(
                SinglyLinkedList::algorithm_1_IntersectionOf2List(
                    SinglyLinkedList({1, 2, 3, 4, 5}), SinglyLinkedList({0, 2, 3, 3, 5})));
        }

        if(0){
            printf("Test Algorithm 02_1.\n");
            std::cout << SinglyLinkedList::algorithm_2_JudgePalindrome_1(SinglyLinkedList{1, 2, 3, 4, 5}) << ", "
                << SinglyLinkedList::algorithm_2_JudgePalindrome_1(SinglyLinkedList{1, 2, 3, 9, 2, 1}) << ", "
                << SinglyLinkedList::algorithm_2_JudgePalindrome_1(SinglyLinkedList{1, 2, 3, 2, 1}) << std::endl; // 0,0,1

            printf("Test Algorithm 02_2.\n");

            SinglyLinkedList aA2_2_a({1, 2, 3, 4, 5});
            SinglyLinkedList aA2_2_b({1, 2, 3, 3, 2, 1});
            std::cout << SinglyLinkedList::algorithm_2_JudgePalindrome_2(aA2_2_a) << ", "
                << SinglyLinkedList::algorithm_2_JudgePalindrome_2(aA2_2_b) << ", "
                << SinglyLinkedList::algorithm_2_JudgePalindrome_2(SinglyLinkedList{1, 2, 3, 2, 1}) << std::endl; // 0,1,1
            aA2_2_a.display();
            aA2_2_b.display();
        }
    }
}