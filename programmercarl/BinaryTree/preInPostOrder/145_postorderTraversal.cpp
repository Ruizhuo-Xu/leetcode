#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
    vector<int> postorderTraversal_(TreeNode* root) {
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
        traversal(cur->right, res);
        res.push_back(cur->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        // 迭代法
        vector<int> res;
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            res.push_back(node->val);
            st.pop();
            if (node->left != nullptr) st.push(node->left);
            if (node->right != nullptr) st.push(node->right);
        }
        // 上面的迭代实现中右左的遍历,翻转一下结果输出就是左右中
        reverse(res.begin(), res.end());
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
    vector<int> res = Solution().postorderTraversal(root);
    for (auto it = res.begin(); it != res.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}