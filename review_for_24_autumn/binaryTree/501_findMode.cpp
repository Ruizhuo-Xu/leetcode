#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxCnt = 0;
    int cnt = 1;
    TreeNode* pre = nullptr;
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }

    void traversal(TreeNode* cur, vector<int>& res) {
        if (cur == nullptr) {
            return ;
        }
        traversal(cur->left, res);
        if (pre == nullptr) {
            pre = cur;
        } else {
            if (pre->val == cur->val) {
                cnt++;
            } else {
                cnt = 1;
            }
            pre = cur;
        }
        if (cnt > maxCnt) {
            maxCnt = cnt;
            res.clear();
            res.push_back(cur->val);
        } else if (cnt == maxCnt) {
            res.push_back(cur->val);
        }
        traversal(cur->right, res);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    Solution().findMode(root);
    return 0;
}