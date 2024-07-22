#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i]: 以nums[i]结尾的递增子序列的最长长度
        // for (0 : i - 1) if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1)
        // dp[i] = 1;
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                res = max(dp[i], res);
            }
        }
        return res;
    }
};