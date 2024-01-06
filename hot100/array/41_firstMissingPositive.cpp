#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 如果n个数正好分别是1-n,则缺失的最小正整数是n+1
        // 否则,缺失的数在1-n之间
        // 遍历数组,如果当前的数字x在1-n之间，则将其置换到数组下标x-1的位置
        // 全部置换完成后,第一个不符合nums[i] = i + 1的位置就是缺失的最小正整数位置
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) { // 最后一个条件防止死循环
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]  != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};

int main() {
    vector<int> nums = {3,4,-1,1};
    cout << Solution().firstMissingPositive(nums) << endl;
    return 0;
}