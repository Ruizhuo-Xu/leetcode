#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 前缀和: pre[i]表示数组中0-i个元素的和
        // pre[i] = pre[i - 1] + nums[i]
        // 要寻找一个子数组j-i的和为k，则pre[i] - pre[j - 1] = k
        // pre[j - 1] = pre[i] - k;
        // 所以我们考虑以i结尾的和为k的连续子数组个数时只要统计有多少个前缀和为 pre[i]−k的 pre[j]即可
        // 有点像两数之和, pre[j - 1] + k = pre[i], 维护一个哈希表记录前缀和出现的次数,后续步骤和两数之和一致
        // 时间复杂度O(n), 空间复杂度O(n)
        unordered_map<int, int> mp;
        int sum = 0;
        int cnt = 0;
        mp[0] = 1; // 前缀和初始化
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i]; // pre[i]
            if (mp.find(sum - k) != mp.end()) {
                cnt += mp[sum - k];
            }
            mp[sum]++; // mp记录i之前的前缀和出现的次数
        }
        return cnt;
    }
};

int main () {
    vector<int> nums = {3, 4, 7, 2, -3, 1, 4, 2};
    int k = 7;
    cout << Solution().subarraySum(nums, k) << endl;
    return 0;
}