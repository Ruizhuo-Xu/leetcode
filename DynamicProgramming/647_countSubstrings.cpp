#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        // dp[i][j]:i~j的字符子串能否构成回文串
        // 当(s[i] == s[j])且 dp[i + 1][j - 1] = true时, dp[i][j] = true;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int res = 0;
        for (int i = s.size() - 1; i >= 0; i--) { // 从低往上
            for (int j = i; j < s.size(); j++) { // j >= i
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        res++;
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) {
                        res++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    string s = "aaa";
    cout << Solution().countSubstrings(s) << endl;
    return 0;
}