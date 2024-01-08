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

TreeNode* constructTree(vector<string>& data) {
    if (data.size() == 0) return nullptr;
    vector<TreeNode*> tree(data.size(), nullptr);
    for (int i = 0; i < data.size(); i++) {
        if (data[i] != "null") {
            tree[i] = new TreeNode(stoi(data[i]));
        }
    }
    for (int i = 0; 2 * i + 1 < tree.size(); i++) {
        if (tree[i] != nullptr) {
            tree[i]->left = tree[2 * i + 1];
            if (2 * i + 2 < tree.size()) {
                tree[i]->right = tree[2 * i + 2];
            }
        }
    }
    return tree[0];
}

class Solution {
public:
    int res;
    int maxDepth(TreeNode* root) {
        // 前序(深度),后序(高度),层序都可以
        if (root == nullptr) return 0;
        traversal(root, 1);
        return res;
    }

    void traversal(TreeNode* cur, int depth) {
        // depth表示当前节点的深度
        if (cur->left == nullptr && cur->right == nullptr) { // 叶子节点,记录结果并返回
            res = max(res, depth);
            return ;
        }
        if (cur->left != nullptr) {
            traversal(cur->left, depth + 1);
        }
        if (cur->right != nullptr) {
            traversal(cur->right, depth + 1);
        }
        return ;
    }
};

int main() {
    vector<string> data = {"3","9","20","null","null","15","7"};
    TreeNode* root = constructTree(data);
    cout << Solution().maxDepth(root) << endl;
    return 0;
}