/*
剑指offer NO.49 丑数

时间复杂度：O(n)
空间复杂度：O(n)

*/


class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n); //有n个丑数

        int a = 0, b = 0, c = 0;
        dp[0] = 1;   //第一个丑数为1

        for (int i=1; i<n; i++) {
            int a2 = dp[a] * 2, b3 = dp[b]*3, c5 = dp[c]*5; //计算新的丑数
            dp[i] = min(a2,min(b3,c5)); //依次加入最小的丑数

            /*已加入的丑数，不再计算*/
            if (dp[i] == a2) a++;
            if (dp[i] == b3) b++;
            if (dp[i] == c5) c++;
        }
        return dp[n-1];
    }
};