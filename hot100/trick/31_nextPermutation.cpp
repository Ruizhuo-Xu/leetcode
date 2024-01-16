#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >=0 && nums[i] >= nums[i + 1]) { // 从右往左找到第一个不符合递增的元素
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) { // 从右往左找第一个大于nums[i]的元素
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end()); // 翻转升序序列,使其变为降序序列，此时排列数字典序最小
    }
};

int main() {
    vector<int> nums = {1, 5, 8, 4, 7, 6, 5, 3, 1};
    Solution().nextPermutation(nums);
    for (int num : nums) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}