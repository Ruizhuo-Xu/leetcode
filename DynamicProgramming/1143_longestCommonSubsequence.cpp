#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i][j]：长度为[0, i - 1]的字符串text1与长度为[0, j - 1]的字符串text2的最长公共子序列为dp[i][j] (子序列，非结尾)
        // if text1[i - 1] == text2]j - 1] dp[i][j] = dp[i - 1][j - 1] + 1; else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        // dp[i][0] = 0; dp[0][j] = 0;
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

int main() {
    string text1 = "abcde";
    string text2 = "aee";
    cout << Solution().longestCommonSubsequence(text1, text2) << endl;
    return 0;
}