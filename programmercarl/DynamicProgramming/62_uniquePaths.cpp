#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp[i][j]表示到达i,j位置所有可能的路径
        // 递推式: dp[i][j] = dp[i][j - 1] + dp[i - 1][j]
        // 初始化: 第一行和第一列都初始化为1
        // 遍历顺序: 从左往右,从上往下
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    cout << Solution().uniquePaths(3, 3) << endl;
    return 0;
}