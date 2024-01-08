#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

TreeNode* constructTree(vector<string>& data) {
    if (data.size() == 0) return nullptr;
    vector<TreeNode*> vecTree(data.size(), nullptr);
    for (int i = 0; i < data.size(); i++) {
        // 先创建节点
        if (data[i] != "null") {
            vecTree[i] = new TreeNode(stoi(data[i]));
        }
    }
    for (int i = 0; i * 2 + 1 < vecTree.size(); i++) {
        // 分别给左右孩子赋值
        if (vecTree[i] != nullptr) {
            vecTree[i]->left = vecTree[2 * i + 1];
            if (2 * i + 2 < vecTree.size()) {
                vecTree[i]->right = vecTree[2 * i + 2];
            }
        }
    }
    return vecTree[0];
}

class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        traversal(root);
        return res;
    }

    void traversal(TreeNode* cur) {
        if (cur == nullptr) return ;
        traversal(cur->left);
        res.push_back(cur->val);
        traversal(cur->right);
    }
};

int main() {
    vector<string> data = {"1","null", "2","null", "null", "3", "null"};
    TreeNode* root = constructTree(data);
    vector<int> res = Solution().inorderTraversal(root);
    for (int num : res) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}



