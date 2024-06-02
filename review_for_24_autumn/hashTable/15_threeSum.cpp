#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {  // 剪枝
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {  // num1去重
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    right--;
                } else if(sum < 0) {
                    left++;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left + 1] == nums[left]) left++;  // nums2去重
                    while (left < right && nums[right - 1] == nums[right]) right--;  // nums3去重
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {0, 0, 0, 0};
    vector<vector<int>> res = Solution().threeSum(nums);
    for (vector<int> x: res) {
        for (int i : x) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}