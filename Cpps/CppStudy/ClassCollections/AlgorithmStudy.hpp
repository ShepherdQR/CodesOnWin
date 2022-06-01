/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-12-05 22:48:01
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2021-12-08 22:06:39
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#pragma once

#include <vector>
#include <iostream>
using namespace std;


auto algorithm002(){
    // 对数组中每个元素a，将a左边比a小的数加起来称为a的“小和”，求数组所有元素小和之和。
    // 问题可转化为每个元素a右侧有多少个比a大的数，有k个时，a需要累加k次。
    class A{
        int smallSum(const vector<int> ivec){
            int out(0);
            vector<int> ovec = ivec;
            if(ovec.size()>1)
            {
                out = _process(ovec, 0, ovec.size());
            }
            return out;
        }

        int _process(vector<int>& ivec, const int l, const int r){
            if(l == r){
                return 0;
            }

            int mid = l + ((r-l) >>1);
            return _process(ivec, l, mid)
            + _process(ivec, mid+1, r)
            + _merge(ivec, l, mid, r);
        }

        int _merge(vector<int>& ivec, const int l, const int mid, const int r){
            int out(0);
            vector<int> ovec;
            ovec.reserve(r-l+1);

            int pl(l);
            int pr(mid+1);

            while(pl<=mid && pr <= r){
                if(ivec[pl] < ivec[pr])
                {
                    ovec.emplace_back(ivec[pl]);
                    out += ivec[pl] * (r-pr+1);
                    ++pl;
                }
                else{
                    //[1,1,1,2] [1,1,3]，相等时先拷贝右组的数，保证右组pr指针右侧的数绝对比左侧pl指针指向的那个数大
                    ovec.emplace_back(ivec[pr++]);
                }
            }

            while(pl<=mid){
                ovec.emplace_back(ivec[pl++]);
            }

             while(pr<=r){
                ovec.emplace_back(ivec[pr++]);
            }

            for(int i=0;i<ovec.size();++i){
                ivec[l+i] = ovec[i];
            }
            return out;
        }


    public:
        auto test(){
            cout << smallSum({1,3,4,2,5}) << endl;//16
        }
    };

    A().test();

}


auto algorithm001(){
    // 数组中有2个数字出现奇数次，其余均出现偶数次，找出这2个奇数次的数
    struct A{
        A(vector<int> ivec){
            int eor(0);
            int onlyOne(0);
            for(const auto& cur:ivec){
                eor ^= cur;
            }

            int rightOne = eor&(~eor +1);//找到最右侧的1
            for(const auto& cur: ivec){
                if((cur & rightOne) == 0)// or ==1
                {
                    onlyOne ^= cur;
                }
            }
            cout << onlyOne <<", " << (eor^ onlyOne) << endl;
        }
    };

    A({1,1,2,2,3,3, 11,12,12,12,12, 20220601});
}





class Solution372 {
    const int MOD = 1337;

    int pow(int x, int n) {
        int res = 1;
        while (n) {
            if (n % 2) {
                res = (long) res * x % MOD;
            }
            x = (long) x * x % MOD;
            n /= 2;
        }
        return res;
    }

public:
    int superPow(int a, vector<int> &b) {
        int ans = 1;
        for (int e: b) {
            ans = (long) pow(ans, 10) * pow(a, e) % MOD;
        }
        return ans;
    }
};

class Solutionxxxx {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        vector<int> ans;
        int sum1 = 0, maxSum1 = 0, maxSum1Idx = 0;
        int sum2 = 0, maxSum12 = 0, maxSum12Idx1 = 0, maxSum12Idx2 = 0;
        int sum3 = 0, maxTotal = 0;
        for (int i = k * 2; i < nums.size(); ++i) {
            sum1 += nums[i - k * 2];
            sum2 += nums[i - k];
            sum3 += nums[i];
            if (i >= k * 3 - 1) {
                if (sum1 > maxSum1) {
                    maxSum1 = sum1;
                    maxSum1Idx = i - k * 3 + 1;
                }
                if (maxSum1 + sum2 > maxSum12) {
                    maxSum12 = maxSum1 + sum2;
                    maxSum12Idx1 = maxSum1Idx;
                    maxSum12Idx2 = i - k * 2 + 1;
                }
                if (maxSum12 + sum3 > maxTotal) {
                    maxTotal = maxSum12 + sum3;
                    ans = {maxSum12Idx1, maxSum12Idx2, i - k + 1};
                }
                sum1 -= nums[i - k * 3 + 1];
                sum2 -= nums[i - k * 2 + 1];
                sum3 -= nums[i - k + 1];
            }
        }
        return ans;
    }
};



class Solutionxxx {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        vector<int> output(3, -1);
        int size = nums.size();
        if(size < k*3)
            return output;


        int numberWindow = nums.size() - k + 1;


        vector<int> subArraySum(numberWindow, 0);

        int sumCurWindow = 0;
        for(int i = 0; i < size; i++){
            sumCurWindow += nums[i];

            if(i >= k)
                sumCurWindow -= nums[i - k];

            if(i >= k - 1)
                subArraySum[i - k + 1] = sumCurWindow;
        }

        vector<int> left(numberWindow, 0);
        int maxIndex = 0;
        for(int i = 0; i < numberWindow; i++){
            if(subArraySum[maxIndex] < subArraySum[i])
                maxIndex = i;
            left[i] = maxIndex;
        }



        vector<int> right(numberWindow, 0);
        maxIndex = numberWindow - 1;
        for(int i = numberWindow - 1; i >= 0; i--){
            if(subArraySum[maxIndex] <= subArraySum[i])
                maxIndex = i;
            right[i] = maxIndex;
        }

       
        for(int i = k; i < numberWindow - k; i++){
            if(output[0] == -1 || 
            subArraySum[output[0]] + subArraySum[output[1]] + subArraySum[output[2]] <
                subArraySum[i] + subArraySum[left[i - k]] + subArraySum[right[i + k]]){
                    output[0] = left[i - k];
                    output[1] = i;
                    output[2] = right[i + k];
                }

        }

        return output;
    }
};
