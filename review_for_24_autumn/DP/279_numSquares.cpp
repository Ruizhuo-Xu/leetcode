#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            int val = i * i;
            for (int j = val; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - val] + 1);
            }
        }
        return dp[n];
    }
};