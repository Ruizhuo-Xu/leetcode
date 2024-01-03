#include <iostream>
#include <vector>
#include <queue>
#include <string>
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
    bool isBalanced(TreeNode* root) {
        if (getHeight(root) == -1) {
            return false;
        }
        return true;
    }
    
    int getHeight (TreeNode* cur) {
        if (cur == nullptr) {
            return 0;
        }
        int leftHeight = getHeight(cur->left);
        if (leftHeight == -1) return -1;
        int rightHeight = getHeight(cur->right);
        if (rightHeight == -1) return -1;
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    // string data = "[3,9,20,null,null,15,7]";
    string data = "[1,2,2,3,3,null,null,4,4,null,null]";
    TreeNode* root = Codec().deserialize(data);
    string ecData = Codec().serialize(root);
    cout << ecData << endl;
    cout << Solution().isBalanced(root) << endl;
    return 0;
}