#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // step1: 从右往左找第一个值相较于前一个值减少的元素，记为x
        // step2: 再次从右往左遍历，找第一个值大于x的元素，记为y
        // step3: 交换x和y
        // step4: 翻转原x位置后的序列
        int idx1 = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx1 = i;  // step1
                break;
            }
        }
        if (idx1 == -1) {  // 如果整个序列都是递增的，就直接reverse
            reverse(nums.begin(), nums.end());
            return ;
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] > nums[idx1]) {  // step2
                swap(nums[i], nums[idx1]);  // step3
                reverse(nums.begin() + idx1 + 1, nums.end());  // step4
                break;
            }
        }
    }
};