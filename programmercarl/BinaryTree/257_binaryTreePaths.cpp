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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) {
            return res;
        }
        vector<int> path;
        traversal(root, path, res);
        return res;
    }

    void traversal(TreeNode* cur, vector<int>& path, vector<string>& res) {
        path.push_back(cur->val);
        if (cur->left == nullptr && cur->right == nullptr) { // 叶子结点,将当前记录的path转换成题目要求的格式并记录
            string s;
            for (int i = 0; i < path.size() - 1; i++) {
                s.append(to_string(path[i]) + "->");
            }
            s.append(to_string(path[path.size() - 1]));
            res.push_back(s);
            return ;
        }
        if (cur->left != nullptr) {
            traversal(cur->left, path, res); // 递归
            path.pop_back(); // 回溯
        }
        if (cur->right != nullptr) {
            traversal(cur->right, path, res);
            path.pop_back();
        }
    }
};

int main() {
    string data = "[1,2,3,null,5]";
    TreeNode* root = Codec().deserialize(data);
    vector<string> res = Solution().binaryTreePaths(root);
    for (string it : res) {
        cout << it << endl;
    }
    return 0;
}