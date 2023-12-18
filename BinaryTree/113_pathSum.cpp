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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        vector<int> path;
        traversal(root, targetSum - root->val, path, res);
        return res;
    }
    
    void traversal(TreeNode* cur, int count, vector<int>& path, vector<vector<int>>& res) {
        path.push_back(cur->val);
        if (cur->left == nullptr && cur->right == nullptr) {
            if (count == 0) {
                res.push_back(path);
            }
            return ;
        }
        if (cur->left) {
            traversal(cur->left, count - cur->left->val, path, res);
            path.pop_back();
        }
        if (cur->right) {
            traversal(cur->right, count - cur->right->val, path, res);
            path.pop_back();
        }
    }
};

int main() {
    string data = "[5,4,8,11,null,13,4,7,2,null,null,5,1]";
    int targetSum = 22;
    TreeNode* root = Codec().deserialize(data);
    vector<vector<int>> res = Solution().pathSum(root, targetSum);
    for (auto it : res) {
        for (auto i : it) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}