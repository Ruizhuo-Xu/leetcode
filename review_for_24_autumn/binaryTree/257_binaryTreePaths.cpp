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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        if (root == nullptr) return res;
        traversal(root, path);
        return res;
    }

    void traversal(TreeNode* root, vector<int>& path) {
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            string s = to_string(path[0]);
            for (int i = 1; i < path.size(); i++) {
                s.append("->" + to_string(path[i]));
            }
            res.push_back(s);
            return ;
        }
        if (root->left) {
            traversal(root->left, path);
            path.pop_back();
        }
        if (root->right) {
            traversal(root->right, path);
            path.pop_back();
        }
    }
};