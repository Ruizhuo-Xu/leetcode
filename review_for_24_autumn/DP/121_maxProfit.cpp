#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 假设第i天买入股票，第j天卖出，那么profit = prices[j] - prices[i]
        // 可以展开为: profit = (prices[j] - prices[j - 1]) + (prices[j - 1] - prices[j - 2]) + ... + (prices[i + 1] - prices[i])
        // 因此题目可以转换为求数组(prices[i + 1] - price[i])中最大连续子数组的和(贪心)
        int sum = 0;
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            sum += (prices[i] - prices[i - 1]);
            if (sum < 0) {
                sum = 0;
            }
            res = max(res, sum);
        }
        return res;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0]: 第i天持有股票时的最大现金；dp[i][1]: 第i天没持有股票时的最大现金
        // dp[i][0] = max(dp[i - 1][0], -prices[i]) 继续持有或今天买入
        // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]) 继续不持有或今天卖出
        vector<vector<int>> dp(2, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            int num1 = max(dp[i - 1][0], -prices[i]);
            int num2 = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
            dp[1][0] = num1;
            dp[1][1] = num2;
        }
        return dp[1][1];
    }
};