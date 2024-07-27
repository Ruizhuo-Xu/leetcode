#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int curCover = 0;
        int nextCover = 0;
        int step = 0;
        for (int i = 0; i <= curCover; i++) {
            if (curCover >= nums.size() - 1) {
                break;
            }
            nextCover = max(nextCover, i + nums[i]);
            if (i == curCover) {
                step++;
                curCover = nextCover;
            }
        }
        return step;
    }
};