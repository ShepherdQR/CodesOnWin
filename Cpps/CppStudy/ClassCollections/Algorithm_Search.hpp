
#pragma once
#include <vector>
#include <iostream>
using namespace std;

namespace Algorithm_Search
{

    class Base{
    public:
        virtual void test() = 0;

    protected:
        template<typename T>
        void _swap(T& a, T& b){
            T c = a;
            a = b;
            b = c;
        }

    };




    class Binary: public Base{
    public:


        void test(){
            cout << searchMax({1,3,2,5,4}) << endl;
        }
    private:
        /* 
            T(N) = a * T(N/b) + O(N^d)
            // 参数为每次函数内部：a是子问题调用次数；b是子问题处理规模比例系数；d是除去递归其余的复杂度
            T(N) = 2 * T(N/2) + O(N^0)

            log_b(a) < d : O(N^k)
            log_b(a) > d : O(N^(log_b(a) ))
            log_b(a) = d : O(N^k * log(N))


        */
        //这个递归利用函数调用栈，实现了后序遍历
        int _searchMax(const vector<int>& ivec, const int l, const int r){
            if(l==r)
            {
                return ivec[l];
            }

            int mid = l + ((r-l) >>1);
            int maxL = _searchMax(ivec, l, mid);
            int maxR = _searchMax(ivec, mid+1, r);

            return max(maxL, maxR);
        }  

        int searchMax(const vector<int>& ivec){
            return _searchMax(ivec, 0, ivec.size()-1);
        }
    };

    auto test(){
        Binary().test();
    }




} // namespace Algorithm_Sort



