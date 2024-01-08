#include <iostream>
#include <vector>
#include <string>
#include <queue>
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

void printTree(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != nullptr) {
        que.push(root);
    }
    vector<string> res;
    while (!que.empty()) {
        int size = que.size();
        while (size--) {
            TreeNode* cur = que.front();
            que.pop();
            if (cur != nullptr) {
                res.push_back(to_string(cur->val));
                que.push(cur->left);
                que.push(cur->right);
            } else {
                res.push_back("null");
            }
        }
    }
    for (string s : res) {
        cout << s << ' ';
    }
    cout << endl;
    return ;
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // 后序, 前序, 层序都可以
        if (root == nullptr) return root;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

int main() {
    vector<string> data = {"4","2","7","1","3","6","9"};
    TreeNode* root = constructTree(data);
    printTree(root);
    Solution().invertTree(root);
    printTree(root);
    return 0;
}