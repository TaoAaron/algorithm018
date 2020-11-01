/*
 NO.1 两数之和
 之前用过暴力解法：两个嵌套循环，时间复杂度是O(n2)
 采用hash表解法

 时间复杂度：O(N)
 空间复杂度：O(N)

*/

class Solution {
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> map;    //数值 下标

        for (int i=0; i<num.size(); i++) {
            auto iter = map.find(target - nums[i]); //查找map中是已存在

            if (iter != map.end()) {
                return {iter->second, i};
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return {}; //返回空
    }
    
};