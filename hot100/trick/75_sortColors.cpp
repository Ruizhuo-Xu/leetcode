#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0; // 准备存储元素0的位置
        int right = nums.size() - 1; // 准备存储元素2的位置
        int index = 0; // 当前遍历的元素的位置
        while (index <= right) { // 如果当前遍历的元素越过了right,说明后面遍历的元素都是2，不需要处理了
            // 将0往前移，将2往后移
            if (nums[index] == 0) { // 当前遍历的元素为0，则将其和left位置的元素交换，并更新left位置
                swap(nums[index], nums[left]);
                left++;
            }
            if (nums[index] == 2) { // 当前遍历的元素为2，则将其和right位置的元素交换，并更新right位置
                swap(nums[index], nums[right]);
                right--;
            }
            if (nums[index] == 1 || index < left) index++; // 当前元素为1不需要交换，index++
            // 另外，如果当前遍历的位置在left之前，说明当前元素已经处理完了，也要index++(考虑nums[0]== 0的情况, 交换完left==1,但是index==0)
        }
        return ;
    }
};

int main() {
    vector<int> nums = {1,0,2,1,2,0};
    Solution().sortColors(nums);
    for (int num : nums) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}