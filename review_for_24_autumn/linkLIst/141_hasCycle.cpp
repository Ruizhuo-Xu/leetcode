#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        while (fastptr->next && fastptr->next->next) {
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
            if (fastptr == slowptr) {
                return true;
            }
        }
        return false;
    }
};