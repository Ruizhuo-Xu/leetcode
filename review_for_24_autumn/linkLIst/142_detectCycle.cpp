#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode* slowptr = head;
        ListNode* fastprt = head;
        while (fastprt->next && fastprt->next->next) {
            fastprt = fastprt->next->next;
            slowptr = slowptr->next;
            if (fastprt == slowptr) {
                ListNode* cur = head;
                while (cur != slowptr) {
                    cur = cur->next;
                    slowptr = slowptr->next;
                }
                return cur;
            }
        }
        return nullptr;
    }
};