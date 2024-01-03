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

class Solution_ {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path;
        vector<vector<TreeNode*>> paths;
        traversal(root, p, q, path, paths);
        int i = 0;
        int len = min(paths[0].size(), paths[1].size());
        for (; i < len; i++) {
            if (paths[0][i] != paths[1][i]) { // 找到最后一个相同的结点,即两个目标结点共同的最近的祖先
                break;
            }
        }
        return paths[0][i - 1];
    }

    void traversal(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>& path, vector<vector<TreeNode*>>& paths) {
        // path记录根结点到当前结点的路径
        // paths记录根结点到两个目标结点的路径
        path.push_back(root);
        if (root == p || root == q) { // 找到某个目标结点,记录其路径
            paths.push_back(path);
        }
        if (paths.size() == 2) { // 如果目标结点全部找到,返回
            return ;
        }
        // 前序遍历
        if (root->left == nullptr && root->right == nullptr) {
            return ;
        }
        if (root->left) {
            traversal(root->left, p, q, path, paths);
            path.pop_back();
        }
        if (root->right) {
            traversal(root->right, p, q, path, paths);
            path.pop_back();
        }
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 后序遍历
        if (root == p || root == q || root == nullptr) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr) { // p,q包含在root结点的左右子树中
            return root;
        }
        if (left == nullptr && right != nullptr) {
            // 两种情况: 1.p,q都包含在root结点的右子树中，此时返回right结点作为公共祖先
            // 2.一个结点在根结点的右子树中,此时返回right说明找到了这个结点
            return right;
        }
        if (left != nullptr && right == nullptr) {
            return left;
        }
        return nullptr;
    }
};

int main() {
    string data = "[3,5,1,6,2,0,8,null,null,7,4]";
    TreeNode* root = Codec().deserialize(data);
    TreeNode* p = root->left;
    TreeNode* q = root->left->right;
    string res = Codec().serialize(Solution().lowestCommonAncestor(root, p, q));
    cout << res << endl;
    return 0;
}