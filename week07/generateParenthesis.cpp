/*
leetcode 22 括号生成
思路：dfs + 剪枝
重点是剪枝的处理，何时进行剪枝

时间复杂度：
空间复杂度：O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    void dfs(vector<string> &res, string str, int left, int right) {
        //terminator
        if (left == 0 && right == 0) {
            res.push_back(str);
            return;
        }

        if (left > 0) dfs(res, str+'(', left-1, right); //drill down
        if (right > left) dfs(res, str+')', left, right-1); //drill down
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res,"",n,n);
        return res;
     }
};