#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != nums[slowIndex]) {
                nums[++slowIndex] = nums[fastIndex];
            }
        }
        return slowIndex + 1;
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