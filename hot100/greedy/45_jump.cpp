#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int curCover = 0;
        int maxCover = 0;
        int jumpSteps = 0;
        for (int i = 0; i <= curCover; i++) {
            maxCover = max(maxCover, i + nums[i]);
            if (curCover >= nums.size() - 1) { // 当前这步跳跃范围可以覆盖到末尾
                break;
            }
            if (i == curCover) { // 当前这步跳跃无法覆盖到末尾，只能再跳一步
                curCover = maxCover;
                jumpSteps++;
            }
        }
        return jumpSteps;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << Solution().jump(nums) << endl;
    return 0;
}