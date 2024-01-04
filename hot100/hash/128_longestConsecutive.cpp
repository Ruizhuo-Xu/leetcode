#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive_(vector<int>& nums) {
        // 使用set排序去重,时间复杂度O(nlogn),空间复杂度O(n)
        // 不符合leetcode要求的O(n)时间复杂度
        set<int> numSet;
        for (int i = 0; i < nums.size(); i++) {
            numSet.insert(nums[i]);
        }
        auto it = numSet.begin();
        int pre = *it;
        int res = 1;
        int cnt = 1;
        for (it++; it != numSet.end(); it++) {
            if (*it == pre + 1) {
                cnt++;
            } else {
                cnt = 1;
            }
            res = max(cnt, res);
            pre = *it;
        }
        return res;
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        int res = 1;
        for (unordered_set<int>::iterator it = numSet.begin(); it != numSet.end(); it++) {
            int num = *it;
            if (numSet.find(num - 1) == numSet.end()) { // 不存在前驱数
                // nums中的每个数最多进入一次这里,所以时间复杂度是O(n);
                int curLen = 1;
                while (numSet.find(num + 1) != numSet.end()) {
                    num++;
                    curLen++;
                }
                res = max(curLen, res);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {100,4,200,1,3,2};
    cout << Solution().longestConsecutive(nums) << endl;
    return 0;
}