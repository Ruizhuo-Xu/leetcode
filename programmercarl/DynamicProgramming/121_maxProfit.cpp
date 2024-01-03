#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit_(vector<int>& prices) {
        // 贪心,第i天买入股票,第j天卖出的盈利: prices[j] - prices[i]可以拆分为:
        // (prices[i + 1] - prices[i]) + (prices[i + 2] - prices[i + 1]) + ... + (prices[j] - prices[j - 1])
        // 所以可以计算一个profits数组,求profits数组最大的子数组和就是所求的最大利润
        int res = 0;
        int sum = 0;
        for (int i = 1; i < prices.size(); i++) {
            sum += prices[i] - prices[i - 1];
            if (sum < 0) sum = 0;
            res = sum > res ? sum : res;
        }
        return res;
    }

    int _maxProfit(vector<int>& prices) {
        // 动态规划: dp[i][0]表示第i天持有股票拥有的最大金额, dp[i][1]表示第i天不持有股票拥有的最大金额
        // dp[i][0] = max(dp[i - 1][0], -prices[i]); dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        // 因为股票只能买卖一次,所以是-prices[i](初始资金为0)
        // dp[0][0] = -prices[0]; dp[0][1] = 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }

    int maxProfit(vector<int>& prices) {
        // 精简版
        vector<vector<int>> dp(2, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[1][0] = max(dp[0][0], -prices[i]);
            dp[1][1] = max(dp[0][1], dp[0][0] + prices[i]);
            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
        }
        return dp[1][1];
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}