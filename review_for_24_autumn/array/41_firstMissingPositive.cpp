#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {  // 设数组长度为n, nums[i]在[1, n]间, 最后一个条件防止死循环
                swap(nums[i], nums[nums[i] - 1]);
            }  
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};