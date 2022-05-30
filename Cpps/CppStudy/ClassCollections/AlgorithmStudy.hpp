/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-12-05 22:48:01
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2021-12-08 22:06:39
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/



#include <vector>
using namespace std;

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
