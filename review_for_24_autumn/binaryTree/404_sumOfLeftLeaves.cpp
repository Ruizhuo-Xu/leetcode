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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return res;
        }
        traversal(root, false);
        return res;
    }

    void traversal(TreeNode* root, bool isLeft) {
        if (root->left == nullptr && root->right == nullptr) {
            if (isLeft) {
                res += root->val;
            }
            return ;
        }
        if (root->left) traversal(root->left, isLeft=true);
        if (root->right) traversal(root->right, isLeft=false);
    }
};