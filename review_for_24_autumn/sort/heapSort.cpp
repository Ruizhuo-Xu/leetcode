#include <iostream>
#include <vector>
using namespace std;

void downAdjust(vector<int>& nums, int i, int heapSize) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int maxValIdx = i;
    if (left < heapSize && nums[left] > nums[maxValIdx]) maxValIdx = left;
    if (right < heapSize && nums[right] > nums[maxValIdx]) maxValIdx = right;
    if (maxValIdx != i) {
        swap(nums[maxValIdx], nums[i]);
        downAdjust(nums, maxValIdx, heapSize);
    }
}

void upAdjust(vector<int>& nums, int i) {
    int parent = (i - 1) / 2;
    if (parent >= 0 && nums[parent] < nums[i]) {
        swap(nums[parent], nums[i]);
        upAdjust(nums, parent);
    }
}

void insert(vector<int>& heap, int val) {
    heap.push_back(val);
    upAdjust(heap, heap.size() - 1);
}

void buildHeap(vector<int>& nums) {
    int heapSize = nums.size();
    for (int i = heapSize / 2; i >= 0; i--) {
        downAdjust(nums, i, heapSize);
    }
}

void heapSort(vector<int>& nums) {
    buildHeap(nums);
    int heapSize = nums.size();
    for (int i = heapSize - 1; i >= 0; i--) {
        swap(nums[i], nums[0]);
        downAdjust(nums, 0, i);
    }
}


int main() {
    vector<int> nums = {85, 55, 82, 57, 68, 92, 99, 98, 66, 56};
    buildHeap(nums); // 建堆
    for (auto num : nums) {
        cout << num << ' ';
    }
    cout << endl;
    insert(nums, 100); // 堆插入
    for (auto num : nums) {
        cout << num << ' ';
    }
    cout << endl;
    heapSort(nums); // 堆排序
    for (auto num : nums) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}
