#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // dp[j]: 容量为j的背包，从下标为0-i的物品中任取放入，能背的最大重量
        // dp[j] = max(dp[j], dp[j - nums[i]] + nums[i])
        // dp[j] = 0;
        // 先遍历物品，再遍历背包容量,从后往前遍历(01背包问题，每个数字只能使用1次)
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[target] == target;
    }
};