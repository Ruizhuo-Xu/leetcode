#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        getHeight(root);
        return res;
    }

    int getHeight(TreeNode* root) {
        // 遍历每个节点左子树的高度和右子树的高度，左子树高度+右子树高度=可能的最大值
        if (root == nullptr) {
            return 0;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        res = max(left + right, res);
        return max(left, right) + 1;
    }
};