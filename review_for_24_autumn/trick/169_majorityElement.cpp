#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate;  // 众数候选
        int cnt = 0;  // 当前候选的计数
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {  // cnt为0说明当前无众数候选
                candidate = nums[i];
            }
            if (candidate == nums[i]) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return candidate;
    }
};