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
    bool isBalanced(TreeNode* root) {
        if (getHeight(root) == -1) {
            return false;
        }
        return true;
    }

    int getHeight(TreeNode* root) {
        // 求树的高度，使用后序遍历
        if (root == nullptr) {
            return 0;
        }
        int leftHeight = getHeight(root->left);
        if (leftHeight == -1) {
            return -1;
        }
        int rightHeight = getHeight(root->right);
        if (rightHeight == -1) {
            return -1;
        }
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return max(leftHeight, rightHeight) + 1;
    }
};