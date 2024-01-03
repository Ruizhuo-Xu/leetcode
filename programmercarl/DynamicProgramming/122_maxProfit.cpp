#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit_(vector<int>& prices) {
        // 贪心
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - prices[i - 1] > 0) {
                profit += (prices[i] - prices[i - 1]);
            }
        }
        return profit;
    }
    
    int maxProfit(vector<int>& prices) {
        // 动态规划: dp[i][0]表示第i天持有股票拥有的最大金额, dp[i][1]表示第i天不持有股票拥有的最大金额
        // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);(因为可以多次买卖,所以买入股票时的资金不一定是0)
        // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
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

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}