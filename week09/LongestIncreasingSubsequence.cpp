/*
leetcode 300 最长递增子序列
dp[i] 表示0~i之间最长严格递增自序列长度

状态转移方程：
初始状态: 每个单独数字都可看作一个最小子序列
dp[0~i-1] = 1
看情况：
if nums[i] > nums[j]
    dp[i] = max(dp[i],dp[j] + 1)
else
    continue;

时间复杂度：O(n^2)
空间复杂度：O(n)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLTS(vector<int>&nums) {
        if (!nums.size()) return 0;
        int n = nums.size();

        //初始化状态
        vector<int> dp(n,1);
        int res = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            res = max(dp[i],res);
        }
        return res;
    }

};
