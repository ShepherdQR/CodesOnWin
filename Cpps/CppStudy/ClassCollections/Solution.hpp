/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-10-23 00:37:39
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-02-11 23:03:05
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


namespace LeetCode
{
    inline namespace Solution_2335{ //20230211
        /* =============装满杯子需要的最短总时长
            现有一台饮水机，可以制备冷水、温水和热水。每秒钟，可以装满 2 杯 不同 类型的水或者 1 杯任意类型的水。

            给你一个下标从 0 开始、长度为 3 的整数数组 amount ，其中 amount[0]、amount[1] 和 amount[2] 分别表示需要装满冷水、温水和热水的杯子数量。返回装满所有杯子所需的 最少 秒数。

             

            示例 1：

            输入：amount = [1,4,2]
            输出：4
            解释：下面给出一种方案：
            第 1 秒：装满一杯冷水和一杯温水。
            第 2 秒：装满一杯温水和一杯热水。
            第 3 秒：装满一杯温水和一杯热水。
            第 4 秒：装满一杯温水。
            可以证明最少需要 4 秒才能装满所有杯子。
            示例 2：

            输入：amount = [5,4,4]
            输出：7
            解释：下面给出一种方案：
            第 1 秒：装满一杯冷水和一杯热水。
            第 2 秒：装满一杯冷水和一杯温水。
            第 3 秒：装满一杯冷水和一杯温水。
            第 4 秒：装满一杯温水和一杯热水。
            第 5 秒：装满一杯冷水和一杯热水。
            第 6 秒：装满一杯冷水和一杯温水。
            第 7 秒：装满一杯热水。
            示例 3：

            输入：amount = [5,0,0]
            输出：5
            解释：每秒装满一杯冷水。
             

            提示：

            amount.length == 3
            0 <= amount[i] <= 100

            来源：力扣（LeetCode）
            链接：https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups
            著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
        */
        class Solution {
        public:
            int fillCups(vector<int>& amount) {
                sort(amount.begin(), amount.end());
                int out{amount[0]+amount[1]-amount[2]};
                return  (out>0)?(out+1)/2 + amount[2]:amount[2];
                
            }
        };
    }

    inline namespace Solution_1233{
        /*
            你是一位系统管理员，手里有一份文件夹列表 folder，你的任务是要删除该列表中的所有 子文件夹，并以 任意顺序 返回剩下的文件夹。

            如果文件夹 folder[i] 位于另一个文件夹 folder[j] 下，那么 folder[i] 就是 folder[j] 的 子文件夹 。

            文件夹的「路径」是由一个或多个按以下格式串联形成的字符串：'/' 后跟一个或者多个小写英文字母。

            例如，"/leetcode" 和 "/leetcode/problems" 都是有效的路径，而空字符串和 "/" 不是。
             

            示例 1：

            输入：folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
            输出：["/a","/c/d","/c/f"]
            解释："/a/b" 是 "/a" 的子文件夹，而 "/c/d/e" 是 "/c/d" 的子文件夹。
            示例 2：

            输入：folder = ["/a","/a/b/c","/a/b/d"]
            输出：["/a"]
            解释：文件夹 "/a/b/c" 和 "/a/b/d" 都会被删除，因为它们都是 "/a" 的子文件夹。
            示例 3：

            输入: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
            输出: ["/a/b/c","/a/b/ca","/a/b/d"]
             

            提示：

            1 <= folder.length <= 4 * 104
            2 <= folder[i].length <= 100
            folder[i] 只包含小写字母和 '/'
            folder[i] 总是以字符 '/' 起始
            每个文件夹名都是 唯一 的

            来源：力扣（LeetCode）
            链接：https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem
            著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

        */
        class Solution {
        public:
            vector<string> removeSubfolders(vector<string>& folder) {
                sort(folder.begin(), folder.end());
                vector<string> vecStr{};
                for(const auto& strCur: folder){
                    if(vecStr.empty()){
                        vecStr.emplace_back(strCur);
                    }else{
                        auto strLast = vecStr.back();

                        bool shoot{false};
                        if(auto sz = strLast.size()){
                            if(strCur.size() > sz
                            && strLast == strCur.substr(0,sz)
                                && strCur[sz] == '/'){
                                shoot = true;
                            }
                        }

                        if(!shoot){
                            vecStr.emplace_back(strCur);
                        }
                    }
                }
                return vecStr;
            }
        };
    }

    struct Solution_15{
        vector<vector<int>> threeSum(vector<int> &nums){
            if(0){
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
