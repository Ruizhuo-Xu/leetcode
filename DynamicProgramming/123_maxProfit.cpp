#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0]: 第i天第一次持有股票的状态下的最大金额; dp[i][1]: 第一次不持有股票状态
        // dp[i][2]: 第二次持有股票; dp[i][3]: 第二次不持有股票
        vector<vector<int>> dp(2, vector<int>(4, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = -prices[0];
        dp[0][3] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[1][0] = max(dp[0][0], -prices[i]);
            dp[1][1] = max(dp[0][1], dp[0][0] + prices[i]);
            dp[1][2] = max(dp[0][2], dp[0][1] - prices[i]);
            dp[1][3] = max(dp[0][3], dp[0][2] + prices[i]);
            for (int j = 0; j < dp[0].size(); j++) {
                dp[0][j] = dp[1][j];
            }
        }
        return dp[1][3];
    }
};

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}

