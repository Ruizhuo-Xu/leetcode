#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 建立一个链表 i->nums[i]->nums[nums[i]]->... i从0开始
        // 寻找链表环的入口，使用快慢指针
        int fast = 0;
        int slow = 0;
        slow = nums[slow]; // 一步
        fast = nums[nums[fast]]; // 两步
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int cur1 = 0;
        int cur2 = slow;
        while (cur1 != cur2) {
            cur1 = nums[cur1];
            cur2 = nums[cur2];
        }
        return cur1;
    }
};

int main() {
    vector<int> nums = {1,3,4,2,2};
    cout << Solution().findDuplicate(nums) << endl;
    return 0;
}