/*
leetcode 213 打家劫舍Ⅱ
动态规划：
使用打家劫舍1的动态规划思路

需要区分两个状态 dp[n][0,1] 0表示偷第0家 1表示不偷第0家

时间复杂度：O(n)
空间复杂度：O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        } else if ( n < 4) {
            return (*max_element(nums.begin(),nums.end()));
        }

        int dp[n][2];   //dp状态
        dp[0][0] = 0; //不偷第0家
        dp[0][1] = nums[0]; //偷第0家
        dp[1][0] = nums[1]; //不偷第0家
        dp[1][1] = nums[0]; //偷第0家,偷了第0家后第1家不能偷

        for (int i = 2; i < n; i++) {
            if (i != n-1) { //不是最后一家
                dp[i][0] = max(dp[i-1][0],dp[i-2][0] + nums[i]);//不偷第0家
                dp[i][1] = max(dp[i-1][1],dp[i-2][1] + nums[i]);
            } else {
                dp[i][0] = max(dp[i-1][0],dp[i-2][0] + nums[i]);
                dp[i][1] = dp[i-1][1];
            }
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }

};
