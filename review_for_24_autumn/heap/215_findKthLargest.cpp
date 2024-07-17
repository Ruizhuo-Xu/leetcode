#include <iostream>
#include <vector>
#include <queue>

// rand
#include <ctime>
#include <cstdlib>

using namespace std;

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         srand((unsigned)time(NULL));
//         quickSort(nums, k, 0, nums.size() - 1);
//         return nums[nums.size() - k];
//     }

//     int partition(vector<int>& nums, int left, int right) {
//         int randNum = left + ((float) rand() / RAND_MAX) * (right - left) + 0.5;
//         swap(nums[left], nums[randNum]);
//         int temp = nums[left];
//         while (left < right) {
//             while (left < right && nums[right] >= temp) right--;
//             nums[left] = nums[right];
//             while (left < right && nums[left] <= temp) left++;
//             nums[right] = nums[left];
//         }
//         nums[left] = temp;
//         return left;
//     }

//     void quickSort(vector<int>& nums, int k, int left, int right) {
//         if (left >= right) return ;
//         int pos = partition(nums, left, right);
//         if (pos > (int) nums.size() - k) {
//             quickSort(nums, k, left, pos - 1);
//         } else if (pos < (int) nums.size() - k) {
//             quickSort(nums, k, pos + 1, right);
//         } else {
//             return ;
//         }
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 直接使用priority_queue作为堆
        priority_queue<int, vector<int>, greater<int>> que;
        for (int num : nums) {
            que.push(num);
            if (que.size() > k) {
                que.pop();
            }
        }
        return que.top();
    }
};


int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    cout << Solution().findKthLargest(nums, 4) << endl;
    return 0;
}