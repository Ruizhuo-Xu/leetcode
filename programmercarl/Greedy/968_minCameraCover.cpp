#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    int minCameraCover(TreeNode* root) {
        // 局部最优：让叶子节点的父节点安摄像头，所用摄像头最少，整体最优：全部摄像头数量所用最少
        // 大体思路就是从低到上，先给叶子节点父节点放个摄像头，然后隔两个节点放一个摄像头，直至到二叉树头结点
        int res = 0;
        if (traversal(root, res) == 0) {
            res++; // 如果根结点没有被覆盖,则在根结点上装上摄像头
        }
        return res;
    }

    int traversal(TreeNode* cur, int& res) {
        // 0: 无覆盖 1: 有摄像头 2: 有覆盖
        if (cur == nullptr) {
            return 2;
        }
        int left = traversal(cur->left, res);
        int right = traversal(cur->right, res);
        // left和right都可以去0，1，2;总共9种可能,可以分下面三种情况讨论
        if (left == 2 && right == 2) {
            return 0; // 左右孩子都有覆盖,则当前结点状态为无覆盖,需要在当前结点的父节点上安装摄像头
        }
        if (left == 0 || right == 0) {
            res++;
            return 1; // 左右孩子至少有一个没有被覆盖,则在当前结点装上摄像头
        }
        if (left == 1 || right == 1) {
            return 2; // 左右孩子至少有一个安装了摄像头,则当前结点处于被覆盖状态
        }
        return -1;
    }
};

int main() {
    string data = "[0,0,null,0,null,0,null,null,0]";
    TreeNode* root = Codec().deserialize(data);
    cout << Solution().minCameraCover(root) << endl;;
    return 0;
}