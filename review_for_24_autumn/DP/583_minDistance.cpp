#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j]: 以i-1,j-1结尾...最少的删除步数
        // if word1[i - 1] == word2[j -1 ] dp[i][j] = dp[i - 1][j - 1] else dp[i][j] = min(dp[i - 1][j - 1] + 2, dp[i - 1][j] + 1, d[i][j - 1] + 1)
        // dp[i][0] = i; dp[0][i] = j
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                    // dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j] + 1, dp[i][j - 1] + 1)); // 这样写也可以
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1] + 2, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};