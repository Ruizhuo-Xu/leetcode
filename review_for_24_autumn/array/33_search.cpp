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
            if (nums[mid] == target) {
                return mid;
            }
            // nums[mid]不是target，那么在[left, mid - 1]和[mid + 1, right]中搜索
            // 以mid为界 区间[left, mid]和[mid, right]至少有一个区间是有序的(可能两个都有序)
            // 我们需要找到这个有序的区间，判断target是否在这个区间内，如果在就在这个区间内继续搜索
            // 如果不在，就再另一个区间内搜索
            if (nums[mid] >= nums[left]) {
                if (target < nums[mid] && target >= nums[left]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target <= nums[right] && target > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};