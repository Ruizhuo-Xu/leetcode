#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size(); // 左闭右开
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) right = mid;
            else if (nums[mid] < target) left = mid + 1;
            else {
                return mid;
            }
        }
        return right;
    }
};

int main() {
    vector<int> nums = {1,3,5,6};
    int target = 7;
    cout << Solution().searchInsert(nums, target) << endl;
    return 0;
}