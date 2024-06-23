#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT32_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res = max(res, sum);
            if (sum < 0) {  // 如果当前sum < 0, 则包含当前元素的子数组必不可能最大, 从下一个元素开始继续累计
                sum = 0;
            }
        }
        return res;
    }
};