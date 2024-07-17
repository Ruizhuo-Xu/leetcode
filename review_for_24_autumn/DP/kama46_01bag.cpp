#include <iostream>
#include <vector>
using namespace std;

int func(vector<int>& weights, vector<int>& values, int bagWeight) {
    // dp[i][j]: 下标为0~i的物品中任取，放进容量为j的背包中，最大的价值
    // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i])  取与不取
    // dp[i][0] = 0;  容量为0，价值也为0
    // dp[0][j] = values[0] if weights[0] <= j else 0
    // 先遍历物品 or 先遍历背包容量 皆可
    vector<vector<int>> dp(weights.size(), vector<int>(bagWeight + 1, 0));
    for (int j = weights[0]; j <= bagWeight; j++) {
        dp[0][j] = values[0];
    }
    for (int i = 1; i < weights.size(); i++) {
        for (int j = 1; j <= bagWeight; j++) {
            if (j < weights[i]) dp[i][j] = dp[i - 1][j];  // 当前背包容量不足以放入物品i
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
        }
    }
    return dp[weights.size() - 1][bagWeight];
}

int _func(vector<int>& weights, vector<int>& values, int bagWeight) {
    // dp[j]: 容量为j的背包所能背的最大价值
    // dp[j] = max(dp[j], dp[j - weights[i]] + values[i]) 取和不取
    // dp[j] = 0;  初始一件物品都没放
    // 先遍历物品，再遍历背包容量，并且是从后往前遍历
    vector<int> dp(bagWeight + 1, 0);
    for (int i = 0; i < weights.size(); i++) {
        for (int j = bagWeight; j >= weights[i]; j--) {  // 保证每件物品只取1次
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    return dp[bagWeight];
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> weights(m);
    vector<int> values(m);
    for (int i = 0; i < m; i++) {
        cin >> weights[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> values[i];
    }
    int res = _func(weights, values, n);
    cout << res << endl;
}