#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // dp[i]: 爬到第i阶楼梯的最小花费
        // dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
        // dp[0] = 0; dp[1] = 0;
        // [2, cost.size()]
        vector<int> dp(2, 0);
        for (int i = 2; i <= cost.size(); i++) {
            int res = min(dp[0] + cost[i - 2], dp[1] + cost[i - 1]);
            dp[0] = dp[1];
            dp[1] = res;
        }
        return dp[1];
    }
};