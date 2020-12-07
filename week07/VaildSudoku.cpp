/*
leetcode 36 有效的数独

思路：对于1个格子，分别要进行 行、列、3X3格子的检查
这3种检查，如何在一次迭代中完成；
空间换时间

时间复杂度：O(1)
空间复杂度：O(1)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int column[9][9] = {0};
        int box[9][9] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j =0 ; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (row[i][board[i][j] - '0' - 1]++) return false;
                    if (column[j][board[i][j] - '0' -1]++) return false;
                    if (box[(i/3)*3 + j/3][board[i][j] - '0' -1]++) return false;
                }
            }
        }
        return true;
    }
};