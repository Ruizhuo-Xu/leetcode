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
    int res;
    int kthSmallest(TreeNode* root, int k) {
        traversal(root, k);
        return res;
    }

    void traversal(TreeNode* cur, int& k) {
        if (cur == nullptr) return ;
        traversal(cur->left, k);
        k--;
        if (k == 0) {
            res = cur->val;
            return ;
        }
        traversal(cur->right, k);
    }
};

int main() {
    vector<string> data = {"3","1","4","null","2"};
    TreeNode* root = construcrtTree(data);
    int k = 1;
    cout << Solution().kthSmallest(root, k);
    return 0;
}