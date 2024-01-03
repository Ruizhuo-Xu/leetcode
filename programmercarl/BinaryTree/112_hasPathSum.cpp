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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        int sum = root->val;
        return traversal(root, targetSum, sum);
    }

    bool traversal(TreeNode* cur, int targetsum, int sum) {
        // sum表示根结点到当前结点路径的和
        if (cur->left == nullptr && cur->right == nullptr) {
            if (sum == targetsum) return true;  // 根结点到叶子结点的和等于目标值
            return false;
        }
        if (cur->left) {
            sum += cur->left->val;
            bool left = traversal(cur->left, targetsum, sum);
            sum -= cur->left->val;
            if (left) {
                return true;
            }
        }
        if (cur->right) {
            sum += cur->right->val;
            bool right = traversal(cur->right, targetsum, sum);
            sum -= cur->right->val;
            if (right) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    // string data = "[5,4,8,11,null,13,4,7,2,null,null,null,1]";
    string data = "[1,2,3]";
    TreeNode* root = Codec().deserialize(data);
    cout << Solution().hasPathSum(root, 22) << endl;
    return 0;
}