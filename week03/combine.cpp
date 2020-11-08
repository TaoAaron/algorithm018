/*
    leetcode NO.77 组合

    解题思路：分解成树状结构
    以 n = 4 k = 2为例
    放1 下面就有[2,3,4]可选, 1->2 完成一条路径
    返回条件path.size() == k

    时间复杂度：O(n*n!)
    空间复杂度：O(n)
     

*/

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path; 
   
    void backtracking(int n, int k, int start) {
        //termination
        if (path.size() == k) {
            res.push_back(path);           
            return;
        }

        
    for (int i = start; i <= n - (k-path.size()) + 1; i++) {    //剪枝
            path.push_back(i);
            backtracking(n, k, i + 1); //drill down
            path.pop_back();  //回溯
        }
    }

public: 

    vector<vector<int>> combine(int n, int k) {
        res.clear();
        path.clear();

        backtracking(n,k,1);
        return res;
    }
};