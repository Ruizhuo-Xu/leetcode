#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // 每次翻转序列中最小的元素即可获得最大和,时间复杂度:O(KlogN)
        priority_queue<int, vector<int>, greater<int>> que(nums.begin(), nums.end());
        while (k--) {
            int temp = que.top();
            que.pop();
            que.push(-temp);
        }
        int res = 0;
        while (!que.empty()) {
            res += que.top();
            que.pop();
        }
        return res;
    }
};

int main() {
    vector<int> nums = {2,-3,-1,5,-4};
    int k = 2;
    cout << Solution().largestSumAfterKNegations(nums, k) << endl;
    return 0;
}