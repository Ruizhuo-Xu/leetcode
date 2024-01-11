#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == nullptr) return root; // 当前节点是所求节点或当前节点为空就返回；
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr) { // 所求的两个节点分别在当前节点的左右子树中
            return root;
        }
        if (left == nullptr && right != nullptr) { // 所求的两个节点的某一个在当前节点的其中一个子树中
            return right;
        }
        if (left != nullptr && right == nullptr) {
            return left;
        }
        return nullptr;
    }
};

int main() {
    vector<string> data = {"3","5","1","6","2","0","8","null","null","7","4"};
    TreeNode* root = constructTree(data);
    TreeNode* p = root->left;
    TreeNode* q = root->right;
    TreeNode* res = Solution().lowestCommonAncestor(root, p, q);
    cout << res->val << endl;
    return 0;
}