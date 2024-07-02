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
    int res = 0;
    int maxDepth(TreeNode* root) {
        traversal(root, 1);
        return res;
    }

    void traversal(TreeNode* root, int depth) {
        if (root == nullptr) {
            return ;
        }
        res = max(res, depth);  // depth表示当前节点(非null)的深度
        traversal(root->left, depth + 1);
        traversal(root->right, depth + 1);
    }
};