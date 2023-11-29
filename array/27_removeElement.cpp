#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 双指针法
        // 快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组
        // 慢指针：指向更新 新数组下标的位置
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != val) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int len = s.removeElement(nums, val);
    for (int i = 0; i < len; i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}