/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-10-23 00:37:39
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-02-14 22:27:25
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include <map>
#include <set>
#include <stack>

namespace LeetCode
{
    template<typename T>
    auto display(std::vector<T> ivec){
        for(auto cur : ivec){
            std::cout << cur << ", " ;
        }std::cout << std::endl;
    }
    using namespace std;
    inline namespace Solution_9999{ //20230212
        /**
       
        */
    }

    inline namespace Solution_1124{ //20230214
        /**
        1124. 表现良好的最长时间段
        给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。

        我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是「劳累的一天」。

        所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。

        请你返回「表现良好时间段」的最大长度。

         

        示例 1：

        输入：hours = [9,9,6,0,6,6,9]
        输出：3
        解释：最长的表现良好时间段是 [9,9,6]。
        示例 2：

        输入：hours = [6,6,6]
        输出：0
         

        提示：

        1 <= hours.length <= 104
        0 <= hours[i] <= 16

        来源：力扣（LeetCode）
        链接：https://leetcode.cn/problems/longest-well-performing-interval
        著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
        */
        class Solution {
        public:
            static auto test()->void{
                Solution s;
                //std::vector<int> vec{9,9,6,0,6,6,9};
                // 0,1,2, 3, 4, 5,6
                // 1,1,-1,-1,-1,-1,1
                // 0,1,2,1,0,-1,-2,-1
                // out 3

                std::vector<int> vec{6,6,9};
                // -1,-1,1
                // 0,-1,-2,-1

                auto number = s.longestWPI(vec);
                std::cout << number << std::endl;
            }
            int longestWPI(vector<int>& hours) {

                int out{0};
                int sz = hours.size();
                if(!sz){
                    return out;
                }

                vector<int> vecPre(sz+1,0);
                std::stack<int> sIndexLower;    // index of vecPre
                sIndexLower.push(0);

                int pre{0};
                
                for(int i=0;i<sz;++i){
                    pre +=hours[i]>8?1:-1;
                    vecPre[i+1] = pre;

                    if(vecPre[i+1]<vecPre[sIndexLower.top()]){
                        sIndexLower.push(i+1);
                        
                    }
                }

                display(vecPre);

                for(int i = sz;i>=1;--i){
                    while(sIndexLower.size() && vecPre[sIndexLower.top()]<vecPre[i]  ){
                        out = max(out, i - sIndexLower.top());
                        sIndexLower.pop();
                    }
                }

                return out;
            }
        };
    }



    inline namespace Solution_1234{ //20230213
        // 同向双指针
        /**
        1234. 替换子串得到平衡字符串
        有一个只含有 'Q', 'W', 'E', 'R' 四种字符，且长度为 n 的字符串。

        假如在该字符串中，这四个字符都恰好出现 n/4 次，那么它就是一个「平衡字符串」。

         

        给你一个这样的字符串 s，请通过「替换一个子串」的方式，使原字符串 s 变成一个「平衡字符串」。

        你可以用和「待替换子串」长度相同的 任何 其他字符串来完成替换。

        请返回待替换子串的最小可能长度。

        如果原字符串自身就是一个平衡字符串，则返回 0。

         

        示例 1：

        输入：s = "QWER"
        输出：0
        解释：s 已经是平衡的了。
        示例 2：

        输入：s = "QQWE"
        输出：1
        解释：我们需要把一个 'Q' 替换成 'R'，这样得到的 "RQWE" (或 "QRWE") 是平衡的。
        示例 3：

        输入：s = "QQQW"
        输出：2
        解释：我们可以把前面的 "QQ" 替换成 "ER"。 
        示例 4：

        输入：s = "QQQQ"
        输出：3
        解释：我们可以替换后 3 个 'Q'，使 s = "QWER"。
         

        提示：

        1 <= s.length <= 10^5
        s.length 是 4 的倍数
        s 中只含有 'Q', 'W', 'E', 'R' 四种字符

        来源：力扣（LeetCode）
        链接：https://leetcode.cn/problems/replace-the-substring-for-balanced-string
        著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
        */

        class Solution {
        public:
            static auto test()->void{
                Solution s;
                {
                    auto val = s.balancedString("QQQW");
                    std::cout << val << std::endl;
                }

            }
            int balancedString(string s) {
                string map = "QWER";
                int buck[4]{};
                int l = s.size();
                std::vector<int> vec;
                vec.reserve(l);
                for(int i= 0;i<l;++i){
                    long unsigned int j = 0;
                    for(j = 0;j<map.size();++j){
                        if(s[i] == map[j]){
                            ++buck[j];
                            break;
                        }
                    }
                    vec[i] = j;
                }

                auto valid = [&]{
                    for(auto cur: buck){
                        if(cur> l/4.0){
                            return false;
                        }
                    }
                    return true;
                };

                if(valid()){
                    return 0;
                }

                //std:: cout << "OK1" << std::endl;

                int outMin{l};
                for(int i= 0,j=0;i<l;++i){

                    // for(auto cur: buck){
                    //     std::cout << cur << ", ";
                    // }std::cout << std::endl;

                    //QQQW

                    //int j = i;
                    for(;!valid() && j<l;++j){
                        // if(valid()){
                        //     break;
                        // }
                        --(buck[vec[j]]);
                    }

                    if(!valid()){
                        break;
                    }


                    ++(buck[vec[i]]);

                    outMin = outMin<j-i?outMin : j-i;
                }

                return outMin;
            }
        };
    }







    inline namespace Solution_35{ //20230212
        /**
            35. 搜索插入位置
            给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

            请必须使用时间复杂度为 O(log n) 的算法。

             

            示例 1:

            输入: nums = [1,3,5,6], target = 5
            输出: 2
            示例 2:

            输入: nums = [1,3,5,6], target = 2
            输出: 1
            示例 3:

            输入: nums = [1,3,5,6], target = 7
            输出: 4
             

            提示:

            1 <= nums.length <= 104
            -104 <= nums[i] <= 104
            nums 为 无重复元素 的 升序 排列数组
            -104 <= target <= 104

            来源：力扣（LeetCode）
            链接：https://leetcode.cn/problems/search-insert-position
            著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

        */
       class Solution {
        public:
            
            int searchInsert(vector<int>& nums, int target) {
                int l = 0;
                int r = nums.size()-1;
                int m = (l+r)/2;

                std::function<int(int,int,int)> lll = [&] (int l, int r, int m)->int{
                    if(l == r){
                        if(target > nums[m]){
                            return m+1;
                        }
                        return m;
                    }
                    
                    if(target < nums[m]){
                        return lll(l, m, (l+m)/2);
                    }else if(target > nums[m]){
                        return lll(m+1,r, (m+1+r)/2);
                    }
                    
                    return m;
                };
                return lll(l,r,m);
            }
        };
    }

    inline namespace Solution_27{ //20230212
        /**
            27. 移除元素
            给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

            不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

            元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

             

            说明:

            为什么返回数值是整数，但输出的答案是数组呢?

            请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

            你可以想象内部操作如下:

            // nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
            int len = removeElement(nums, val);

            // 在函数里修改输入数组对于调用者是可见的。
            // 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
            for (int i = 0; i < len; i++) {
                print(nums[i]);
            }
             

            示例 1：

            输入：nums = [3,2,2,3], val = 3
            输出：2, nums = [2,2]
            解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。
            示例 2：

            输入：nums = [0,1,2,2,3,0,4,2], val = 2
            输出：5, nums = [0,1,4,0,3]
            解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。
             

            提示：

            0 <= nums.length <= 100
            0 <= nums[i] <= 50
            0 <= val <= 100

            来源：力扣（LeetCode）
            链接：https://leetcode.cn/problems/remove-element
            著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
       
        */

       class Solution {
        public:
            int removeElement(vector<int>& nums, int val) {

                int indexLast = nums.size()-1;
                while(indexLast>=0 && nums[indexLast] == val){
                    --indexLast;
                }
                for(int i = indexLast;i>=0;--i){
                    if(nums[i] == val){
                        swap(nums[i], nums[indexLast]);
                        --indexLast;
                    }
                }
                return indexLast+1;

            }
        };
    }

    inline namespace Solution_1138{ //20230212
        /**
        1138. 字母板上的路径

        我们从一块字母板上的位置 (0, 0) 出发，该坐标对应的字符为 board[0][0]。

        在本题里，字母板为board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]，如下所示。


        a   b   c   d   e
        f   g   h   i   j
        k   l   m   n   o
        p   q   r   s   t
        u   v   w   x   y
        z

        我们可以按下面的指令规则行动：

        如果方格存在，'U' 意味着将我们的位置上移一行；
        如果方格存在，'D' 意味着将我们的位置下移一行；
        如果方格存在，'L' 意味着将我们的位置左移一列；
        如果方格存在，'R' 意味着将我们的位置右移一列；
        '!' 会把在我们当前位置 (r, c) 的字符 board[r][c] 添加到答案中。
        （注意，字母板上只存在有字母的位置。）

        返回指令序列，用最小的行动次数让答案和目标 target 相同。你可以返回任何达成目标的路径。

         

        示例 1：

        输入：target = "leet"
        输出："DDR!UURRR!!DDD!"
        示例 2：

        输入：target = "code"
        输出："RR!DDRR!UUL!R!"
         

        提示：

        1 <= target.length <= 100
        target 仅含有小写英文字母。

        来源：力扣（LeetCode）
        链接：https://leetcode.cn/problems/alphabet-board-path
        著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

        */
       class Solution {
        public:
            string alphabetBoardPath(string target) {
                string strOut;
                auto xP = 0;
                auto yP = 0;

                for(auto charCur: target){
                    auto x = (charCur-'a')/5;
                    auto y = (charCur-'a')%5;

                    if(x<xP){
                        strOut.append(xP-x,'U');
                    }
                                
                    if(y<yP){
                        strOut.append(yP-y,'L' );
                    }

                    if(x>xP){
                        strOut.append(x-xP,'D');
                    }

                    if(y>yP){
                        strOut.append(y-yP,'R' );
                    }
                    strOut.append(1,'!');

                    xP = x;
                    yP = y;

                    
                }

                return strOut;
            }
        };
    }




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
