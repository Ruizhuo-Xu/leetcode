#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 四数之和：a+b+c+d
        // 利用双指针把O(n^2)变成O(n)
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > target && nums[i] > 0) { // 剪枝，正数越加越大，永远不可能等于target
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) { // 元素a去重
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] > target && nums[i] + nums[j] > 0) { // 剪枝，同理
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) { // 元素b去重 注意j > i + 1条件，容易遗漏
                    continue;
                }
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    long sum = (long) nums[i] + nums[j] + nums[left] + nums[right]; // 防止数值溢出
                    if (sum > target) right--;
                    else if (sum < target) left++;
                    else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++; // 元素c去重
                        while (left < right && nums[right] == nums[right - 1]) right--; // 元素d去重
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = Solution().fourSum(nums, target);
    for (auto it : res) {
        for (auto i : it) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}