#include <iostream>
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        int res = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                if (i == 0) res = cur->val;
                if (cur->left != nullptr) que.push(cur->left);
                if (cur->right != nullptr) que.push(cur->right);
            }
        }
        return res;
    }
};

class Solution {
public:
    int res = 0;
    int maxDepth = 0;
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) return res;
        traversal(root, 1);
        return res;
    }

    void traversal(TreeNode* root, int depth) {
        if (root->left == nullptr && root->right == nullptr) {  // 深度最大的叶子节点就是最后一层的节点，且由于遍历顺序，记录的肯定是最左边的节点
            if (depth > maxDepth) {
                maxDepth = depth;
                res = root->val;
            }
        }
        if (root->left) traversal(root->left, depth + 1);
        if (root->right) traversal(root->right, depth + 1);
    }
};