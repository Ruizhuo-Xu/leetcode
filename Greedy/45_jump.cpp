#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int cover = 0; // 每一次跳跃能覆盖的最大范围
        int maxCover = cover; // 当前覆盖范围内再跳跃一次能到达的最大范围
        int curStep = 0; // 当前跳跃的次数
        for (int i = 0; i <= cover; i++) {
            int temp = i + nums[i]; // 当前位置能跳跃到的最大范围
            if (temp > maxCover) { // 更新最大覆盖范围
                maxCover = temp;
            }
            if (maxCover >= nums.size() - 1) { // 从当前位置起跳可以到达末尾
                break;
            }
            if (i == cover) { // 当前这一次跳跃能覆盖的元素遍历完成,进行下一次跳跃
                cover = maxCover;
                curStep++;
            }
        }
        return ++curStep; // 还需要最后一次跳跃才能从当前位置跳到末尾
    }
};

int main() {
    // vector<int> nums = {2, 2, 1, 1, 4};
    vector<int> nums = {5,4,0,1,3,6,8,0,9,4,9,1,8,7,4,8};
    cout << Solution().jump(nums) << endl;
    return 0;
}