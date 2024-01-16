#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // dp[i][j]: [i, j]的子串是否是回文子串
        // if s[i] == s[j] && dp[i + 1][j - 1] != 0 : dp[i][j] = dp[i + 1][j - 1] + 2;
        // dp[i][j] = 0;
        // 从下往上，从左往右遍历
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int maxLen = 0;
        string res;
        for (int j = 0; j < s.size(); j++) {
            for (int i = j; i >= 0; i--) { // 只考虑上半部分
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) { // j - i <= 1放前面，这样不用处理边界
                    dp[i][j] = true;
                    int strLen = j - i + 1;
                    if (strLen > maxLen) {
                        maxLen = strLen;
                        res = s.substr(i, strLen);
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    string s = "babad";
    cout << Solution().longestPalindrome(s) << endl;
    return 0;
}