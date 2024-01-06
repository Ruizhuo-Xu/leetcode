#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp[i]: 以nums[i]结尾的最大子数组的和
        // dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        // dp[0] = max(nums[0], 0);
        // 时间复杂度O(n),空间复杂度O(1)
        vector<int> dp(2, 0);
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[1] = max(dp[0] + nums[i], nums[i]);
            res = max (res, dp[1]); // 记录最大值
            dp[0] = dp[1];
        }
        return res;
    }
};

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Solution().maxSubArray(nums) << endl;
    return 0;
}