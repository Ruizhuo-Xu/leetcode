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
    int res = INT32_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        traversal(root);
        return res;
    }

    int traversal(TreeNode* root) {
        if (root == nullptr) return 0; // 空树的直径为0
        int left = traversal(root->left);
        int right = traversal(root->right);
        res = max(res, left + right); // 任意两个节点之间的最大路径一定是以某个节点为根结点,
                                    // 其左子树节点到该节点的最大路径+其右子树节点到该节点的最大路径
        return 1 + max(left, right); // 返回上一层,返回当前子树中的节点到上一层根结点的最大路径
    }
};

int main() {
    vector<string> data = {"1", "2", "3", "4", "5"};
    TreeNode* root = construcrtTree(data);
    cout << Solution().diameterOfBinaryTree(root) << endl;
    return 0;
}