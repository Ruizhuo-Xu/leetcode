#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        // 问题可以看成:在s中删除若干字符后等于t
        // dp[i][j]表示0~i-1的s的子串中出现0~j-1的t的子串的次数
        // 当s[i - 1] == t[i - 1]时, dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        // 分别对应保留s[i - 1]和删除s[i - 1]两种情况
        // 当s[i - 1] != t[i - 1]时, dp[i][j] = dp[i - 1][j]; 不相等直接删除s[i - 1]
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int j = 0; j <= t.size(); j++) dp[0][j] = 0; // 相当于s是空字符串
        for (int i = 0; i <= s.size(); i++) dp[i][0] = 1; // 相当于t是空字符串
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};

int main() {
    string s = "rabbbit";
    string t = "rabbit";
    cout << Solution().numDistinct(s, t) << endl;
    return 0;
}