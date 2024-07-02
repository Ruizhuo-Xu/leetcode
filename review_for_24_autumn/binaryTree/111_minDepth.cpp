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
    int res = INT32_MAX;
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        traversal(root, 1);
        return res;
    }

    void traversal(TreeNode* root, int depth) {
        if (root->left == nullptr && root->right == nullptr) {
            res = min(res, depth);
            return ;
        }
        if (root->left != nullptr)  traversal(root->left, depth + 1);
        if (root->right != nullptr)  traversal(root->right, depth + 1);
    }
};