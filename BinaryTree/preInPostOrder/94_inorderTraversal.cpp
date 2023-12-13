#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal_(TreeNode* root) {
        // 递归法
        vector<int> res;
        traversal(root, res);
        return res;
    }
    
    void traversal(TreeNode* cur, vector<int>& res) {
        if (cur == nullptr) {
            return ;
        }
        traversal(cur->left, res);
        res.push_back(cur->val);
        traversal(cur->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        // 迭代法
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (!st.empty() || cur != nullptr) {
            if (cur != nullptr) {
                // 栈里存放当前遍历过的非空结点
                st.push(cur);
                cur = cur->left; // 左
            } else {
                // 当前结点为空则回溯上一个结点
                TreeNode* node = st.top();
                res.push_back(node->val); // 中
                cur = node->right; // 右
                // 左中右遍历完成后删除该结点
                st.pop();
            }
        }
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);
    vector<int> res = Solution().inorderTraversal(root);
    for (auto it = res.begin(); it != res.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}