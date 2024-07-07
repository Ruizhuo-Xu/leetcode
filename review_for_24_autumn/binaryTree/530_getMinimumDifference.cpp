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
    int res = INT32_MAX;
    TreeNode* pre = nullptr;
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return res;
    }

    void traversal(TreeNode* root) {
        if (root == nullptr) {
            return ;
        }
        traversal(root->left);
        if (pre == nullptr) {
            pre = root;
        } else {
            res = min(res, abs(root->val - pre->val));
            pre = root;
        }
        traversal(root->right);
    }
};