#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][j]: 以nums1[i-1]和nums[j-1]结尾的最长重复子数组的长度(子数组，结尾)
        // if (nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
        // dp[i][0] = 0; dp[0][j] = 0;
        vector<int> dp(nums2.size() + 1, 0); // 使用滚动数组压缩状态
        int res = 0;
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = nums2.size(); j >= 1; j--) { // 和背包问题压缩状态相同
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                } else {  // 注意这里不相等的时候要有赋0的操作
                    dp[j] = 0;
                }
                res = max(dp[j], res);
            }
            for (int it : dp) {
                cout << it << ' ';
            }
            cout << endl;
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {1,0,0,0,1};
    vector<int> nums2 = {1,0,0,1,1};
    cout << Solution().findLength(nums1, nums2) << endl;
    return 0;
}