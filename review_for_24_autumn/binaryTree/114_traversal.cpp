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
    void flatten(TreeNode* root) {
        traversal(root);
    }

    TreeNode* traversal(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        TreeNode* left = traversal(root->left);
        TreeNode* right = traversal(root->right);
        root->right = left;
        root->left = nullptr;
        TreeNode* cur = root;
        while (cur->right != nullptr) {
            cur = cur->right;
        }
        cur->right = right;
        return root;
    }
};