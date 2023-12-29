#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 在cost数组上原地修改作为dp数组
        // dp[i]表示从第i个楼梯往上爬需要的最小cost
        // 递推式: dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]
        // dp数组初始化：dp[0] = cost[0] dp[1] = cost[1]
        // 遍历顺序: 从前往后,因为根据递推式要先确定前面楼梯的花费,才能计算到楼顶的花费
        for (int i = 2; i < cost.size(); i++) {
            cost[i] = min(cost[i - 1], cost[i - 2]) + cost[i];
        }
        int len = cost.size();
        return min(cost[len - 1], cost[len - 2]); // 最后到楼顶的最小花费=从前一步楼梯出发或从前两步楼梯出发
    }
};

int main() {
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    cout << Solution().minCostClimbingStairs(cost) << endl;
    return 0;
}