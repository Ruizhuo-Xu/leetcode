#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(2);
        dp[0] = 1;
        dp[1] = 2;
        int sum = 0;
        for (int i = 3; i <= n; i++) {
            sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return sum;
    }
};

int main() {
    cout << Solution().climbStairs(5) << endl;
    return 0;
}