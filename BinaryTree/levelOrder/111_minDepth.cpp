#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        int depth = 0;
        while (!que.empty()) {
            int size = que.size();
            depth++;
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
                if (node->left == nullptr && node->right == nullptr) {
                    return depth;
                }
            }
        }
        return depth;
    }
};