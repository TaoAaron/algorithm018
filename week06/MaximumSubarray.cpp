/*
leetcode 53 最大子序和
动态规划：
状态dp只需要dp的前一项
dp = max(dp+nums[i],nums[i])

时间复杂度：O(n)
空间复杂度：O(1)
*/
#include <bits/stdc++.h>
using namespace std;

class solution {
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        //dp边界状态
        int dp = nums[0];
        int result = dp;

        for (int i = 1; i < nums.size(); i++) {
            dp = max(dp+nums[i],nums[i]);
            result = max(dp,result);
        }
        return result;
    }

};