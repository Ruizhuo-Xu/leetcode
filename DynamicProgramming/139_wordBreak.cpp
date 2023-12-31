#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[j]表示长度为j的字符串能否由wordDict内的单词组成
        // s.substr(i, j - i)在wordDict中 && dp[i] == true
        // dp[0] = true
        // 先遍历背包,后遍历物品
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        for (int j = 0; j <= s.size(); j++) { // 先遍历背包
            for (int i = 0; i < j; i++) {
                string word = s.substr(i, j - i);
                if (wordSet.find(word) != wordSet.end() && dp[i]) {
                    dp[j] = true;
                }
            }
        }
        return dp[s.size()];
    }
};

int main() {
    vector<string> wordDict = {"apple", "pen"};
    string s = "applepenapple";
    cout << Solution().wordBreak(s, wordDict) << endl;
    return 0;
}