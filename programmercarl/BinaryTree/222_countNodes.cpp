#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode* cur = root;
        int leftDepth = 0;
        while (cur) {
            cur = cur->left;
            leftDepth++;
        }
        cur = root;
        int rightDepth = 0;
        while(cur) {
            cur = cur->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth) { // 完全二叉树的特性,如果归向左遍历的深度等于递归向右遍历的深度，那说明就是满二叉树
            // 注意:移位运算符的优先级低于'+ - * /'
            return (2 << (leftDepth - 1)) - 1;
        }
        int leftNodes = countNodes(root->left);
        int rightNodes = countNodes(root->right);
        return leftNodes + rightNodes + 1;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    cout << Solution().countNodes(root) << endl;
    return 0;
}