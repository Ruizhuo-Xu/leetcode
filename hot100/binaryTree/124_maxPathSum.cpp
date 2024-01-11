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
        // 局部最优: 遍历二叉树，求以当前节点为根节点，且路径经过当前节点的最大路径和
        // 全局最优: 比较每个节点的最大路径和，得到全局的最大路径和
        traversal(root);
        return res;
    }

    int traversal(TreeNode* root) {
        // 思路类似543_求二叉树最大直径
        if (root == nullptr) return 0;
        int left = traversal(root->left);
        int right = traversal(root->right);
        int sum = root->val;
        // 要特别注意和0的比较,因为求的是最大值，加上负数一定会使结果变小
        if (left > 0) {
            sum += left;
        }
        if (right > 0) {
            sum += right;
        }
        res = max({res, sum}); // 考虑当前节点为根结点且经过当前节点的最大路径和: 当前节点 + 左右子树到当前节点最大的路径和
        return max({left, right, 0}) + root->val; // 经过当前节点往上，最大的路径和;
    }
};

int main() {
    vector<string> data = {"-10","9","20","null","null","15","7"};
    TreeNode* root = constructTree(data);
    cout << Solution().maxPathSum(root) << endl;
    return 0;
}