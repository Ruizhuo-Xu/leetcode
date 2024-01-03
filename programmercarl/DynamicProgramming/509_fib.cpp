#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        vector<int> dp(2); // 斐波那契递推式只和前两个状态有关
        // dp数组初始化
        dp[0] = 0;
        dp[1] = 1;
        int sum = 0;
        for (int i = 2; i <= n; i++) {
            sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return sum;
    }
};

int main() {
    cout << Solution().fib(4) << endl;
    return 0;
}