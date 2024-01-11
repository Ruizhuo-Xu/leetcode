#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* constructTree(vector<string> data) {
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
    void flatten(TreeNode* root) {
        traversal(root);
    }

    TreeNode* traversal(TreeNode* root) {
        // 后序遍历, 展平当前根节点表示的树
        if (root == nullptr) return nullptr;
        TreeNode* left = traversal(root->left);
        TreeNode* right = traversal(root->right);
        root->right = root->left; // 将左子树节点插入右子树
        root->left = nullptr; // 左子树置空
        TreeNode* cur = root;
        while (cur->right != nullptr) { // 接上原先的右子树节点
            cur = cur->right;
        }
        cur->right = right;
        return root;
    }
};

int main() {
    vector<string> data = {"1","2","5","3","4","null","6"};
    TreeNode* root = constructTree(data);
    Solution().flatten(root);
    TreeNode* cur = root;
    while (cur) {
        cout << cur->val << ' ';
        cur = cur->right;
    }
    cout << endl;
    return 0;
}
