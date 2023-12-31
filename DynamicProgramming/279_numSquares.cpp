#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // dp[j]: 和为j的完全平方数的最少数量
        // dp[j] = min(dp[j], dp[j - i^2] + 1)
        // dp[0] = 0; dp[j!=0] = INT_MAX
        // 遍历顺序随意
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) { // 先遍历物品
            int temp = i * i;
            for (int j = temp; j <= n; j++) { // 遍历物品
                if (dp[j - temp] != INT32_MAX) {
                    dp[j] = min(dp[j], dp[j - temp] + 1);
                }
            }
            for (int it : dp) {
                cout << it << ' ';
            }
            cout << endl;
        }
        return dp[n];
    }
};

int main() {
    int n = 12;
    cout << Solution().numSquares(n) << endl;
    return 0;
}