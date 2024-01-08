#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* construcrtTree(vector<string> data) {
    if (data.size() == 0) return nullptr;
    vector<TreeNode*> tree(data.size(), nullptr);
    for (int i = 0; i < data.size(); i++) {
        if (data[i] != "null") {
            tree[i] = new TreeNode(stoi(data[i]));
        }
    }
    for (int i = 0; i * 2 + 1 < tree.size(); i++) {
        if (tree[i] != nullptr) {
            tree[i]->left = tree[i * 2 + 1];
            if (i * 2 + 2 < tree.size()) {
                tree[i]->right = tree[i * 2 + 2];
            }
        }
    }
    return tree[0];
}

class Solution {
public:
    TreeNode* pre;
    bool isValidBST(TreeNode* root) {
        // 二叉搜索树中序遍历满足递增条件
        if (root == nullptr) return true;
        bool left = isValidBST(root->left);
        if (pre != nullptr && pre->val >= root->val) {
            return false;
        }
        pre = root;
        bool right = isValidBST(root->right);
        return left && right;
    }
};

int main() {
    vector<string> data = {"2", "1", "3"};
    TreeNode* root = construcrtTree(data);
    cout << Solution().isValidBST(root) << endl;
    return 0;
}