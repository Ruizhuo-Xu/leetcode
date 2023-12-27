#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxValue = INT32_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxValue = maxValue > sum ? maxValue : sum;
            if (sum < 0) { // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
                sum = 0;
            }
        }
        return maxValue;
    }
};

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int res = Solution().maxSubArray(nums);
    cout << res << endl;
    return 0;
}