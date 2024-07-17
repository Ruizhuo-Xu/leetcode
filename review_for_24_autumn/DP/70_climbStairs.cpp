#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // dp[i]: 爬到第i阶台阶的不同方法数
        // dp[i] = dp[i - 1] + dp[i - 2]
        // dp[0] = 1 dp[1] = 2
        // 从3-n遍历
        if (n <= 2) return n;
        vector<int> dp(2);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 3; i <= n; i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};