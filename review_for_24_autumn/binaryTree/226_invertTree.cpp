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
    TreeNode* invertTree(TreeNode* root) {
        traversal(root);
        return root;
    }

    void traversal(TreeNode* root) {
        if (root == nullptr) return ;
        swap(root->left, root->right);
        traversal(root->left);
        traversal(root->right);
    }
};