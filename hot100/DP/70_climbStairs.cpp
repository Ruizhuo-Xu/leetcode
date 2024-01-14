#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(2, 0);
        dp[0] = 1; // 第一阶
        dp[1] = 2; // 第二阶
        int res = 0;
        for (int i = 3; i <= n; i++) {
            res = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = res;
        }
        return res;
    }
};

int main() {
    cout << Solution().climbStairs(3) << endl;
    return 0;
}