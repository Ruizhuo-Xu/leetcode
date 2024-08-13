#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<string>& tree) {
    if (tree.size() == 0) {
        return nullptr;
    }
    vector<TreeNode*> treeNodes(tree.size(), nullptr);
    for (int i = 0; i < tree.size(); i++) {
        if (tree[i] != "null") {
            treeNodes[i] = new TreeNode(stoi(tree[i]));
        }
    }
    for (int i = 0; i * 2 + 1 < tree.size(); i++) {
        if (treeNodes[i] != nullptr) {
            treeNodes[i]->left = treeNodes[i * 2 + 1];
            if (i * 2 + 2 < tree.size()) {
                treeNodes[i]->right = treeNodes[i * 2 + 2];
            }
        }
    }
    return treeNodes[0];
}