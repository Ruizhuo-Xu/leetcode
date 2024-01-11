#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = searchLeft(nums, target);
        int right = searchRight(nums, target);
        return vector<int>({left, right});
    }

    int searchLeft(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) right = mid;
            else if (nums[mid] < target) left = mid + 1;
        }
        if (right < 0 || right >= nums.size() || nums[right] != target) { // 没有找到的情况
            return -1;
        }
        return right;
    }

    int searchRight(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) right = mid;
            else if (nums[mid] <= target) left = mid + 1;
        }
        if (right < 1 || right > nums.size() || nums[right - 1] != target) {
            return -1;
        }
        return right - 1;
    }
};

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> res = Solution().searchRange(nums, target);
    cout << res[0] << ' ' << res[1] << endl;
    return 0;
}