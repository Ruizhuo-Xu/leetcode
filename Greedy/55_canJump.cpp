#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 贪心:
        // 局部最优: 当前能通过跳跃覆盖的最大区域(不断更新)
        // 全局最优: 最大覆盖区域是否包含序列末尾
        if (nums.size() == 1) {
            return true;
        }
        int cover = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > cover) { // 如果索引超出覆盖区域,则说明当前序列无法通过跳跃到达末尾
                break;
            }
            cover = max(i + nums[i], cover); // 当前跳跃能覆盖到的区域(最大索引)
            if (cover >= nums.size() - 1) { // 如果覆盖区域包含了序列末尾,则满足题目要求
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {2, 2, 1, 0, 4};
    cout << Solution().canJump(nums) << endl;
    return 0;
}