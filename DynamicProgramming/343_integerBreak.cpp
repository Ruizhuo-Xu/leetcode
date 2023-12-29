#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        // dp[i] 表示将i拆分成k(k >= 2)个整数能获得的最大乘积
        // 递推公式： dp[i] = max(j * (i - j), j * dp[i - j], dp[i]), j = 1,...,i/2
        // 初始化: dp[0]无意义 dp[1]无意义 dp[2] = 1
        // 遍历顺序: 从前往后
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) { // 只有拆分成若干个近似相等的数时乘积才会最大,极限情况是拆成2个近似相等的数
                dp[i] = max(max(j * (i - j), j * dp[i - j]), dp[i]); // 拆分成2个数的情况和拆分成大于2个数的情况,最后的dp[i]用于更新最大值
            }
        }
        return dp[n];
    }
};

int main() {
    cout << Solution().integerBreak(10) << endl;
    return 0;
}