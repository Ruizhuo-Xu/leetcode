#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return false;
        }
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        while (fastPtr->next && fastPtr->next->next) {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
        ListNode* cur1 = reverse(slowPtr->next);
        ListNode* cur2 = head;
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val != cur2->val) {
                return false;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};