#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][j]: 以i-1下标结尾的nums1子数组和以j-1下标结尾的nums2子数组的最长连续子数组的长度
        // if (nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
        // dp[i][0] = dp[0][j] = 0; 相当于某个数组为空,那么相同子数组也为0
        // dp数组定义的时候以i结尾和以j结尾虽然直观，但是需要多初始化一行一列
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int res = 0;
        for (int i = 1; i < nums1.size() + 1; i++) {  // 由于dp数组的定义，这里需要+1
            for (int j = 1; j < nums2.size() + 1; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {  // 以i-1结尾和以j-1结尾
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};