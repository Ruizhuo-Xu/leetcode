#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        // dp[i]第i项斐波那契数
        // dp[i] = dp[i - 2] + dp[i - 1]
        // dp[0] = 0 dp[1] = 1
        // 从2-n遍历
        if (n < 2) return n;
        vector<int> dp(2);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};