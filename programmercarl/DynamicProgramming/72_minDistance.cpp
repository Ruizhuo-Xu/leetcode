#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j]: word1 0~i-1的子串和word2 0~j-1的子串相同需要的最小编辑次数
        // 当word1[i - 1] == word2[j - 1]时, dp[i][j] = dp[i - 1][j - 1];
        // 不相等时, dp[i][j] = min (dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1)
        // 分别对应删除(插入)和替换; 删除和插入操作可逆,所以只需要考虑删除操作的最少次数即可
        // dp[i][0] = i; dp[0]j] = j;
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1; // 删除(插入), 替换
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
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