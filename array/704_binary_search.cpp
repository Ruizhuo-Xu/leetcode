#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // nums必须符合:有序数组; 无重复;
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭区间内[left, right]
        while(left <= right) { // 区间[left, right]满足条件left <= right
            int middle = left + (right - left) / 2; // 防止溢出
            if (nums[middle] > target) { // 如果中间值大于target,则新区间更新为[left, middle-1]
                right = middle - 1;
            } else if (nums[middle] < target) { // 反之,新区间为[middle+1, right]
                left = middle + 1;
            } else {
                return middle;
            }
        }
		return -1;
    }
};

int main() {
	Solution s = Solution();
	vector<int> nums = {-1, 0, 3, 5, 9, 12};
	int target = 2;
	cout << s.search(nums, target) << endl;
	return 0;
}