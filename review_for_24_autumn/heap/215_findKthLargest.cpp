#include <iostream>
#include <vector>

// rand
#include <ctime>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand((unsigned)time(NULL));
        return quickSort(nums, k, 0, nums.size() - 1);
    }

    int quickSort(vector<int>& nums, int k, int left, int right) {
        int randNum = left + ((float) rand() / RAND_MAX) * (right - left) + 0.5;
        int ref = nums[randNum];
        vector<int> big, small;
        for (int num: nums) {
            if (num > ref) big.push_back(num);
            else if (num < ref) small.push_back(num);
        }
        if (big.size() >= k) {
            quickSort(big, k, 0, big.size() - 1);
        } else if (nums.size() - small.size() < k) {
            quickSort(small, k - (nums.size() - small.size()), 0, small.size() - 1);
        }
        return ref;
    }
};

int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    cout << Solution().findKthLargest(nums, 4) << endl;
    return 0;
}