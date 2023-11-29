#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        // 二分查找假设目标值包含在区间[left, right]
        // 如果目标不存在
        // 查找的极限情况是left == right == middle
        // 此时如果target在middle左边,下一次循环right = middle - 1
        // 如果target在right右边,下一次训好left = middle + 1
        // 无论哪种情况,最终循环结束后,target肯定包含在区间[right, left]中
        return right + 1;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {1, 3, 5, 6};
    int target = 7;
    cout << s.searchInsert(nums, target) << endl;
    return 0;
}