#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = getLeft(nums, target);
        int right = getRight(nums, target);
        return {left, right};
    }

    int getLeft(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (left >= 0 && left <= (int) nums.size() - 1 && nums[left] == target) {
            return left;
        }
        return -1;
    }

    int getRight(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (right >= 0 && right <= (int) nums.size() - 1 && nums[right] == target) {
            return right;
        }
        return -1;
    }
};