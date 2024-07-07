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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> res;
        if (root != nullptr) {
            path.push_back(root->val);
            traversal(root, targetSum, root->val, path, res);
        }
        return res;
    }

    void traversal(TreeNode* root, int targetSum, int curSum, vector<int>& path, vector<vector<int>>& res) {
        if (root->left == nullptr && root->right == nullptr) {
            if (curSum == targetSum) {
                res.push_back(path);
            }
            return ;
        }
        if (root->left != nullptr) {
            path.push_back(root->left->val);
            traversal(root->left, targetSum, curSum + root->left->val, path, res);
            path.pop_back();
        }
        if (root->right != nullptr) {
            path.push_back(root->right->val);
            traversal(root->right, targetSum, curSum + root->right->val, path, res);
            path.pop_back();
        }
    }
};