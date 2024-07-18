#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 2维01背包问题
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str : strs) {
            int zeroNum = 0;
            int oneNum = 0;
            for (char c : str) {
                if (c == '0') zeroNum++;
                else oneNum++;
            }
            for (int j = m; j >= zeroNum; j--) {
                for (int k = n; k >= oneNum; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - zeroNum][k - oneNum] + 1);  // 取了要+1
                }
            }
        }
        return dp[m][n];
    }
};
