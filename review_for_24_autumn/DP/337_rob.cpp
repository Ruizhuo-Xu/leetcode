#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        return traversal(root).first;
    }

    pair<int, int> traversal(TreeNode* root) {
        if (root == nullptr) return pair<int, int>(0, 0);
        pair<int, int> left = traversal(root->left);
        pair<int, int> right = traversal(root->right);
        int maxVal = max(left.first + right.first, left.second + right.second + root->val);  // 相当于max(dp[i - 1], dp[i - 2] + nums[i])
        int preMaxVal = left.first + right.first;
        return pair<int, int>(maxVal, preMaxVal);  // 相当于dp[i - 1], dp[i - 2]
    }
};
