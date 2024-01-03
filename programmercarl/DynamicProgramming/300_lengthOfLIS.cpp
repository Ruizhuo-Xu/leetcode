#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i]: 以nums[i]结尾的最长递增子序列的长度(因为有递增的条件约束,所以要以nums[i]作为结尾)
        // dp[i] = nums[i] > nums[j] ? max(dp[j] + 1, dp[i]), j = 0,...,nums.size()-1
        // 初始化: dp[i] = 1
        vector<int> dp(nums.size(), 1);
        int res = 1; // 如果nums.size() == 1时,直接就返回1
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            res = max(dp[i], res);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << Solution().lengthOfLIS(nums) << endl;
    return 0;
}