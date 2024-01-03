#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != nullptr) {
            que.push(root);
        }
        string s = "[";
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            if (node != nullptr) {
                s.append(to_string(node->val));
                que.push(node->left);
                que.push(node->right);
            } else {
                s.append("null");
            }
            s.append(",");
        }
        if (s.size() > 1) {
            s[s.size() - 1] = ']';
        } else {
            s += "]";
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> record;
        string s;
        for (int i = 1; i < data.size(); i++) {
            if (data[i] != ',' && data[i] != ']') {
                s += data[i];
            } else {
                record.push_back(s);
                s.clear();
            }
        }
        queue<TreeNode*> que;
        TreeNode* root = nullptr;
        if (record[0] == "") {
            return root;
        } else {
            root = new TreeNode(stoi(record[0]));
            que.push(root);
        }
        int i = 1;
        while (!que.empty() && i < record.size()) {
            TreeNode* node = que.front();
            que.pop();
            if (i < record.size() && record[i] != "null") {
                node->left = new TreeNode(stoi(record[i]));
                que.push(node->left);
            }
            i++;
            if (i < record.size() && record[i] != "null") {
                node->right = new TreeNode(stoi(record[i]));
                que.push(node->right);
            }
            i++;
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return traversal(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }

    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder,
            int preorderBegin, int preorderEnd, int inorderBegin, int inorderEnd) {
        if (preorderEnd == preorderBegin) {
            return nullptr;
        }
        int rootValue = preorder[preorderBegin];
        TreeNode* root = new TreeNode(rootValue);
        if (preorderEnd - preorderBegin == 1) {
            return root;
        }
        int delimiterIndex = inorderBegin;
        for (; delimiterIndex < inorderEnd; delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) {
                break;
            }
        }
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;
        int leftPreorderBegin = preorderBegin + 1;
        int leftPreorderEnd = leftPreorderBegin + (leftInorderEnd - leftInorderBegin);
        int rightPreorderBegin = leftPreorderEnd;
        int rightPreorderEnd = preorderEnd;
        root->left = traversal(preorder, inorder, leftPreorderBegin, leftPreorderEnd, leftInorderBegin, leftInorderEnd);
        root->right = traversal(preorder, inorder, rightPreorderBegin, rightPreorderEnd, rightInorderBegin, rightInorderEnd);
        return root;
    }
};

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = Solution().buildTree(preorder, inorder);
    string tree = Codec().serialize(root);
    cout << tree << endl;
    return 0;
}