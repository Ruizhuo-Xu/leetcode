#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 设nums数组的和为sum, 其中取正号的数字的和为x
        // 则x - (sum - x) = target, x= (target + sum) / 2, 如果不能被整除，则不能构成target
        // 题目就转换为01背包问题，背包容量为x,装满背包有几种方法
        // dp[j]: 装满背包容量为j的背包有几种方法
        // dp[j] = dp[j] + dp[j - nums[i]]
        // dp[0] = 1 不取
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if ((sum + target) % 2 == 1) return 0;
        int bagSize = (sum + target) / 2;
        vector<int> dp(bagSize + 1);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};