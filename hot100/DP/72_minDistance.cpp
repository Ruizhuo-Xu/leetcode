#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j]: 以i-1为结尾的word1子串和以j-1结尾的word2子串相同需要的最小编辑距离
        // if word1[i - 1] == word2[j - 1]: dp[i][j] = dp[i - 1][j - 1];
        // else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1 删除、替换
        // dp[i][0] = i; dp[0][j] = j;
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main() {
    string word1 = "horse";
    string word2 = "ros";
    cout << Solution().minDistance(word1, word2) << endl;
    return 0;
}