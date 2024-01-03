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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            if (compare(node, subRoot)) return true;
            if (node->left != nullptr) que.push(node->left);
            if (node->right != nullptr) que.push(node->right);
        }
        return false;
    }

    bool compare (TreeNode* p, TreeNode* q) {
        if (p == nullptr && q != nullptr) return false;
        else if (p != nullptr && q == nullptr) return false;
        else if (p == nullptr && q == nullptr) return true;
        else if (p->val != q->val) return false;
        return compare(p->left, q->left) && compare(p->right, q->right);
    }
};