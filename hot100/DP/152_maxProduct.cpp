#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // dpMax[i]：以i结尾的子数组的最大乘积, dpMin[i]: 以i为结尾的子数组的最小乘积
        // 当nums[i]为正数时，希望乘上一个越大越好的正数，当nums[i]为负数时，希望乘上一个越小越好的负数，依次写出下面两个递推式
        // dpMax[i] = max(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i], nums[i])
        // dpMin[i] = min(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i], nums[i])
        // dpMax[i] = nums[0]; dpMin[i] = nums[0];
        vector<int> dpMax(2, 0);
        vector<int> dpMin(2, 0);
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dpMax[1] = max({dpMax[0] * nums[i], dpMin[0] * nums[i], nums[i]});
            dpMin[1] = min({dpMax[0] * nums[i], dpMin[0] * nums[i], nums[i]});
            dpMax[0] = dpMax[1];
            dpMin[0] = dpMin[1];
            res = max(dpMax[0], res);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {2,3,-2,4};
    cout << Solution().maxProduct(nums) << endl;
    return 0;
}