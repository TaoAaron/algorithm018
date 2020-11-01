/*
NO.144 二叉树的前序遍历
    递归解法： 
        时间复杂度O(n)
        空间复杂的O(n)
*/

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void preorder(struct TreeNode* root, int* arr, int* returnSize) {
    if (!root) return;

    arr[(*returnSize)++] = root->val; //前序遍历
    preorder(root->left,arr,returnSize);
    preorder(root->right,arr,returnSize);


}

int nodeSize(struct TreeNode* root) {
    if (!root) return 0;

    return nodeSize(root->left) + nodeSize(root->right) + 1;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {

    int size = nodeSize(root);
    int* arr = (int*)malloc(size*sizeof(int));

    *returnSize = 0;    
    preorder(root,arr,returnSize);

    return arr;

}