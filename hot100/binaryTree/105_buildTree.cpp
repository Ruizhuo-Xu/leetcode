#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printLevelOrderTraversal(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        while (size--) {
            TreeNode* cur = que.front();
            que.pop();
            if (cur != nullptr) {
                cout << cur->val << ' ';
                que.push(cur->left);
                que.push(cur->right);
            } else {
                cout << "null" << ' ';
            }
        }
        cout << endl;
    }
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return traversal(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder,
                        int preBegin, int preEnd, int inBegin, int inEnd) {
        if (preEnd < preBegin) return nullptr;
        int rootVal = preorder[preBegin];
        TreeNode* root = new TreeNode(rootVal);
        int i = 0;
        for (; i < inorder.size(); i++) {
            if (inorder[i] == rootVal) {
                break;
            }
        }
        int leftInBegin = inBegin;
        int leftInEnd = i - 1;
        int leftPreBegin = preBegin + 1;
        int leftPreEnd = leftPreBegin + (leftInEnd - leftInBegin);
        int rightInBegin = i + 1;
        int rightInEnd = inEnd;
        int rightPreBegin = leftPreEnd + 1;
        int rightPreEnd = rightPreBegin + (rightInEnd - rightInBegin);
        root->left = traversal(preorder, inorder, leftPreBegin, leftPreEnd, leftInBegin, leftInEnd);
        root->right = traversal(preorder, inorder, rightPreBegin, rightPreEnd, rightInBegin, rightInEnd);
        return root;
    }
};

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = Solution().buildTree(preorder, inorder);
    printLevelOrderTraversal(root);
    return 0;
}