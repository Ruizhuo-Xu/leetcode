#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i]: 0-i户人家最多可以偷盗的钱
        // dp[i] = max(dp[i - 2] + nums[i] + dp[i - 1])
        // dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
        if (nums.size() == 1) return nums[0]; //  // 如果nums只有一个元素，那么下面dp[1]初始化会越界
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
    vector<int> nums = {1, 2, 3, 1};
    cout << Solution().rob(nums) << endl;
    return 0;
}