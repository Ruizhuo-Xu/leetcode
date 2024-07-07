#include <iostream>
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == key) {
            // 删除节点的三种情况: 1.左空右空，直接返回空 2.左空右不空,直接返回右 3.左不空右空,直接返回左 4.左右都不空
            if (root->left == nullptr && root->right == nullptr) {
                return nullptr;
            } else if (root->left == nullptr) {
                return root->right;
            } else if (root->right == nullptr) {
                return root->left;
            } else { // 这里有两种调整策略：1.把左子树的根节点替换删除节点，把右子树接到左子树的最右边节点后面；2.把右子树的根节点替换删除节点，把左子树街道右子树最左边的节点后面
                TreeNode* cur = root->left;
                while (cur->right != nullptr) {
                    cur = cur->right;
                }
                cur->right = root->right;
                return root->left;
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};