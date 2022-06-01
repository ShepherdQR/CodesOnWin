
#pragma once
#include <vector>
#include <iostream>
using namespace std;

namespace Algorithm_Sort
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


    class Insertion: public Base{
    public:
        vector<int> solve(const vector<int>& ivec){
            vector<int> ovec = ivec;
            if(ivec.size()<2)
            {
                return ovec;
            }

            auto lambdaSwap = [](int& a, int&b){
                if(&a != &b){
                    a = a^b;
                    b = a^b;
                    a = a^b;
                }
            };

            for(int i = 1;i<ovec.size();++i){
                for(int j = i-1; j>=0 && ovec[j]> ovec[j+1];--j){
                    _swap(ovec[j], ovec[j+1]);
                    //lambdaSwap(ovec[j], ovec[j+1]);
                }
            }
            return ovec;
        }

        void test(){
            for(auto cur: solve({1,3,2,5,4})){
                cout << cur << ", ";
            }cout << endl;
        }
    };

    // 比较的信息，以整体有序的部分的形式保存，因而优于O(N^2)
    class Merge: public Base{
    public:
        vector<int> solve(const vector<int>& ivec){
            vector<int> ovec = ivec;
            if(ivec.size()>1)
            {
                _binary(ovec, 0, ovec.size()-1);
            }
            return ovec;
        }

        void test(){
            cout << typeid(*this).name() << endl;
            for(auto cur: solve({1,3,2,5,4})){
                cout << cur << ", ";
            }cout << endl;
        }

    private:
        // T(N) = 2* T(N/2) + O(N), so O(N*logN)
        void _binary(vector<int>& ivec, const int l, const int r){
            if(l==r)
            {
                return ;
            }

            int mid = l + ((r-l) >>1);
            _binary(ivec, l, mid);
            _binary(ivec, mid+1, r);
            _merge(ivec, l, mid, r);
        }
        void _merge(vector<int>& ivec, const int l, const int mid, const int r){
            vector<int> vecTemp;
            vecTemp.reserve(r-l+1);

            int indexO(0);
            int indexL(l);
            int indexR(mid+1);
            while( (indexL<=mid) && (indexR <=r)){
                if(ivec[indexL]<=ivec[indexR])
                {
                    vecTemp.emplace_back(ivec[indexL++]);
                }
                else
                {
                    vecTemp.emplace_back(ivec[indexR++]);
                }

                //vecTemp.emplace_back(ivec[indexL]<=ivec[indexR]? ivec[indexL++]:ivec[indexR++]);
            }

            while(indexL<=mid){
                vecTemp.emplace_back(ivec[indexL++]);
            }

            while(indexR<=r){
                vecTemp.emplace_back(ivec[indexR++]);
            }

            for(int i=0;i<vecTemp.size();++i){
                //cout <<  vecTemp[i] << "..";
                ivec[l+i] = vecTemp[i];
            }
            //cout << endl;

        }
    };






    auto test(){

        Merge().test();
        //Insertion().test();
    }




} // namespace Algorithm_Sort



