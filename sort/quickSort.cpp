#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
    // 以nums[left]为主元，将数组划分为两个部分，左半部分元素都小于等于nums[left]
    // 右半部分元素都大于等于nums[left]
    // 相当于找到了nums[left]在整个排好序后的数组中的正确位置
    // 返回新的位置
    int temp = nums[left];
    while (left < right) {
        while (left < right && nums[right] >= temp) right--; // 仍然需要判断left < right
        nums[left] = nums[right];
        while (left < right &&nums[left] <= temp) left++;
        nums[right] = nums[left];
    }
    nums[left] = temp;
    return left;
}

void quickSort(vector<int>& nums, int left, int right) {
    // 快速排序，平均时间复杂度O(nlogn)
    // 类似于树的前序遍历
    if (left >= right) return ; // 区间只有一个元素，不需要排序
    int pos = partition(nums, left, right);
    quickSort(nums, left, pos - 1);
    quickSort(nums, pos + 1, right);
}

int main() {
    vector<int> nums = {3, 5, 1, 4, 2, 7, 0};
    quickSort(nums, 0, nums.size() - 1);
    for (int num : nums) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}