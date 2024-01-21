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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            ListNode* temp = cur->next->next;
            cur->next->next = cur;
            pre->next = cur->next;
            cur->next = temp;
            pre = cur;
            cur = cur->next;
        }
        return dummyHead->next;
    }
};

int main () {
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode* dummyHead = new ListNode();
    ListNode* cur = dummyHead;
    for (int num : nums) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    cur = Solution().swapPairs(dummyHead->next);
    while (cur) {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
    return 0;
}