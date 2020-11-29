/*
leetcode 64 最小路径和

动态规划：
dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + gird[i][j]

dp[j][j] 的状态可以直接使用gird

初始状态，第一行 第一列 左上角格子
时间复杂度：o(m*n)
空间复杂度：O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class SOlution {
int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size();
    int cloumn = grid[0].size();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cloumn; j++) {
            if (i == 0 && j != 0) { //第一行 初始状态
                grid[i][j] += grid[i][j-1];
            } else if ( j == 0 && i != 0) { //第一列 初始状态
                grid[i][j] += grid[i-1][j];
            } else if (i != 0 && j != 0) {
                grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
            } else { //左上角格子

            }

        }
    }
    return grid[row-1][cloumn-1];    
}

};