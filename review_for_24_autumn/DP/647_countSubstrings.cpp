#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        // dp[i][j]: [i, j]范围的子串是否是回文子串
        // if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1]))
        // 只遍历右半三角，从下往上，从左往右
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int res = 0;
        for (int j = 0; j < s.size(); j++) {
            for (int i = j; i >= 0; i--) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                    res++;
                    dp[i][j] = true;
                }
            }
        }
        return res;
    }
};