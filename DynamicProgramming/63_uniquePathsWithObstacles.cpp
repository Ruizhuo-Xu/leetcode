#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // dp[i][j]表示到达i,j位置所有可能的路径
        // 递推式: if (obstacleGrid == 0): dp[i][j] = dp[i][j - 1] + dp[i - 1][j]
        // else: dp[i][j] = 0; 
        // 初始化: 第一行和第一列遇到障碍后都初始为0,否则初始化为1
        // 遍历顺序: 从左往右,从上往下
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) break; // 这里要break,因为遇到障碍后后面都去不了
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 1) break; // 这里要break,因为遇到障碍后后面都去不了
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << Solution().uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}