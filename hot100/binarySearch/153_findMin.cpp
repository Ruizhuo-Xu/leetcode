#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        // 在区间[left, right]内搜索最小值
        while (left < right) { // 如果left == right说明区间只有一个元素,即找到了最小值
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) { // 说明mid是最小值右侧的元素
                right = mid; // 有可能mid就是最小值,如果right=mid-1可能会错过最小值,在区间[mid,right]内搜索
            } else {
                left = mid + 1; // mid不可能是最小值,所以在区间[mid+1, right]内继续搜索
            }
        }
        return nums[left];
    }
};

int main() {
    vector<int> nums = {3,4,5,1,2};
    cout << Solution().findMin(nums) << endl;
    return 0;
}