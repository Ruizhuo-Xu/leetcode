#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cur = headA;
        int sizeA = 0;
        while (cur != nullptr) {
            sizeA++;
            cur = cur->next;
        }
        cur = headB;
        int sizeB = 0;
        while (cur != nullptr) {
            sizeB++;
            cur = cur->next;
        }
        int gap = sizeA > sizeB ? sizeA - sizeB : sizeB - sizeA;
        ListNode* cur1 = sizeA > sizeB ? headA : headB;
        while (gap--) {
            cur1 = cur1->next;
        }
        ListNode* cur2 = sizeA > sizeB ? headB : headA;
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1 == cur2) {
                return cur1;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return nullptr;
    }
};