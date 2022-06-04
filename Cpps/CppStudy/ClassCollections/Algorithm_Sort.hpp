
#pragma once
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;

namespace Algorithm_Sort
{
    /**
     *          Time        Space       static
    select      O(N^2)      O(1)        N
    bubble      O(N^2)      O(1)        Y
    Inserction  O(N^2)      O(1)        Y
    Merge       O(NlogN)    O(N)        Y
    Fast        O(NlogN)    O(logN)     N
    Heap        O(NlogN)    O(1)        N
    1)基于比较的排序，时间上目前NlogN最小；要保持稳定space需要O(N)
    2）工程改进：a）综合排序，小样本用O(N^2)的，大样本用O(NlogN)；b）基础类型用快排，自定义类型用归并保证稳定性。
    */

    class Base{
    public:

        void test(const vector<int> ivec = {1,3,2,5,4}){
            cout << typeid(*this).name() << endl;
            display(solve(ivec));
        }

    protected:
        virtual vector<int> solve(const vector<int>& ivec){return ivec;};

        template<typename T>
        void _swap(T& a, T& b){
            T c = a;
            a = b;
            b = c;
        }

        void display(const vector<int>& ivec){
            for(auto cur:ivec){
                cout << cur << ", ";
            }cout << endl;
        }  

    };

    class Radix: public Base{
        vector<int> solve(const vector<int>& ivec){
            vector<int> ovec = ivec;
            if(ivec.size()<2)
            {
                return ovec;
            }

            int maxNum = ivec[0];
            for(int i=1;i<ivec.size();++i){
                if(maxNum<ivec[i]){
                    maxNum = ivec[i];
                }
            }

            const int radix = 10;
            int numberBucket(0);
            while(maxNum){
                maxNum /=radix;
                ++numberBucket;
            }//cout << "==" << numberBucket <<endl;

            vector<int> vecLoop = ovec;

            //遍历各个元素的个位、十位、百位...
            for(int i=0;i!=numberBucket;++i){

                vector<int> vecLoopLast(vecLoop.size(),0);
                vector<int> vecCount(radix,0);
                //从左到右统计落入各个桶的数量             
                for(int j=0;j!=vecLoop.size();++j){
                    vecLoopLast[j] = vecLoop[j]%radix;
                    vecCount[vecLoopLast[j]] +=1;
                    vecLoop[j]/=radix;
                }

                //将各个桶K的等于K的数量变成小于等于K的数量
                int sum(0);
                for(auto& cur: vecCount){
                    sum += cur;
                    cur = sum;
                }//display(vecCount);

                //从右向左，第j个元素的最低位的k时，将其移动到--vecCount[k]
                vector<int> vecBucketIndex(vecLoop.size(),0);
                for(int j=vecLoop.size()-1;j>=0;--j){
                    vecBucketIndex[--(vecCount[vecLoopLast[j]])] = j ;
                }

                //处理完一轮后，更新数组
                vector<int> outTemp1(vecLoop.size(),0);
                vector<int> outTemp2(vecLoop.size(),0);
                for(int i=0;i!=vecLoop.size();++i){
                    outTemp1[i] = vecLoop[vecBucketIndex[i]];
                    outTemp2[i] = ovec[vecBucketIndex[i]];
                }
                vecLoop = outTemp1;
                ovec = outTemp2;
                //display(ovec);
            }

            return ovec;
        }
    };


    class Quick: public Base{

        vector<int> solve(const vector<int>& ivec){
            vector<int> ovec = ivec;
            if(ivec.size()>1)
            {
                quick(ovec, 0, ovec.size()-1);
            }
            return ovec;
        }

        void quick(vector<int>& iovec, const int il, const int ir){
            if(il>=ir){
                return;
            }

            srand(time(0));
            int indexElem = rand()%(ir-ir+1)+il;
            swap(iovec[indexElem], iovec[ir]);

            auto [l, r] = partition(iovec, il, ir);
            quick(iovec, il,l-1);
            quick(iovec, r+1,ir);
        }

        std::pair<int, int> partition(vector<int>& iovec, const int il, const int ir){
            //分为 < = > 三个子数组，
            int number = iovec[ir];
            int ml = il;// 1st of =
            int mr = ir;// last of =

            for(int i= ml;i!=mr;++i){
                if(iovec[i] < number){
                    swap(iovec[ml++], iovec[i]);
                }
                else if(iovec[i]> number){
                    swap(iovec[mr--], iovec[i--]);
                }
                //display(iovec);
                //cout << i << ": " << ml << "--" << mr << endl;
            }
            return {ml,mr};
        }
    };



    class Insertion: public Base{
   
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

    };


    // 比较的信息，以整体有序的部分的形式保存，因而优于O(N^2)
    class Merge: public Base{

        vector<int> solve(const vector<int>& ivec){
            vector<int> ovec = ivec;
            if(ivec.size()>1)
            {
                _binary(ovec, 0, ovec.size()-1);
            }
            return ovec;
        }

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

        Radix().test({10,13,1,66,4,121});
        //Quick().test();
        //Merge().test();
        //Insertion().test();
    }




} // namespace Algorithm_Sort



