#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstdint>
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
    TreeNode* pre = nullptr;
    vector<int> res;
    int maxCount = 0;
    int count = 0;
    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return res;
    }
    
    void traversal(TreeNode* cur) {
        if (cur == nullptr) return ;
        traversal(cur->left);
        if (pre == nullptr) { // 遍历到的第一个结点
            count = 1;
        } else if (pre->val == cur->val) {
            count += 1;
        } else if (pre->val != cur->val) {
            count = 1;
        }
        pre = cur;
        if (count > maxCount) {
            maxCount = count;
            res.clear(); // 清空之前记录的结果
            res.push_back(cur->val);
        } else if (count == maxCount) {
            res.push_back(cur->val);
        }
        traversal(cur->right);
    }
};

int main() {
    string data = "[1,null,2,2]";
    TreeNode* root = Codec().deserialize(data);
    vector<int> res = Solution().findMode(root);
    for (int it : res) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}