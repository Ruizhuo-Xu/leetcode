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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* cur = root;
        while (cur != nullptr) {
            if (cur->val > val) {
                cur = cur->left;
            } else if (cur->val < val) {
                cur = cur->right;
            } else {
                return cur;
            }
        }
        return nullptr;
    }
};