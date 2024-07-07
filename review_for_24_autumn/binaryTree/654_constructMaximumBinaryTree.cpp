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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode* build(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        if (start == end) {
            return new TreeNode(nums[start]);
        }
        int rootIdx = -1;
        int maxVal = INT32_MIN;
        for (int i = start; i <= end; i++) {
            if (nums[i] > maxVal) {
                rootIdx = i;
                maxVal = nums[i];
            }
        }
        TreeNode* root = new TreeNode(maxVal);
        root->left = build(nums, start, rootIdx - 1);
        root->right = build(nums, rootIdx + 1, end);
        return root;
    }
};

int main() {
    vector<int> nums = {3,2,1,6,0,5};
    TreeNode* root = Solution().constructMaximumBinaryTree(nums);
    cout << root->val << endl;
    return 0;
}