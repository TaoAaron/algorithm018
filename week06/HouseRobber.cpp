/*
leetcode 198 打家劫舍
思路：典型的动态规划问题
尝试一：常规动态规划解法
dp[i][0,1] ：0表示不偷，1表示偷

状态方程：
dp[i][0] = max(dp[i-1][0],dp[i-1][1])
dp[i][1] = dp[i-1][0] + nums[i]

时间复杂度：O(n)
空间复杂度：O(n)

尝试二：
dp[i] 0 ~i 能偷到的最大值（包括偷或者不偷）
假设i要偷的话，i-1不能偷，所以要去看i-2
dp[i] = max(dp[i-1],dp[i-2] + num[i])

空间复杂度：O(n)
时间复杂度：O(n)

*/

#include <bits/stdc++.h>
using namespace std;


class solution1 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int dp[n][2]; //定义两种状态：0 偷 1不偷
        //初始化边界状态
        dp[0][0] = 0; //第一家不偷
        dp[0][1] = nums[0]; //第一家偷

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]); //第i家 不偷的情况
            dp[i][1] = dp[i-1][0] + nums[i];    //第i家 偷的情况
        }

        return max(dp[n-1][0],dp[n-1][1]);
    }
  };


class solution2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1) return n == 0 ? 0 : nums[0];

        int dp[n];

        //初始状态
        dp[0] = 0; //第一家不偷
        dp[1] = max(nums[0],nums[1]); // 0~1家能偷到的最大值

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1],dp[i-2] + nums[i]);         
        }

        return dp[n-1];
    }

};

