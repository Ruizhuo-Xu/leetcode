#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            // nums[mid]不是target，那么在[left, mid - 1]和[mid + 1, right]中搜索
            // 以mid为界 区间[left, mid]和[mid, right]至少有一个区间是有序的(可能两个都有序)
            // 我们需要找到这个有序的区间，判断target是否在这个区间内，如果在就在这个区间内极限搜索
            // 如果不在，就再另一个区间内搜索
            if (nums[mid] >= nums[left]) { // [left, mid]是有序区间 nums[mid] == nums[left]说明这个区间只有一个元素，也是有序的
                if (target < nums[mid] && target >= nums[left]) { // target在[left, mid - 1]之间
                    right = mid - 1; // 左闭右闭
                } else { // 否则target在[mid + 1, right]之间
                    left = mid + 1;
                }
            } else { // [mid, right]是有序区间
                if (target <= nums[right] && target >= nums[mid]) { // target在[mid + 1, right]之间
                    left = mid + 1;
                } else { // 否则target在[left, mid - 1]之间
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {3,1};
    int target = 1;
    cout << Solution().search(nums, target) << endl;
    return 0;
}