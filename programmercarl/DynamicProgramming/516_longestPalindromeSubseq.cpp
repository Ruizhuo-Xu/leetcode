#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // dp[i][j]: i~j的字符子串中最长的回文子序列的长度
        // 当s[i] == s[j]时,如果j - i == 0, dp[i][j] = 1; j - i == 1, dp[i][j] = 2; 另外 dp[i][j] = dp[i + 1][j - 1] + 2;
        // 当s[i] != s[j]时,dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = j - i + 1;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};

int main() {
    string s = "bbbab";
    cout << Solution().longestPalindromeSubseq(s) << endl;
    return 0;
}