#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0; // 存放0的下标
        int right = nums.size() - 1; // 存放2的下标
        int idx = 0;
        while (idx <= right) {
            if (nums[idx] == 0) {
                if (idx > left) {
                    swap(nums[idx], nums[left]);
                    left++;
                } else {  // idx和left相等的情况
                    idx++;
                }
            } else if (nums[idx] == 2) {
                if (idx < right) {
                    swap(nums[idx], nums[right]);
                    right--;
                } else {  // idx和right相等的情况
                    idx++;
                }
            } else {  // nums[i] == 1的情况
                idx++;
            }
        }
    }
};