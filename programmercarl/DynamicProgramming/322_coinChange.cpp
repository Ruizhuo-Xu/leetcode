#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[j]:组成金额j所需的最小硬币数
        // 递推式: dp[j] = min(dp[j], dp[j - coins[i]] + 1)
        // 初始化: dp[0] = 0; dp[j != 0] = INT_MAX
        // 遍历顺序: 先遍历物品后遍历背包或反之都可
        vector<int> dp(amount + 1, INT32_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (dp[j - coins[i]] != INT32_MAX) { // 如果dp[j - coins[i]]是初始值说明无法组成当前金额,跳过
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
            // for (int it : dp) {
            //     cout << it << ' ';
            // }
            // cout << endl;
        }
        return dp[amount] != INT32_MAX ? dp[amount] : -1;
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << Solution().coinChange(coins, amount) << endl;
    return 0;
}