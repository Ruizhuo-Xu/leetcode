#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int res = 0;
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> mp;
        mp[0] = 1;
        traversal(root, targetSum, 0, mp);
        return res;
    }

    void traversal(TreeNode* root, int targetSum, long sum, unordered_map<long, int>& preSum) {
        if (root == nullptr) {
            return ;
        }
        sum += root->val;
        if (preSum.find(sum - targetSum) != preSum.end()) {
            res += preSum[sum - targetSum];
        }
        preSum[sum]++;
        traversal(root->left, targetSum, sum, preSum);
        traversal(root->right, targetSum, sum, preSum);
        preSum[sum]--;
    }
};