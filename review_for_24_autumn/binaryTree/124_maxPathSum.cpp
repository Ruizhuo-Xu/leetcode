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
    int res = INT32_MIN;
    int maxPathSum(TreeNode* root) {
        traversal(root);
        return res;
    }

    int traversal(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = traversal(root->left);
        int right = traversal(root->right);
        // 考虑以当前节点为根节点的路径
        left = max(left, 0);
        right = max(right, 0);
        res = max(res, left + right + root->val);
        // 返回的是当前节点出发的最大路径和
        return max(left, right) + root->val;
    }
};