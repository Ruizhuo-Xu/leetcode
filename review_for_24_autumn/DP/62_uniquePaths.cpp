#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp[i][j]: 到达i,j位置共有多少条不同路径
        // dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        // dp[0][j] = 1; dp[0][i] = 1;
        // 从i=1, j= 1开始遍历
        vector<int> dp(n, 1);  // 使用滚动数组降低空间复杂度
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};