#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 双指针: nums[i] + nums[left] + nums[right] = 0
        // 因为题目返回的是数值而不是索引，所以可以排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) { // 元素a去重
                // 因为nums排序过，所以相同的值必然相连
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) right--;
                else if (sum < 0) left++;
                else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    // 两个while循环的第一个条件防止后续数组越界
                    while (right > left && nums[left] == nums[left + 1]) left++; //元素b去重
                    while (right > left && nums[right] == nums[right - 1]) right--; // 元素c去重
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = Solution().threeSum(nums);
    for (auto it : res) {
        for (auto i : it) {
            cout << i << ' ';
        }
        cout <<endl;
    }
    return 0;
}
