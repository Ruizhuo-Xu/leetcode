#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int temp = nums[left];
    while (left < right) {
        while (left < right && nums[right] >= temp) right--;
        swap(nums[left], nums[right]);
        while (left < right && nums[left] <= temp) left++;
        swap(nums[left], nums[right]);
    }
    return left;
}

void quickSort(vector<int>& nums, int left, int right) {
    if (left >= right) return ;
    int pos = partition(nums, left, right);
    quickSort(nums, left, pos - 1);
    quickSort(nums, pos + 1, right);
}

int main() {
    vector<int> nums = {4, 5, 1, 2, 9, 0};
    quickSort(nums, 0, nums.size() - 1);
    for (int num : nums) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}