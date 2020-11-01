/*
NO.589  N叉树的前序遍历
思路：递归方式
    时间复杂度O(n)
    空间复杂的O(n)

思路：迭代方式 用栈来实现
    时间复杂度O(n)
    空间复杂的O(n)
    
*/

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

//递归解法
class Solution {
private:
    vector<int> res;
void tranversal(Node* root) {
    if (!root) return;

    res.push_back(root->val);

    for (int i=0; i<root->children.size(); i++) {   //根据儿子节点的数量
        tranversal(root->children[i]);
    }

}  
public:
vector<int> preorder(Node* root) {
    res.clear();
    tranversal(root);
    return res;
}

};

//迭代解法
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (!root) return;

        stack<Node*> stk;  //Node * 类型的栈
        stk.push(root);

        while (!stk.empty()) {
            Node* node = stk.top();
            stk.pop();
            res.push_back(node->val);

            //倒序遍历
            for (int i=node->children.size()-1; i>=0; i++)
                if (node->children[i]) {
                    stk.push(node->children[i]);
                }
        }
        return res;
    }

};

