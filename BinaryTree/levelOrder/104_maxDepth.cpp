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
    int maxDepth(TreeNode* root) {
        // 层序遍历
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
            }
        }
        return depth;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // 后序遍历,返回的是根结点的高度
        // 二叉树节点的高度：指从该节点到叶子节点的最长简单路径边的条数或者节点数
        int depth = postTraversal(root);
        return depth;
    }

    int postTraversal(TreeNode* cur) {
        if (cur == nullptr) return 0;  // 叶子结点的下一层是空结点,高度为0(假设叶子节点的高度为1)
        int leftDepth = postTraversal(cur->left);
        int rightDepth = postTraversal(cur->right);
        int depth = 1 + max(leftDepth, rightDepth);
        return depth;
    }
};
