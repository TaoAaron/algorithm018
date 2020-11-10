/*
leetcode NO.46 全排列
解题思路：回溯法

时间复杂度：O(n*n!)
空间复杂度：O(n)

*/

class Solution {
private:
    vector<vector<int>> res;

    void backtracking(vector<int>& nums, vector<int>& path, vecotr<bool>& used) {
        if (path.size() = nums.size()) {    //完成一个组合
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size; i++) {
            if (used[i]) {
                path.push_back(nums[i]);
                nums1[i] = false; //用过的标记为false,不可用
                backtracking(nums,path,used);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) 
            return {};
        else if (nums.size() == 1) 
            return {{nums[0]}};
        else {
            vector<bool> used(nums.size(),true);
            vector<int> path;
            backtracking(nums,path,used);
        }
        return res;
    }
};