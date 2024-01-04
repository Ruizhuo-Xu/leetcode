#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 时间复杂度: O(n), 空间复杂度: O(1)
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                nums[left++] = nums[right];
            }
        }
        for (; left < nums.size(); left++) {
            nums[left] = 0;
        }
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 3, 2};
    Solution().moveZeroes(nums);
    for (int it : nums) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}