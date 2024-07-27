#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 数组下标就相当于链表每个节点的指针,寻找链表成环的入口
        int slow = 0;
        int fast = 0;
        while (true) {
            slow = nums[slow];  // 这里相当于是cur->next
            fast = nums[nums[fast]]; // cur->next->next
            if (slow == fast) {
                break;
            }
        }
        int cur = 0;
        while (cur != slow) {
            cur = nums[cur];
            slow = nums[slow];
        }
        return cur;
    }
};