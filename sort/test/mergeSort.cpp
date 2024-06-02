#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, int l1, int r1, int l2, int r2) {
    int i = l1;
    int j = l2;
    vector<int> temp(nums.size(), 0);
    int index = 0;
    while (i <= r1 && j <= r2) {
        if (nums[i] < nums[j]) {
            temp[index++] = nums[i++];
        } else {
            temp[index++] = nums[j++];
        }
    }
    while (i <= r1) temp[index++] = nums[i++];
    while (j <= r2) temp[index++] = nums[j++];
    for (int i = 0; i < index; i++) {
        cout << temp[i] << ' ';
        nums[l1 + i] = temp[i];
    }
    cout << endl;
}

void mergeSort(vector<int>& nums, int left, int right) {
    if (left == right) return ;
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, mid + 1, right);
}

int main() {
    vector<int> array = {2, 3, 1, 4, 6, 0};
    mergeSort(array, 0, array.size() - 1);
    for (int num : array) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}