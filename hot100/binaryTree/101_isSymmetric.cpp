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
    bool isSymmetric(TreeNode* root) {
        return compare(root->left, root->right);
    }

    bool compare(TreeNode* left, TreeNode* right) {
        // 分别遍历左子树和右子树,比较左右子树是否互为翻转
        if (left == nullptr && right == nullptr) return true;
        if (left != nullptr && right == nullptr) return false;
        if (left == nullptr && right != nullptr) return false;
        if (left->val != right->val) return false;
        return compare(left->left, right->right) && compare(left->right, right->left);
    }
};

int main() {
    vector<string> data = {"1", "2", "2", "3", "4", "4", "3"};
    TreeNode* root = construcrtTree(data);
    cout << Solution().isSymmetric(root) << endl;
    return 0;
}