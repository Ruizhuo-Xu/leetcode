#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths_(int m, int n) {
        // dp[i][j]: 从起点到i,j总共有多少条路径
        // dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        // 第一行和第一列初始化为1
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePaths(int m, int n) {
        // 滚动数组优化
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

int main() {
    int m = 3;
    int n = 7;
    cout << Solution().uniquePaths(m, n) << endl;
    return 0;
}