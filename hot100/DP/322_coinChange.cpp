#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 完全背包问题，amount是背包容量，coins[i]是物品，coins[i]可以重复选取
        // dp[j]: 凑成总额j所需的最少硬币数
        // dp[j] = min(dp[j], dp[j - conis[i]] + 1); 注意 j - conis[i]可能无法被组成
        // dp[0] = 0; dp[j != 0] = INT32_MAX; // INT32_MAX表示无法被组成
        // 遍历顺序任意，因为求的是最少物品数量，和顺序无关
        vector<int> dp(amount + 1, INT32_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) { // 只能从coins[i]开始才考虑取或不取
                if (dp[j - coins[i]] != INT32_MAX) { // 可以组成 j - coins[i], // INT32_MAX + 1会上溢 !!!
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        return dp[amount] == INT32_MAX ? -1 : dp[amount];
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << Solution().coinChange(coins, amount) << endl;
    return 0;
}