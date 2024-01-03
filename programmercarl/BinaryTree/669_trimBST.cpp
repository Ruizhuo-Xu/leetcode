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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        while (cur) {
            if (cur->val == key) {
                // 找到要删除的结点,此时有两种情况:
                // 1.该结点的右子树不为空,此时需要将该结点的左子树插入到右子树的左下角(左子树的值全部小于右子树)
                // 2.该结点的右子树为空,此时只要删除该结点即可(pre->... = cur->left)
                // 注意pre结点也有空和非空两种情况,也需要分开处理
                TreeNode* rightNode = cur->right;
                if (rightNode) { // 右子树不为空
                    if (pre) { // pre也不为空
                        if (pre->val > key) { // 根据key的大小重新将pre的某个子树指向rightNode
                            pre->left = rightNode;
                        } else if (pre->val < key) {
                            pre->right = rightNode;
                        }
                    } else { // pre为空,说明根结点就是要删除的结点,这时直接拿右子树的根结点作为新的根结点
                        root = rightNode;
                    }
                    while (rightNode->left) { // 找到右子树的左下角
                        rightNode = rightNode->left;
                    }
                    rightNode->left = cur->left; // 将待删除结点的左子树插入到右子树的左下角
                    break;
                } else { // 右子树为空
                    if (pre) {
                        if (pre->val > key) {
                            pre->left = cur->left;
                        } else if (pre->val < key) {
                            pre->right = cur->left;
                        }
                    } else {
                        root = cur->left;
                    }
                    break;
                }
            }
            pre = cur;
            if (cur->val > key) {
                cur = cur->left;
            } else if (cur->val < key) {
                cur = cur->right;
            }
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // 函数的作用是寻找符合范围的结点返回
        if (root == nullptr) return root;
        if (root->val < low) { // 不符合规定的范围情况1:小于最小值,需要遍历右子树的值寻找符合条件的结点
            TreeNode* right = trimBST(root->right, low, high);
            return right;
        }
        if (root->val > high) { // 情况2:大于最大值,需要遍历左子树的值寻找符合条件的结点
            TreeNode* left = trimBST(root->left, low, high);
            return left;
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

int main() {
    string data = "[3,0,4,null,2,null,null,1]";
    TreeNode* root = Codec().deserialize(data);
    int low = 1, high = 3;
    string res = Codec().serialize(Solution().trimBST(root, low, high));
    cout << res << endl;
    return 0;
}