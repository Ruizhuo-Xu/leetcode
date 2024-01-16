#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 任选一个候选值，初始计数值为0
        int candidate = nums[0];
        int count = 0;
        for (int i = 0; i < nums.size(); i++) { // 遍历数组元素
            if (count == 0) { // 如果计数值为0，则将当前元素作为众数候选值
                candidate = nums[i];
            }
            if (candidate == nums[i]) { // 如果当前元素 == 候选值，计数值+1
                count++;
            } else { // 否则计数值-1
                count--;
            }
        }
        return candidate;
    }
};