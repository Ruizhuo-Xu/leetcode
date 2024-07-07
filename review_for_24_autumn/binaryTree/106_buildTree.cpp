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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) {
            return nullptr;
        }
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd) {  // 左闭右闭 要判断区间是否合法!!!
            return nullptr;
        }
        if (inStart == inEnd) {
            return new TreeNode(inorder[inStart]);
        }
        // 后序遍历: 左右中, 根节点是最后一个遍历到的
        int rootVal = postorder[postEnd];
        int rootIdx = -1;
        // 中序遍历: 左中右, 根节点在中间, 划分左右子树
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                rootIdx = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(inorder[rootIdx]);
        // 这里计算postStart, postEnd的时候可以按照 postEnd - postStart == inEnd - inStart来考虑
        root->left = build(inorder, postorder, inStart, rootIdx - 1, postStart, postStart + (rootIdx - 1 - inStart));
        // root->right = build(inorder, postorder, rootIdx + 1, inEnd, postStart + (rootIdx - 1 - inStart) + 1, postStart - inStart + inEnd - 1);
        root->right = build(inorder, postorder, rootIdx + 1, inEnd, postStart + (rootIdx - 1 - inStart) + 1, postEnd - 1);
        return root;
    }
};