#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i]: 考虑下标0-i以内的房屋，最多可以偷盗的金额
        // dp[i] = max(dp[i-2] + nums[i], dp[i - 1]);
        // dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
        // 遍历顺序从左到右
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};

int main() {
    vector<int> nums = {2,7,9,3,1};
    cout << Solution().rob(nums) << endl;
    return 0;
}