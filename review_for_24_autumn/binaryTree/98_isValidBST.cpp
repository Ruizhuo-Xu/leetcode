#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        // 二叉搜索树中序遍历是递增的
        if (root == nullptr) {
            return true;
        }
        bool left = isValidBST(root->left);
        if (pre == nullptr) {
            pre = root;
        } else {
            if (pre->val >= root->val) { // 非递增都是false
                return false;
            }
            pre = root;
        }
        bool right = isValidBST(root->right);
        return left && right;
    }
};