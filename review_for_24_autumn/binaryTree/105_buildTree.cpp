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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }
        if (inStart == inEnd) {
            return new TreeNode(inorder[inStart]);
        }
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        int rootIdx = -1;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                rootIdx = i;
                break;
            }
        }
        root->left = build(preorder, inorder, preStart + 1, preStart + 1 + (rootIdx - 1) - inStart, inStart, rootIdx - 1);
        root->right = build(preorder, inorder, preStart + 1 + (rootIdx - 1) - inStart + 1, preEnd, rootIdx + 1, inEnd);
        return root;
    }
};