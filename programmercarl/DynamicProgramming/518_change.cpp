#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[j]表示凑成总金额j的货币组合数为dp[j]
        // 递推公式: dp[j] = dp[j] + dp[j - coins[i]]; 不取当前货币组成j的组合数+取当前货币(可以重复)组成j的组合数
        // 初始化: dp[0] = 1
        vector<int> dp(amount + 1, 0);
        dp[0] = 1; // 什么都没取的时候总和就为0,所以初始化为1
        for (int i = 0; i < coins.size(); i++) { // 先遍历物品数后遍历背包容量求的是组合数
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
            // for (int it : dp) {
            //     cout << it << ' ';
            // }
            // cout << endl;
        }
        return dp[amount];
    }
};

int main() {
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    cout << Solution().change(amount, coins) << endl;
    return 0;
}