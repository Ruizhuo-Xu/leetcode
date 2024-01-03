#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // dp[i]: 以nums[i]结尾的最长连续递增子序列的长度(连续子序列，即子数组，一般都以nums[i]结尾)
        // dp[i] = nums[i] > nums[i - 1] ? dp[i - 1] + 1 : 1;
        // dp[i] = 1;
        vector<int> dp(2, 1);
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            dp[1] = nums[i] > nums[i - 1] ? dp[0] + 1 : 1;
            dp[0] = dp[1];
            res = max(dp[1], res);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,3,5,4,7};
    cout << Solution().findLengthOfLCIS(nums) << endl;
    return 0;
}