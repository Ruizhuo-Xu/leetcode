#include <iostream>
#include <vector>
using namespace std;

void downAdjust(vector<int>& nums, int idx, int heapSize) {
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;
    int maxValIdx = idx;
    if (left < heapSize && nums[left] > nums[maxValIdx]) maxValIdx = left;
    if (right < heapSize && nums[right] > nums[maxValIdx]) maxValIdx = right;
    if (maxValIdx != idx) {
        swap(nums[maxValIdx], nums[idx]);
        downAdjust(nums, maxValIdx, heapSize);
    }
}

void upAdjust(vector<int>& nums, int idx) {
    int parent = (idx - 1) / 2;
    if (parent >= 0 && nums[idx] > nums[parent]) {
        swap(nums[idx], nums[parent]);
        upAdjust(nums, parent);
    }
}

void insert(vector<int>& nums, int val) {
    nums.push_back(val);
    upAdjust(nums, nums.size() - 1);
}

vector<int> _buildHeap(vector<int>& nums) {
    vector<int> heap;
    for (int num : nums) {
        insert(heap, num);
    }
    return heap;
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
    while (heapSize--) {
        swap(nums[0], nums[heapSize]);
        downAdjust(nums, 0, heapSize);
    }
}

int main() {
    vector<int> nums = {85, 55, 82, 57, 68, 92, 99, 98, 66, 56};
    // buildHeap(nums); // 建堆
    vector<int> _nums =  _buildHeap(nums); // 建堆
    for (auto num : _nums) {
        cout << num << ' ';
    }
    cout << endl;
    insert(_nums, 100); // 堆插入
    for (auto num : _nums) {
        cout << num << ' ';
    }
    cout << endl;
    heapSort(_nums); // 堆排序
    for (auto num : _nums) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}


