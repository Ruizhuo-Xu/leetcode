#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // 完全背包问题，背包容量为n,物品为平方数，每个物品可以重复选取
        // dp[j]: 和为j的完全平方数的最少数量
        // dp[j] = min(dp[j], dp[j - i*i] + 1); 当前物品取或不取
        // dp[0] = 0; dp[j != 0] = INT_MAX // 相当于用数字0累加和为j需要无穷多个
        // 遍历顺序任意(先物品或先背包),因为求的是最少的物品数量，和物品的选取顺序无关(组合or排列)
        vector<int> dp(n + 1, INT32_MAX); // [0, n]
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            int temp = i * i; // 物品
            for (int j = temp; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - temp] + 1);
            }
        }
        return dp[n];
    }
};

int main() {
    cout << Solution().numSquares(12) << endl;
    return 0;
}