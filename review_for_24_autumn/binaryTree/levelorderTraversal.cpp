#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        vector<vector<int>> res;
        while (!que.empty()) {
            int size = que.size();
            vector<int> temp;
            while (size--) {
                TreeNode* cur = que.front();
                temp.push_back(cur->val);
                que.pop();
                if (cur->left != nullptr) que.push(cur->left);
                if (cur->right != nullptr) que.push(cur->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};