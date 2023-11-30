#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 寻找最小子序列
        // 滑动窗口,也可以理解为双指针法的一种
        int slowIndex = 0;
        int res = INT32_MAX;
        int sum = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            sum += nums[fastIndex];
            while (sum >= target) { // 符合条件则移动左指针寻找符合条件的极限情况(最小子序列)
                int subLength = fastIndex - slowIndex + 1;
                res = subLength < res ? subLength : res;
                sum -= nums[slowIndex++];
            }
        }
        res = res == INT32_MAX ? 0 : res;
        return res;
    }
};

int main() {
    Solution so = Solution();
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    int res = so.minSubArrayLen(target, nums);
    cout << res << endl;
    return 0;
}