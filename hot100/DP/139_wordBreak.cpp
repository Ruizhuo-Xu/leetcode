#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 完全背包，s的长度表示背包容量，wordDict[i]表示物品
        // dp[j]: [0-j]的s的子串能否由wordDict内的单词组成
        // dp[j] = dp[j] || (dp[j - word.size()] && s.substr(j - word.size(), word.size()) == wordDict[i]) // 取或不取
        // dp[0] = true;(相当于空字符串组成空字符串), dp[j != 0] = false;
        // 遍历顺序：先背包容量后物品(因为组成s的单词需要考虑顺序)
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int j = 0; j <= s.size(); j++) {
            for (int i = 0; i < wordDict.size(); i++) {
                string word = wordDict[i];
                if (j - (int)word.size() >= 0) { // 要强制将word.size()转成int,否则表达式变成uint !!!!!
                    dp[j] = dp[j] || (dp[j - word.size()] && s.substr(j - word.size(), word.size()) == word);
                }
            }
        }
        return dp[s.size()];
    }
};

int main() {
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    cout << Solution().wordBreak(s, wordDict) << endl;
    return 0;
}