#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int temp = nums[left];
    while (left < right) { // left和right相等的位置就是放置temp的位置
        while (left < right && nums[right] >= temp) right--;
        nums[left] = nums[right];
        while (left < right && nums[left] <= temp) left++;
        nums[right] = nums[left];
    }
    nums[left] = temp;
    return left;
}

void quickSort(vector<int>& nums, int left, int right) {
    if (left >= right) return ;
    int pos = partition(nums, left, right);
    quickSort(nums, left, pos - 1);
    quickSort(nums, pos + 1, right);
}

int main() {
    vector<int> nums = {2, 3, 1 ,4 ,2, 2, 6};
    quickSort(nums, 0, nums.size() - 1);
    for (int num : nums) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}