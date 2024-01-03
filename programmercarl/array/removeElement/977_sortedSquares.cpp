#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int resIndex = res.size() - 1;
        int headIndex = 0;
        int tailIndex = nums.size() - 1;
        while (headIndex <= tailIndex) {
            long headNum = (long) nums[headIndex] * nums[headIndex];
            long tailNum = (long) nums[tailIndex] * nums[tailIndex];
            if (headNum > tailNum) {
                res[resIndex--] = headNum;
                headIndex++;
            } else {
                res[resIndex--] = tailNum;
                tailIndex--;
            }
        }
        return res;
    }
};

int main() {
    Solution so = Solution();
    // vector<int> nums = {-4,-1,0,3,10};
    vector<int> nums = {-7,-3,2,3,11};
    vector<int> sortedSquares = so.sortedSquares(nums);
    for (auto it : sortedSquares) {
        cout << it << ' ';
    }
    return 0;
}