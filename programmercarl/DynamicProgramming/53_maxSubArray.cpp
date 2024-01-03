#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp[i]: 以nums[i]结尾的最大子数组和
        // dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        // dp[0] = nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int res = INT32_MIN;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Solution().maxSubArray(nums) << endl;
    return 0;
}