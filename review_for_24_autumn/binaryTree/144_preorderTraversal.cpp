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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }

    void traversal(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return ;
        }
        res.push_back(root->val);
        traversal(root->left, res);
        traversal(root->right, res);
    }
};