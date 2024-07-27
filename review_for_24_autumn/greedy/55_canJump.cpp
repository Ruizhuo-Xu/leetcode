#include <iostream>
#include <vector>
using namesapce std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curCover = 0;  // 当前跳跃覆盖的范围
        int nextCover = 0; // 下一次跳跃覆盖的范围
        for (int i = 0; i <= curCover; i++) {
            if (curCover >= nums.size() - 1) {
                return true;
            }
            nextCover = max(nextCover, i + nums[i]);
            if (i == curCover) {
                curCover = nextCover;
            }
        }
        return false;
    }
};