#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* pre;
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;
    }

    void traversal(TreeNode* root) {
        if (root == nullptr) {
            return ;
        }
        traversal(root->right);
        if (pre != nullptr) {
            root->val += pre->val;
        }
        pre = root;
        traversal(root->left);
    }
};