#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 定义前缀和pre[i]为区间[0,i]的子数组的和
        // 假设索引[j,i]的子数组和为k: pre[i] - pre[j - 1] = k
        // pre[j - 1] = pre[i] - k
        // 如果j - 1存在, 则答案+1
        // 按照题意: j - 1 <= i, j < i
        vector<int> pre(nums.size(), 0);
        unordered_map<int, int> mp;
        mp[0]++;  // 考虑第一个元素就是k的情况
        int res = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];  // 前缀和，表示0-i元素的和
            int target = sum - k;
            if (mp.find(target) != mp.end()) {  // mp.find(target)的范围是[0, i-1], 所以要先find，然后再更新map
                res += mp[target];  // 加上所有可能性
            }
            mp[sum]++;
        }
        return res;
    }
};