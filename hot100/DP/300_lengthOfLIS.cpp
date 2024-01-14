#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i]：以i为结尾的递增子序列的最大长度
        // if nums[j] < nums[i] : dp[i] = max(dp[i], dp[j]), j = 0,...,i-1
        // dp[i] = 1
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) { // 递增
                    dp[i] = max(dp[i], dp[j] + 1);
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