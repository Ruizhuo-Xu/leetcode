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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            if (cmp(subRoot, cur)) {
                return true;
            }
            if (cur->left != nullptr) que.push(cur->left);
            if (cur->right != nullptr) que.push(cur->right);
        }
        return false;
    }
    
    bool cmp(TreeNode* root1, TreeNode* root2) {
        // 比较两棵树是否相同，或按某个规则相同（这里是对称）,都可以用这个模板
        if (root1 == nullptr && root2 != nullptr) {
            return false;
        } else if (root1 != nullptr && root2 == nullptr) {
            return false;
        } else if (root1 == nullptr && root2 == nullptr) {
            return true;
        } else if (root1->val != root2->val) {  // 要比较两个节点的值，必须要先对所有为空的情况进行判断
            return false;
        }
        return cmp(root1->left, root2->left) && cmp(root1->right, root2->right);
    }
};