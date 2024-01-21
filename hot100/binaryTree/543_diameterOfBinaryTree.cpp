#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
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
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        traversal(root);
        return res;
    }
    int traversal(TreeNode* cur) {
        if (cur == nullptr) return 0;
        int left = traversal(cur->left);
        int right = traversal(cur->right);
        res = max(left + right, res); // 左子树高度+右子树高度=当前节点的直径
        return max(left, right) + 1; // 返回当前节点的高度，默认叶子节点高度为1
    }
};

int main() {
    vector<string> data = {"1", "2", "3", "4", "5"};
    TreeNode* root = construcrtTree(data);
    cout << Solution().diameterOfBinaryTree(root) << endl;
    return 0;
}