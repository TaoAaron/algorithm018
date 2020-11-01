/*
    NO.94 二叉树的中序遍历
    递归解法：
        
        时间复杂度O(n),每个节点只会被访问1次，n为二叉数节点个数
        空间复杂度O(n)

    迭代解法:
        本质上类似递归解法
        显示的将递归的栈模拟出来

        时间复杂度O(n)
        空间复杂度O(n)

*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void inorder(struct TreeNode* root, int* arr, int* returnSize) {
    if (!root) return;

    inorder(root->left,arr,returnSize);
    arr[(*returnSize)++] = root->val; //中序遍历
    inorder(root->right,arr,returnSize);

}


int nodeSize(struct TreeNode *root) {
    if (!root) return 0;

    return nodeSize(root->left) + nodeSize(root->right) + 1;
}

int* inorderTranversal(struct TreeNode* root, int* returnSize) {
    int size = nodeSize(root);
    int *arr = (int*)malloc(size*sizeof(int));

    *returnSize = 0;

    inorder(root,arr,returnSize);

    return arr;
}


/*迭代*/
int* inorderTranversal(struct TreeNode* root, int *returnSize) {
    *returnSize = 0;
    int* res = (int*)malloc(501*sizeof(int));
    struct TreeNode** stk = (struct TreeNode**)malloc(501*sizeof(struct TreeNode*));

    int top = 0;

    while (root || top>0) {
        while(root) {
            stk[top++] = root; //压栈
            root = root->left;
        }

        root = stk[--top]; //出栈
        res[(*returnSize)++] = root->val;
        
        root = root->right; //检测右子树

    }
}
