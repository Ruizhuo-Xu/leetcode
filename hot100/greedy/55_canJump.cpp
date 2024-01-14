#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxCover = 0; // 最大覆盖范围(下标)
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxCover) { // 当前下标超出覆盖范围，说明无法到达末尾 // 这个条件必须放这个位置
                return false;
            }
            maxCover = max(maxCover, i + nums[i]); // 不断更新覆盖范围
            if (maxCover >= nums.size() - 1) { // 能覆盖到末尾
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