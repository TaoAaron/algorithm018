## 不同路径Ⅱ  
### 动态规划解法：  
状态定义：用dp[i][j]表示从坐标点(0,0)到(i,j)的路径总和  
根据不同的情况，确定不同的动态转移过程：  
i = 0 && j = 0  dp[i][j] = 1    //左上角
i = 0 && j != 0 dp[i][j] = obstacleGrid[i][j] ？0 ： dp[i][j-1]   //第一行  
i != 0 && j =0 dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i-1][j]   //第一列  
i ！= 0 && j != 0 dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i][j - 1] + dp[i - 1][j])  
