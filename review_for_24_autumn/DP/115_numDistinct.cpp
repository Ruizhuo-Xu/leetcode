#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        // s中包含t s = 'bagg' t='bag'
        // dp[i][j]: 以i-1结尾的s子串和以j-1结尾的t子串中，s子串的子序列中包含t子串的个数
        // if s[i - 1] == t[j - 1] dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][t]  // 末尾相等时：1.匹配末尾元素（相当于消除了最后的元素）
        // 所以分别退一位； 2.不匹配末尾元素（相当于删除s子串的末尾元素），这是s子串退一位
        // 也可以这样思考, 当已知dp[i - 1][j]时，推导dp[i][j]的状态，相当于给s子串增加一个元素，如果这个元素和t子串的最后一个元素相等，
        // 就可以用这个元素和t子串末尾匹配，这时新增的匹配方法是dp[i - 1][j - 1]; 如果不匹配，也就是不增加这个元素的时候，方法数是dp[i - 1][j]
        // 也就是dp[i - 1][j] + dp[i - 1][j -  1]
        // 初始化 dp[i][0] = 1; 总是可以通过删除s实现空字符串; dp[0][j] = 0; dp[0][0] = 1
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 0; i <= s.size(); i++) dp[i][0] = 1;
        for (int j = 0; j <= t.size(); j++) dp[0][j] = 0;
        dp[0][0] = 1;
        int mod = 1e9 + 7;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;  // 感觉只有这题需要搞清楚所有情况所以要考虑两项，其他题目多种情况可以归并为同一种情况，所以不需要考虑
                } else {
                    dp[i][j] = dp[i - 1][j] % mod;
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};