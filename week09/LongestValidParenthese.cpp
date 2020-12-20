/*
leetcode 32 最长有效括号
动态规划：
1、定义状态
dp[i] 表示以i为结尾的最长有效括号的长度
2、初始状态
全部初始化为0
3、
    if s[i] = '(' ---> dp[i] = 0

    if s[i] = ')' && s[i - 1] = '(' ---> dp[i] = dp[i-2] + 2
    if s[i] = ')' && s[i - 1] = ')' 这种情况下 要形成有效形式 类似“ (())” 
        要求s[i-1]位置必须形成有效括号对
        S[i]就需要与s[i-dp[i-1]-1]的位置去配对 --->
        if s[i-dp[i-1]-1] == '(' 符合情况 --->       
        dp[i]=dp[i−1] + dp[i−dp[i−dp[-1]−2] + 2
时间复杂度: o(n)
空间复杂度：o(n)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n,0);

        int ans = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;            
                } else if (i - dp[i - 1] > 0 && s [i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};