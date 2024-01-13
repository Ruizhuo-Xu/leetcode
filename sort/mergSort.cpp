#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, int l1, int r1, int l2, int r2) {
    // 合并[l1, r1]和[l2, r2]这两个有序区间为一个新的有序区间
    vector<int> temp(nums.size(), 0); // 使用一个临时数组储存合并的结果
    int index = 0;
    int i = l1, j = l2;
    while (i <= r1 && j <= r2) { // 合并两个区间
        if (nums[i] <= nums[j]) {
            temp[index++] = nums[i++];
        } else {
            temp[index++] = nums[j++];
        }
    }
    // 合并剩余的区间
    while (i <= r1) temp[index++] = nums[i++];
    while (j <= r2) temp[index++] = nums[j++];
    // 使用临时数组覆盖原数组的值
    for (i = 0; i < index; i++) {
        nums[l1 + i] = temp[i];
    }
}

void mergeSort(vector<int>& nums, int left, int right) {
    // 归并排序, 时间复杂度O(nlogn)
    // 类似树的后序遍历
    if (left == right) return ; // 区间只有一个元素，直接返回
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, mid + 1, right);
}

int main() {
    vector<int> nums = {3, 5, 1, 4, 2, 7, 0};
    mergeSort(nums, 0, nums.size() - 1);
    for (int num : nums) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}