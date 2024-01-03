#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 相当于以石头重量的一半作为背包容量,装尽可能重的石头
        int sum = 0;
        for (int it : stones) sum += it;
        int target = sum / 2; // 将一堆石头分成尽可能相等的两堆
        vector<int> dp(target + 1, 0); // 初始化为0,因为石头重量(价值)总为正
        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
};

int main() {
    vector<int> stones = {2,7,4,1,8,1};
    cout << Solution().lastStoneWeightII(stones) << endl;
    return 0;
}