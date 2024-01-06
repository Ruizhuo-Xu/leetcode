#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        cout << start << ' ' << end << endl;
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        // 先整体翻转,再分段翻转
        // 时间复杂度O(3n),空间复杂度O(1)
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k % nums.size() - 1); // k 有可能大于nums.size()
        reverse(nums, k % nums.size(), nums.size() - 1);
    }
};

int main() {
    // vector<int> nums = {1,2,3,4,5,6,7};
    vector<int> nums = {1,2};
    int k = 2;
    Solution().rotate(nums, k);
    for (int num : nums) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}