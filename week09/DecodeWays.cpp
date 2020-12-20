/*
leetcode 91 解码方法
状态:   dp[i] 表示str从0~i有多少种译码方法

分情况：
s[i] = '0' s[i-1] = (1或2) dp[i] = dp[i-2]

s[i-1] = '1' dp[i] = dp[i-1] + dp[i-2]
s[i-1] = '2' 1 <= s[i] <= 6  fp[i] = dp[i-1] + dp[i-2]

时间复杂度：O(n)
空间复杂度：O(1)

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int numDecodings(string s) {
    if (s[0] == '0') return 0;

    int pre = 1, cur = 1;//dp[-1] = dp[0] = 1
    for (int i = 1; i < s.size(); i++) {
        int tmp = cur;
        if (s[i] == '0') {
            if (s[i - 1] == '1' || s[i - 1] == '2') cur = pre;
            else return 0;
        } else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
        {
            cur = cur + pre; 
        }         
        
        pre = tmp;
    }
    return cur;
}
};