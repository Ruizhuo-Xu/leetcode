#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int target = nums[0];
        int slowIndex = 1;
        for (int fastIndex = 1; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != target) {
                nums[slowIndex++] = nums[fastIndex];
                target = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int len = s.removeDuplicates(nums);
    for (int i = 0; i < len; i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}