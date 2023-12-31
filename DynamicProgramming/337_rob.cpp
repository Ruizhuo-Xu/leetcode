#include <iostream>
#include <queue>
#include <vector>
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
    int rob(TreeNode* root) {
        pair<int, int> res = traversal(root);
        return res.first;
    }
    
    pair<int, int> traversal(TreeNode* cur) {
        // pair<int, int> 第一个数字表示考虑当前结点及其子结点的房屋可以偷盗的最大金额
        // 第二个数字表示考虑当前节点的前一个结点及其子节点的房屋可以偷盗的最大金额
        if (cur == nullptr) return pair<int, int>(0, 0);
        pair<int, int> left = traversal(cur->left);
        pair<int, int> right = traversal(cur->right);
        // 根据左右孩子返回的值更新当前结点的最大金额
        // 情况1: 不偷当前节点， 则只考虑孩子节点
        // 情况2: 偷当前节点, 则只考虑孩子节点的孩子节点
        int num1 = max(left.first + right.first, left.second + right.second + cur->val);
        // 记录左右孩子最大金额的和
        int num2 = left.first + right.first;
        return pair<int, int>(num1, num2);
    }
};

int main() {
    string data = "[3,4,5,1,3,null,1]";
    cout << Solution().rob(Codec().deserialize(data)) << endl;;
    return 0;
}