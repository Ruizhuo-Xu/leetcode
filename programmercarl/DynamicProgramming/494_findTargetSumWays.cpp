#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int it : nums) sum += it;
        if ((sum + target) % 2) return 0; // 如果方程解出来x为小数，则没有可能性
        if (sum < abs(target)) return 0; // 如果所有数字全取正或全取负都达不到target，则没有可能性
        // 将nums分成两堆,一堆全取正,一堆全取负, 列出方程: x + y = sum, x - y = target
        // x = (sum + target) / 2; y = x - sum;
        int x = (sum + target) / 2;
        int y = sum - x;
        int myTarget = min(x, y);
        vector<int> dp(myTarget + 1, 0); // 表示从0-i个数字中任取若干个,和为j的可能组合数
        // 初始化: 什么物品都不取的时候,和为0,所以初始有1种情况
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = myTarget; j >= nums[i]; j--) {
                dp[j] = dp[j] + dp[j - nums[i]]; // nums[i]取或不取组合等于j的数量
            }
        }
        return dp[myTarget];
    }
};

int main() {
    // vector<int> nums = {2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53};
    vector<int> nums = {0,0,0,0,0,0,0,0,1};
    cout << Solution().findTargetSumWays(nums, 1000) << endl;
    return 0;
}