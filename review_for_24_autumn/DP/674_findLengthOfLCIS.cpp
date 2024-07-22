#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // dp[i]: 以i结尾的最长连续子序列的长度
        // if (nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
        // dp[i] = 1
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
        int res  = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};