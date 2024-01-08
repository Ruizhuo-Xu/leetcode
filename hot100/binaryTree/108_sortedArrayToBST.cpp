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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = traversal(nums, 0, nums.size() - 1);
        return root;
    }

    TreeNode* traversal(vector<int>& nums, int begin, int end) {
        if (begin > end) return nullptr;
        int mid = begin + (end - begin) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traversal(nums, begin, mid - 1);
        root->right = traversal(nums, mid + 1, end);
        return root;
    }
};

void printTree(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != nullptr) que.push(root);
    vector<string> res;
    while (!que.empty()) {
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
    for (string s : res) {
        cout << s << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> nums = {-10,-3,0,5,9};
    TreeNode* root = Solution().sortedArrayToBST(nums);
    printTree(root);
    return 0;
}