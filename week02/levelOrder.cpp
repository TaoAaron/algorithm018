/*
 NO.429  N叉树的层序遍历
解法：使用队列来实现，

    时间复杂度：O(n)
    空间付啊都：O(n)

*/

class Solution {
public:
    vector<vecotr<int>> levelOrder(Node *root) {
    queue<TreeNode *> que; //使用队列
    vector<vector<int>> res;
    

    if(root) que.push(root);

    while (!que.empty()) {  //每次循环是1层
        int size = que.size();
        vector<int> nums;

        for(int i=0; i<size; i++) {
            Node * node = que.front(); //获取队列头
            que.pop(); //弹出
            nums.push_back(node->val); //取值

            for (int i=0; i<node->children.size(); i++) {
                if (node->childer[i]) que.push(node->childer[i]));
            }
        }
        result.push_back(nums);
    }
        return res;

    }


};