#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i]: 在下标为0-i的房屋中偷盗所能取得的最大金额
        // dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
        // 由递推式可知现需要初始化dp[0], dp[1]
        // dp[0] = nums[0], dp[1] = max(dp[0], dp[1])
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};