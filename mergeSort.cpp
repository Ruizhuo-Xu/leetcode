#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, int l1, int r1, int l2, int r2) {
    vector<int> temp;
    int idx1 = l1;
    int idx2 = l2;
    while (idx1 <= r1 && idx2 <= r2) {
        if (nums[idx1] < nums[idx2]) {
            temp.push_back(nums[idx1++]);
        } else {
            temp.push_back(nums[idx2++]);
        }
    }
    while (idx1 <= r1) temp.push_back(nums[idx1++]);
    while (idx2 <= r2) temp.push_back(nums[idx2++]);
    for (int i = 0; i < temp.size(); i++) {
        nums[l1 + i] = temp[i];
    }
}

void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) return ;
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