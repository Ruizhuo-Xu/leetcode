#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5};
    ListNode* dummyHead = new ListNode();
    ListNode* cur = dummyHead;
    for (int i = 0; i < nums.size(); i++) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    ListNode* head = Solution().reverseList(dummyHead->next);
    cur = head;
    while (cur) {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
    return 0;
}