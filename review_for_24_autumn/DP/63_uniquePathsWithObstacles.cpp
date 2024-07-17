#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // dp[i][j]: 到达第i行第j列的位置共有多少条不同的路径
        // dp[i][j] = dp[i-1][j] + dp[i][j-1] if obs[i][j] == 0 else 0
        // 遍历第一行第一列，一旦遇到障碍，后续都为0，否则为1
        // 从i=1,j=1开始遍历
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 1) {
                break;
            }
            dp[j] = 1;
        }
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                dp[0] = 0;
            }
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[j] = dp[j] + dp[j - 1];
                } else {
                    dp[j] = 0;
                }
            }
        }
        return dp[n - 1];
    }
};