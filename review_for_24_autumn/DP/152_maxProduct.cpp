#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // dpMax[i]：以i结尾的子数组的最大乘积, dpMin[i]: 以i为结尾的子数组的最小乘积
        // 当nums[i]为正数时，希望乘上一个越大越好的正数，当nums[i]为负数时，希望乘上一个越小越好的负数，依次写出下面两个递推式
        // dpMax[i] = max(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i], nums[i])
        // dpMin[i] = min(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i], nums[i])
        // dpMax[i] = nums[0]; dpMin[i] = nums[0]; // 因为子数组至少要有一个数字
        vector<int> dpMax(nums.size());
        vector<int> dpMin(nums.size());
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dpMax[i] = max(nums[i], max(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]));
            dpMin[i] = min(nums[i], min(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]));
            res = max(res, dpMax[i]);
        }
        return res;
    }
};