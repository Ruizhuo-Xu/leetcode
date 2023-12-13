#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            // 交换左右结点
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;

            if (node->left != nullptr) que.push(node->left);
            if (node->right != nullptr) que.push(node->right);
        }
        return root;
    }
};

void levelOrderTraversal(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != nullptr) que.push(root);
    vector<int> res;
    while (!que.empty()) {
        TreeNode* node = que.front();
        que.pop();
        res.push_back(node->val);
        if (node->left != nullptr) que.push(node->left);
        if (node->right != nullptr) que.push(node->right);
    }
    for (int it : res) {
        cout << it << ' ';
    }
    cout << endl;
    return ;
}


int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    levelOrderTraversal(root);
    root = Solution().invertTree(root);
    cout << "--------" << endl;
    levelOrderTraversal(root);
    return 0;
}