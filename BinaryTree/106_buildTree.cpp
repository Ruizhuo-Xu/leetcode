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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return traversal(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }

    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder,
                        int inorderBegin, int inorderEnd, int postorderBegin, int postorderEnd) {
        // 所有的索引(begin, end)均符合左闭右开原则
        // 将中序数组和后序数组分为左中序、右中序和左后序、右后序
        // 根据中序和后序数组递归建树
        if ((postorderEnd - postorderBegin) == 0) {
            return nullptr;
        }
        int rootValue = postorder[postorderEnd - 1]; // 从后序遍历数组取出根结点的值
        TreeNode* root = new TreeNode(rootValue);
        if ((postorderEnd - postorderBegin) == 1) { // 叶子结点,递归返回
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
        int leftPostorderBegin = postorderBegin;
        int leftPostorderEnd = postorderBegin + (leftInorderEnd - leftInorderBegin);
        int rightPostorderBegin = leftPostorderEnd;
        int rightPostorderEnd = postorderEnd - 1; // 排除最后一个元素，已经作为节点了
        root->left = traversal(inorder, postorder, leftInorderBegin, leftInorderEnd, leftPostorderBegin, leftPostorderEnd);
        root->right = traversal(inorder, postorder, rightInorderBegin, rightInorderEnd, rightPostorderBegin, rightPostorderEnd);
        return root;
    }
};

int main() {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* root = Solution().buildTree(inorder, postorder);
    string tree = Codec().serialize(root);
    cout << tree << endl;
    return 0;
}