#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        buildHeap(nums);
        // int size = nums.size();
        // for (int i = size - 1; i >= size - k; i--) {
        for (int i = nums.size() - 1; i >= nums.size() - k; i--) {
            cout << i << ' ';
            swap(nums[i], nums[0]);
            downAdjust(nums, 0, i);
        }
        return nums[nums.size() - k];
    }

    void downAdjust(vector<int>& nums, int i, int heapSize) {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int maxValIndex = i;
        if (left < heapSize && nums[left] > nums[maxValIndex]) {
            maxValIndex = left;
        }
        if (right < heapSize && nums[right] > nums[maxValIndex]) {
            maxValIndex = right;
        }
        if (maxValIndex != i) {
            swap(nums[i], nums[maxValIndex]);
            downAdjust(nums, maxValIndex, heapSize);
        }
    }

    void buildHeap(vector<int>& nums) {
        int heapSize = nums.size();
        for (int i = heapSize / 2; i >= 0; i--) {
            downAdjust(nums, i, heapSize);
        }
    }
};

int main() {
    // vector<int> nums = {3, 2, 1, 5, 6, 4};
    vector<int> nums = {1};
    cout << Solution().findKthLargest(nums, 1) << endl;
    return 0;
}