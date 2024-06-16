#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {  // nums为空的情况
            return 0;
        }
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            // 记录出现过的数字
            set.insert(nums[i]);
        }
        int res = 0;
        for (auto it = set.begin(); it != set.end(); it++) {
            if (set.find(*it - 1) != set.end()) {  // 如果一个数字的前一个数字存在，那么最长的序列肯定不是以这个数字为起点
                continue;
            }
            int len = 1;
            int num = *it + 1;
            while (set.find(num) != set.end()) {  // 如果一个数字的前一个数字不存在，且后一个数字存在，则循环寻找下一个数字
                num++;
                len++;
                res = len > res ? len : res;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << Solution().longestConsecutive(nums) << endl;
    return 0;
}