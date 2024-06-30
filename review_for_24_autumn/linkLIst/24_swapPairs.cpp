#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // dummyHead -> 0 -> 1 -> 2 -> 3, pre = dummyHead, cur = 0
        // step1: pre / cur -> 1 -> 2 -> 3
        // step2: cur -> 2 -> 3
        // step3: pre -> 1 -> cur -> 2 -> 3
        // pre = cur, cur = cur->next
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {  // 要交换cur和cur->next
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = cur;
            pre = cur;
            cur = cur->next;
        }
        return dummyHead->next;
    }
};