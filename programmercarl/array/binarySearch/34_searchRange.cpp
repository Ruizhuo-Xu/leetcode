#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return vector<int>{-1, -1};
        }
        int rightBorder = searchRightBorder(nums, target);
        int leftBorder = searchLeftBorder(nums, target);
        return vector<int>{leftBorder, rightBorder};
    }

private:
    int searchRightBorder(vector<int>& nums, int target) {
        // 搜索右边界
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] > target) { // 该条件保证nums[right] >= target, 且等于target时,是数组中最后一个
                right = middle - 1;
            } else if (nums[middle] <= target) { // 该条件保证nums[left] <= target
                left = middle + 1;
            }
        }
        if (right < 0 || nums[right] != target) { // 注意边界, target在数组左边界之外
            return -1;
        }
        return right;
    }

    int searchLeftBorder(vector<int>& nums, int target) {
        // 搜索左边界
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] >= target) { // 该条件保证nums[right] >= target
                right = middle - 1;
            } else if (nums[middle] < target) { // 该条件保证nums[left] <= target, 如果等于target,也是数组中的第一个target
                left = middle + 1;
            }
        }
        if (left >= nums.size() || nums[left] != target) { // 注意边界, target在数组右边界之外
            return -1;
        }
        return left;
    }
};

int main() {
    Solution s = Solution();
    // vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> nums = {1};
    int target = 0;
    vector<int> res = s.searchRange(nums, target);
    cout << res[0] << ' ' << res[1] << endl;
    return 0;
}