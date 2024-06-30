#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode();
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* cur = dummyHead;
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val < cur2->val) {
                cur->next = cur1;
                cur1 = cur1->next;
            } else {
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        cur->next = cur1 ? cur1 : cur2;
        return dummyHead->next;
    }
};