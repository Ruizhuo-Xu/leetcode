#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        // 时间复杂度：O(log n × log n)
        // 空间复杂度： O(log n)
        if (root == nullptr) {
            return 0;
        }
        TreeNode* cur = root;
        int leftDepth = 0;
        while (cur) {
            cur = cur->left;
            leftDepth++;
        }
        cur = root;
        int rightDepth = 0;
        while (cur) {
            cur = cur->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth) {
            return  (2 << (leftDepth - 1)) - 1;
        }
        int leftCnt = countNodes(root->left);
        int rightCnt = countNodes(root->right);
        return leftCnt + rightCnt + 1;
    }
};
