#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0]: 第i天持有股票的最大金额；dp[i][1]: 第i天持续不持有股票的最大金额
        // dp[i][2]: 第i天刚卖出不持有股票的最大金额； dp[i][3]: 第i天是冷冻期的最大金额
        vector<vector<int>> dp(2, vector<int>(4, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[1][0] = max(dp[0][0], max(dp[0][1] - prices[i], dp[0][3] - prices[i])); // 维持原状；持续不持有的时候买入；前一天是冷冻期买入
            dp[1][1] = max(dp[0][1], dp[0][3]); // 前一天也是持续不持有；前一天是冷冻期
            dp[1][2] = dp[0][0] + prices[i]; // 前一天持有,今天卖出
            dp[1][3] = dp[0][2]; // 前一天刚卖出,今天是冷冻期
            for (int j = 0; j < dp[0].size(); j++) {
                dp[0][j] = dp[1][j];
            }
        }
        return max(dp[1][1], max(dp[1][2], dp[1][3])); // 三种不持有股票的情况取最大值
    }
};

int main() {
    vector<int> prices = {1,2,3,0,2};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}