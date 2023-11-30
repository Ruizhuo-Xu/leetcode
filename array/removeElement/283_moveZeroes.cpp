#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0;
        int target = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != target) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        while (slowIndex < nums.size()) {
            nums[slowIndex++] = target;
        }
    }
};

int main() {
    Solution s = Solution();
    // vector<int> nums = {0, 1, 0, 3, 12};
    vector<int> nums = {0};
    s.moveZeroes(nums);
    for (auto it : nums) {
        cout << it << ' ';
    }
    return 0;
}