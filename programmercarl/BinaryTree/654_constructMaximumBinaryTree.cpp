#include <iostream>
#include <queue>
#include <string>
#include <vector>
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }

    TreeNode* traversal(vector<int>& nums, int begin, int end) {
        // 区间为左闭右开 [begin, end)
        if (begin == end) return nullptr; // 数组为空返回空指针
        int delimiterIndex = -1;
        int maxValue = INT32_MIN;
        for (int i = begin; i < end; i++) { // 查找最大元素的值及其下标
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                delimiterIndex = i;
            }
        }
        TreeNode* root = new TreeNode(maxValue);
        if (end - begin == 1) { // 叶子结点,直接返回
            return root;
        }
        int leftBegin = begin;
        int leftEnd = delimiterIndex;
        int rightBegin = delimiterIndex + 1;
        int rightEnd = end;
        root->left = traversal(nums, leftBegin, leftEnd);
        root->right= traversal(nums, rightBegin, rightEnd);
        return root;
    }
};

int main() {
    vector<int> nums = {3,2,1,6,0,5};
    TreeNode* root = Solution().constructMaximumBinaryTree(nums);
    string tree = Codec().serialize(root);
    cout << tree << endl;
    return 0;
}