#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        // 分别遍历左子树和右子树,比较左右子树是否互为翻转
        return compare(root->left, root->right);
    }

    bool compare(TreeNode* left, TreeNode* right) {
        // left和right都有空和非空两种情况,总共有四种组合可能
        if (left == nullptr && right != nullptr) return false;
        else if(left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right == nullptr) return true;  // 这个条件说明需要回溯
        else if (left->val != right->val) return false;
        // 左子树按照左右中的顺序遍历,右子树按照右左中的顺序遍历
        return compare(left->left, right->right) && compare(left->right, right->left);
    }
};

class Solution_ {
public:
    bool isSymmetric(TreeNode* root) {
        // 迭代法,将一棵树分成左右子树同时层序遍历
        queue<TreeNode*> que;
        if (root == nullptr) return true;
        else {
            que.push(root->left);
            que.push(root->right);
        }
        while (!que.empty()) {
            TreeNode* node1 = que.front();
            que.pop();
            TreeNode* node2 = que.front();
            que.pop();
            if (node1 == nullptr && node2 == nullptr) {
                continue;
            }
            if (!node1 || !node2 || (node1->val != node2->val)) { // 某个结点为空,或两个结点的值不相等
                return false;
            }
            que.push(node1->left);
            que.push(node2->right);
            que.push(node1->right);
            que.push(node2->left);
        }
        return true;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(5);
    root->left->left->right = new TreeNode(6);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    root->right->right->left = new TreeNode(6);
    root->right->right->right = new TreeNode(5);
    cout << Solution_().isSymmetric(root) << endl;
    return 0;
}