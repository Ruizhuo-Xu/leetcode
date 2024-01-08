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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                TreeNode* cur = que.front();
                que.pop();
                if (size == 0) res.push_back(cur->val);
                if (cur->left != nullptr) que.push(cur->left);
                if (cur->right != nullptr) que.push(cur->right);
            }
        }
        return res;
    }
};

int main() {
    vector<string> data = {"1","2","3","null","5","null","4"};
    TreeNode* root = construcrtTree(data);
    vector<int> res = Solution().rightSideView(root);
    for (int num : res) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}