/*
leetcode 200 岛屿数量
解题思路：核心dfs
    遍历二维数组，双重循环，遍历每行每列
    当前点为1时,岛屿数目加1
    查看其上下左右是否有1，遇到1置0，遇到0 return

时间复杂度：O(M*N) m为行数，n为列数
空间复杂度：O(M*N)
*/

class Solution {

void dfs(vector<vector<char>>& gird, int i, int j) {
    //边界判定
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].szie()) return;

    //terminator
    if (grid[i][j] == '0') return;

    //上下左右
    dfs(gird,i-1,j);
    dfs(gird,i+1,j);
    dfs(gird,i,j-1);
    dfs(gird,i,j+1);

}

public:
    int numIslands(vector<vector<char>>& gird) {
        int count = 0; //岛屿计数

        for (int i = 0; i < gird.size(); i++) {    //遍历行
            for (int j = 0; j < gird[0].szie(); j++) { //遍历列

                if (gird[i][j] == '1') {
                    count++
                }
            }
        }
        return count;
    }
};