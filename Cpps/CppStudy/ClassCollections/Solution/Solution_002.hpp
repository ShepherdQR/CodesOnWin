/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2023-10-25 20:59:09
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2024-06-15 14:45:46
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#pragma once

#include <vector>
#include <unordered_set>

namespace Solution{

    using namespace std;

class Solution_20231105 {
    /**
    
    读入字符串并丢弃无用的前导空格
    检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
    读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
    将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
    如果整数数超过 32 位有符号整数范围 [−2^31,  2^31 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −2^31 的整数应该被固定为 −2^31 ，大于 2^31 − 1 的整数应该被固定为 2^31 − 1 。
    返回整数作为最终结果。
    */
    /*
    执行结果：
            通过
            显示详情
            查看示例代码
            执行用时：
            0 ms
            , 在所有 C++ 提交中击败了
            100.00%
            的用户
            内存消耗：
            6.6 MB
            , 在所有 C++ 提交中击败了
            23.90%
            的用户
            通过测试用例：
            1088 / 1088
    */
public:
    int myAtoi(string s) {
        auto indexMax{10};
        int indexCur{0};
        int out{0};
        [[maybe_unused]]bool flagAlready{false};
        bool flagSign{true};
        const int max1 = 2147483647;
        const int max11 = 214748364;
                        //2147483640 + 8
                       //"21474836460"
                          //-912834724
                          // "00000-42a1234" => 0
                          // "   +0 123" => 0
                          // "-2147483648"
        bool overflow{false};
        //bool overflowAlmost{false};
        int collectLevel{0};
        for( const auto& cur:s){
            if(cur == ' ' && collectLevel == 0) {
                continue;
            }

            if(cur == '+'){
                ++collectLevel;
                if(collectLevel == 1) {
                // if(!flagAlready) {
                    flagSign = true;
                    flagAlready = true;
                } else{
                    break;
                }
            } else if(cur == '-'){
                ++collectLevel;
                if(collectLevel == 1) {
                //if(!flagAlready) {
                    flagSign = false;
                    flagAlready = true;
                } else{
                    break;
                }
            } else{
                int vCur = int(cur - '0');
                if((vCur >= 0) && (vCur <= 9)){
                    //std::cout << vCur << std::endl;

                    if(out == max11){
                        //std::cout << "Overflow: " << int(!flagSign) << std::endl;
                        //std::cout << "Overflow: " << vCur;
                        if(vCur >= (7 + int(!flagSign))){
                            overflow = true;
                            break;
                        }
                    }
                    collectLevel = 2;

                    if(vCur == 0 && out == 0){
                    }else{
                        ++indexCur;
                    }
                    if(indexCur > indexMax){
                        overflow = true;
                        //puts("eee1\n");
                        break;
                    }

                    if(out > max11){
                        overflow = true;
                        //puts("eee2\n");
                        break;
                    }

                    long long outCur = out * 10 + vCur;
                    //std::cout << "xxxxxx: " << outCur;

                    long long mm = max1;
                    if(!flagSign){
                        ++mm;
                    }

                    if(outCur > mm){
                        //puts("eee3\n");
                        break;
                    } else{
                        out = outCur;
                    }
                } else{
                    break;
                }
            }
        }
        if(overflow){
            return flagSign? max1 : -1 * max1-1;
        }
        return flagSign? out : -1 * out;
    }
};

    void testSolution(){
        std::cout << "hi20231105" << std::endl;

        std::cout <<  Solution_20231105().myAtoi({"-2147483648"}) << std::endl;
        
       
    }


class Solution_128{
public:
    int longestConsecutive_V2(vector<int>& nums) {
        /*
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res = 0
        hash_dict = dict()
        for num in nums:
            # 新进来哈希表一个数
            if num not in hash_dict:
                # 获取当前数的最左边连续长度,没有的话就更新为0
                left = hash_dict.get(num-1,0)
                # 同理获取右边的数
                right = hash_dict.get(num+1,0)
                """不用担心左边和右边没有的情况
                因为没有的话就是left或者right0
                并不改变什么
                """
                # 把当前数加入哈希表，代表当前数字出现过
                hash_dict[num] = 1
                # 更新长度
                length = left+1+right
                res = max(res,length)
                # 更新最左端点的值，如果left=n存在，那么证明当前数的前n个都存在哈希表中
                hash_dict[num-left] = length
                # 更新最右端点的值，如果right=n存在，那么证明当前数的后n个都存在哈希表中
                hash_dict[num+right] = length
                # 此时 【num-left，num-right】范围的值都连续存在哈希表中了
                # 即使left或者right=0都不影响结果
        return res

        */
        return {};
    }

    int longestConsecutive(vector<int>& nums) {
        int out{};

        unordered_set<int> setVal;
        for(const auto& cur: nums){
            setVal.insert(cur);
        }

        for(const auto& cur: setVal){
            if(!setVal.count(cur-1)){
                auto curValue = cur;
                auto curS = 1;

                while(setVal.count(curValue +1)){
                    ++curValue;
                    ++curS;
                }
                out = max(out, curS);
            }
        }

        return out;
    }
};

}
