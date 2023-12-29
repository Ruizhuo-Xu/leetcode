#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= target; j++) { // 先遍历背包容量,再遍历物品数,求的是排列数
            for (int i = 0; i < nums.size(); i++) {
                if (j - nums[i] >= 0  && dp[j] < INT_MAX - dp[j - nums[i]]) {
                    dp[j] = dp[j] + dp[j - nums[i]];
                }
            }
        }
        return dp[target];
    }
};

int main() {
    vector<int> nums = {1,2,3};
    int target = 4;
    cout << Solution().combinationSum4(nums, target) << endl;;
    return 0;
}