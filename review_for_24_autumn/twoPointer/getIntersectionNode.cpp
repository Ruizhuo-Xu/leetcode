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
        int sizeA = 0;
        ListNode* cur = headA;
        while(cur != nullptr) {
            cur = cur->next;
            sizeA++;
        }
        int sizeB = 0;
        cur = headB;
        while(cur != nullptr) {
            cur = cur->next;
            sizeB++;
        }
        int gap = sizeA > sizeB ? sizeA - sizeB : sizeB - sizeA;
        ListNode* cur1 = sizeA > sizeB ? headA : headB;
        ListNode* cur2 = sizeA > sizeB ? headB : headA;
        while (gap--) {
            cur1 = cur1->next;
        }
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