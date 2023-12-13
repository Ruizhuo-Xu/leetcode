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
    vector<int> preorderTraversal_(TreeNode* root) {
        // 递归法
        vector<int> res;
        traversal(root, res);
        return res;
    }
    
    void traversal(TreeNode* cur, vector<int>& res) {
        if (cur == nullptr) {
            return ;
        }
        res.push_back(cur->val);
        traversal(cur->left, res);
        traversal(cur->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        // 迭代法
        vector<int> res;
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            res.push_back(node->val);
            st.pop();
            // 栈先入后出,所以right先入,left后入,下一次迭代left先出,满足中左右的遍历顺序
            if (node->right != nullptr) st.push(node->right);
            if (node->left != nullptr) st.push(node->left);
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
    vector<int> res = Solution().preorderTraversal(root);
    for (auto it = res.begin(); it != res.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}