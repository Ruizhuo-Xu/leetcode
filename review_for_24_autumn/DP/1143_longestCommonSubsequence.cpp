#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i][j]: 下标为0-i-1的text1子串和下标为0-j-1的text2子串的最长公共子序列
        // if text1[i - 1] == text2[j - 1] dp[i][j] = dp[i - 1][j - 1] + 1 else dp[i][j] = max(dp[i - 1][j], dp[j][j - 1])
        // dp[i][0] = 0; dp[0][j] = 0
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};