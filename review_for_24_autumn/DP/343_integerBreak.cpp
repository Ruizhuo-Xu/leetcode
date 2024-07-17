#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        // dp[i]: 将i拆分后的最大乘积
        // dp[i] = max(dp[i], mad(dp[i - j]* j (i - j) * j))
        // dp[2] = 1;
        // i从3遍历到,j从1遍历到i/2 (因为是正整数，所以从1开始，超过i/2之后就重复了)
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[i], max(dp[i - j], i - j) * j);  // (i - j) * j表示拆分为2个正整数的情况，dp[i - j] * j表示拆分为>2个正整数的情况
            }
        }
        return dp[n];
    }
};