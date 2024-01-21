#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdint>
#include <algorithm>
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
        if (tree[i] != nullptr)  {
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
    int maxPathSum(TreeNode* root) {
        traversal(root);
        return res;
    }

    int traversal(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = traversal(root->left);
        int right = traversal(root->right);
        res = max(left + right + root->val, res);
        return max(max(left, right) + root->val, 0);
    }
};

int main() {
    vector<string> data = {"-10","9","20","null","null","15","7"};
    TreeNode* root = constructTree(data);
    cout << Solution().maxPathSum(root) << endl;
    return 0;
}