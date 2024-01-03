#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j]: 0~i-1的word1的子串和0~j-1的word2的子串相同所需最少的删除步骤
        // 当word1[i - 1] == word2[j - 1]时, dp[i][j] = dp[i - 1][j - 1]; // 不需要删除,只需要考虑0~i-2和0~j-2的删除即可
        // else: dp[i][j] = min(dp[i - 1][j], dp[i][j] - 1) + 1; // 不相等，删除其中的一个(需要1步)
        // dp[0][j] = 0; dp[i][0] = i;
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); j++) {
            dp[0][j] = j;
        }
        dp[0][0] = 0; // 可以理解为两个空字符串,不需要任何操作
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
            for (int it : dp[i]) {
                cout << it << ' ';
            }
            cout << endl;
        }
        return dp[word1.size()][word2.size()];
    }
};

int main() {
    string word1 = "leetcode", word2 = "etco";
    cout << Solution().minDistance(word1, word2) << endl;
    return 0;
}