#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) return false;
        // 01背包: target背包容量，nums[i]是物品
        // dp[j]: 容量为j的背包最多装多重的物品
        // dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]])
        // dp[i] = 0;
        // 遍历顺序: 先物品后背包，背包逆序遍历
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[target] == target; // 背包能否装满
    }
};

int main() {
    vector<int> nums = {1,5,11,5};
    cout << Solution().canPartition(nums) << endl;
    return 0;
}