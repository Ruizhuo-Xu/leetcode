#include <iostream>
#include <string>
#include <vector>
#include <queue>
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

void printLevelTraversal(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        while (size--) {
            TreeNode* cur = que.front();
            que.pop();
            if (cur != nullptr) {
                cout << cur->val << ' ';
                que.push(cur->left);
                que.push(cur->right);
            } else {
                cout << "null" << ' ';
            }
        }
        cout << endl;
    }
}

int main() {
    vector<string> data = {"0", "1", "2", "null", "3", "4", "null", "null", "null", "5"};
    TreeNode* root = constructTree(data);
    printLevelTraversal(root);
}