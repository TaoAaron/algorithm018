/*
leetcode 221 最大正方形
动态规划：
dp[i][j] 表示以i,j为右下角的且全为1的正方形对应的最大边长

初始状态


matrix[i][j] = 0时， dp[i][j] = 0;

matrix[0][0] = 1时， dp[0][0] = 1;

maxtrix[i][j] = 1时，dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1

时间复杂度：O(n*m)
空间复杂度：O(n*m)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int maxSide = 0; //最大的边长

        int row = matrix.size(), column = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(column));
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 && j == 0) {
                        dp[i][j] = 1;
                    } else {
                        //左边格子，上边格子，左上格子的 最小的dp值 + 1
                        dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
                    }
                    maxSide = max(maxSide,dp[i][j]);
                }
            }
        }
        return maxSide*maxSide;
    }


};