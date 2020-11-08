/*
leetcode NO.236 二叉树的最近公共祖先

解题思路：回溯
后序遍历的方式，后序遍历是看完叶子节点再去看根结点

时间复杂度：O(n) 
空间复杂度：O(n)

*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNod* root, TreeNode* p, TreeNode* q) {

        //terminnation
        if(root == p || root == q || !root) return root;    //当前的节点是p或者p就返回

        //trill down
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        //返回结果 处理
        if(left && right) return root; //如果左右节点都存在，root必然是它们的最近公共祖先

        if (!left) 
            return right; //若没有left节点，那就要返回right节点
        else
            return left;
    }
 

}