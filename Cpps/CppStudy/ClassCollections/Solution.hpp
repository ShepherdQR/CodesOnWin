/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-10-23 00:37:39
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-10-23 01:00:35
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


namespace LeetCode
{

    struct Solution_15
    {
        vector<vector<int>> threeSum(vector<int> &nums)
        {
            if(0)
            {
                vector<vector<int>> out;

                std::set<int> mySet;
                for (auto &val : nums)
                {
                    mySet.insert(val);
                }

                int sz = mySet.size();
                if (sz < 3)
                {
                    return out;
                }

                vector<int> v;
                v.reserve(mySet.size());

                std::map<int, int> map;
                int index{0};
                for (auto it = mySet.begin(); it != mySet.end(); ++it)
                {
                    v.emplace_back(*it);
                    map.insert({*it, index++});
                    cout << *it << endl;
                }

                for (int i = 0; i != sz; ++i)
                {
                    for (int j = i + 1; j != sz && j != i; ++j)
                    {
                        int k = -v[i] - v[j];
                        if (map.find(k) != map.end() && map[k] > i && map[k] > j)
                        {
                            out.emplace_back(std::vector<int>{v[i], v[j], k});
                        }
                    }
                }

                return out;
            }

            std::vector<std::vector<int>> out{};

            vector<int> vec {nums};
            std::sort(vec.begin(), vec.end());

            int sz = vec.size();
            if(sz<3){
                return out;
            }

            int p0{vec[0]+1};

            for(int i=0; i<sz-2; ++i){
                if(vec[i] == p0){continue;}

                int p1{vec[i+1]+1};
                for(int j=i+1; j<sz-1; ++j){
                    if(vec[j] == p1){continue;}


                    int p2{vec[j+1]+1};
                    for(int k=j+1; k<sz; ++k){
                        if(vec[k] == p2){continue;}

                        if(vec[i]+vec[j]+vec[k] == 0){
                            out.emplace_back(std::vector<int>{vec[i], vec[j], vec[k]});
                        }

                        p2=vec[k];
                    }


                     p1=vec[j];
                }
                p0=vec[i];
            }


            return out;



        }
    };

}
