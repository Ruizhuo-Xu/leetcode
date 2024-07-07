#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int end = nums.size() - 1;
        return traversal(nums, 0, end);
    }

    TreeNode* traversal(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        if (start == end) {
            return new TreeNode(nums[start]);
        }
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traversal(nums, start, mid - 1);
        root->right = traversal(nums, mid + 1, end);
        return root;
    }
};