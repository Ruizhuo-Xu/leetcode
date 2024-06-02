#include <iostream>
#include <vector>
using namespace std;

void downAdjust(vector<int>& nums, int i, int heapSize) {
    // 将数组(树的层序遍历结果)中的节点i进行向下调整(不断和子节点比较，将最大的子节点和i节点进行交换)
    // 时间复杂度O(logn)
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int maxValIndex = i;
    // 首先判断左右孩子是否存在，如果存在，依次比较，找到最大的节点
    if (left < heapSize && nums[left] > nums[maxValIndex]) {
        maxValIndex = left;
    }
    if (right < heapSize && nums[right] > nums[maxValIndex]) {
        maxValIndex = right;
    }
    if (maxValIndex != i) { // 左右孩子是最大的节点,递归终止条件
        swap(nums[i], nums[maxValIndex]);
        downAdjust(nums, maxValIndex, heapSize); // 交换后，继续向下比较
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

void upAdjust(vector<int>& nums, int i) {
    int parent = (i - 1) / 2;
    if (parent >= 0 && nums[parent] < nums[i]) {
        swap(nums[parent], nums[i]);
        upAdjust(nums, parent);
    }
}

void buildHeap(vector<int>& nums) {
    // 建堆 时间复杂度O(n)
    int heapSize = nums.size();
    for (int i = heapSize / 2; i >= 0; i--) { // 节点数为n的完全二叉树的叶子节点数量为 n/2 (向上取整)
        downAdjust(nums, i, heapSize);
    }
}

void insert(vector<int>& heap, int val) {
    heap.push_back(val);
    upAdjust(heap, heap.size() - 1);
}

void heapSort(vector<int>& nums) {
    // 堆排序，时间复杂度nlog(n)
    buildHeap(nums);
    for (int i = nums.size() - 1; i >= 1; i--) {
        swap(nums[0], nums[i]); // 将最后一个节点和根节点交换
        downAdjust(nums, 0, i); // 弹出一个元素，减小堆的大小
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