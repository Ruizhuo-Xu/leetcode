#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curCover = 0; // 当前这一步跳跃可以覆盖的范围，初始只能从期起点出发
        int maxCover = 0; // 从当前这一步跳跃覆盖的范围起跳，最远可以覆盖的下一步跳跃范围
        for (int i = 0; i <= curCover; i++) {
            maxCover = max(maxCover, i + nums[i]); // 更新下一步跳跃的最大范围
            if (i == curCover) { // 当前这一步跳跃的末尾，即将进入下一步跳跃
                curCover = maxCover;
            }
            if (maxCover >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    // vector<int> nums = {2,3,1,1,4};
    vector<int> nums = {3,2,1,0,4};
    cout << Solution().canJump(nums) << endl;
    return 0;
}