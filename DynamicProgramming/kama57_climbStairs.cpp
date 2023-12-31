#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n, int m) {
    // 完全背包，排列问题
    // 台阶数n表示背包容量, 每次最多爬m阶台阶等于(1-m)件物品
    // dp[i]：爬到有i个台阶的楼顶，有dp[i]种方法
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int j = 0; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (j - i >= 0) {
                dp[j] = dp[j] + dp[j - i];
            }
        }
    }
    return dp[n];
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << climbStairs(n, m) << endl;
    return 0;
}
