#include <iostream>
#include <queue>
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
    int sum = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        sum += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == targetSum) {
                return true;
            }
            return false;
        }
        if (root->left != nullptr) {
            bool left = hasPathSum(root->left, targetSum);
            if (left) {
                return true;
            }
            sum -= root->left->val;
        }
        if (root->right != nullptr) {
            bool right = hasPathSum(root->right, targetSum);
            if (right) {
                return true;
            }
            sum -= root->right->val;
        }
        // return left || right; // 局部变量，不能这样用
        return false;
    }

};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << Solution().hasPathSum(root, 5) << endl;
    return 0;
}