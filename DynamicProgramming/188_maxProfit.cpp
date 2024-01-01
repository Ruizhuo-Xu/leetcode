#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(2*k + 1, 0));
        dp[0][0] = 0;
        for (int i = 1; i < dp[0].size(); i++) {
            if (i % 2) { // 持有状态初始化,不持有状态初始化为0
                dp[0][i] = -prices[0];
            }
        }
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                if (j % 2) { // 奇数表示持有状态
                    dp[1][j] = max(dp[0][j], dp[0][j - 1] - prices[i]);
                } else { // 偶数表示不持有状态
                    dp[1][j] = max(dp[0][j], dp[0][j - 1] + prices[i]);
                }
                dp[0][j] = dp[1][j];
            }
        }
        return dp[1][2*k];
    }
};

int main() {
    vector<int> prices = {3,2,6,5,0,3};
    cout << Solution().maxProfit(2, prices) << endl;
    return 0;
}