#include <iostream>
#include <vector>
using namespace std;

void downAdjust(vector<int>& nums, int i, int heapSize) {
    // 递归
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int maxIndex = i;
    if (left < heapSize && nums[left] > nums[maxIndex]) maxIndex = left;
    if (right < heapSize && nums[right] > nums[maxIndex]) maxIndex = right;
    if (maxIndex != i) {
        swap(nums[i], nums[maxIndex]);
        downAdjust(nums, maxIndex, heapSize);
    }
}

void downAdjust_(vector<int>& nums, int i, int heapSize) {
    // 非递归
    while (i < heapSize) {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int maxIndex = i;
        if (left < heapSize && nums[left] > nums[maxIndex]) maxIndex = left;
        if (right < heapSize && nums[right] > nums[maxIndex]) maxIndex = right;
        if (maxIndex != i) {
            swap(nums[i], nums[maxIndex]);
            i = maxIndex;
        } else {
            break;
        }
    }
}

void createHeap(vector<int>& nums) {
    int heapSize = nums.size();
    for (int i = heapSize / 2; i >= 0; i--) { // 从最后一个非叶子节点开始从右往左，从下往上
        downAdjust_(nums, i, heapSize);
    }
}

void heapSort(vector<int>& nums) {
    createHeap(nums);
    for (int i = nums.size() - 1; i >= 1; i--) {
        swap(nums[0], nums[i]);
        downAdjust(nums, 0, i);
    }
}

int main() {
    vector<int> nums = {85, 55, 82, 57, 68, 92, 99, 98, 66, 56};
    heapSort(nums);
    for (auto num : nums) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}