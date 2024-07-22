#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - prices[i - 1];
            if (profit > 0) {
                res += profit;
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0]: 第i天持有股票状态下拥有的最大现金; dp[i][1]: 第i天不持有股票状态下由于的最大现金
        // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i])  前一天就持有、前一天不持有，今天买入
        // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])  前一天就不持有、前一天持有，今天卖出
        vector<vector<int>> dp(2, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[1][0] = max(dp[0][0], dp[0][1] - prices[i]);
            dp[1][1] = max(dp[0][1], dp[0][0] + prices[i]);
            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
        }
        return dp[1][1];
    }
};