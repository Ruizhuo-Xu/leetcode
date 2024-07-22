#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // 第一个元素偷或不偷，分两种情况
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        int res1 = _rob(nums, 0, nums.size() - 1);
        int res2 = _rob(nums, 1, nums.size());
        return res1 > res2 ? res1 : res2;
    }

    int _rob(vector<int>& nums, int start, int end) {
        vector<int> dp(end - start);  // 左闭右开
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
        }
        return dp[dp.size() - 1];
    }
};