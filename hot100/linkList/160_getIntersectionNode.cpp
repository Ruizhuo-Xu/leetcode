#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cur = headA;
        int sizeA = 0;
        while (cur != nullptr) {
            cur = cur->next;
            sizeA++;
        }
        int sizeB = 0;
        cur = headB;
        while (cur != nullptr) {
            cur = cur->next;
            sizeB++;
        }
        ListNode* curA = headA;
        ListNode* curB = headB;
        if (sizeA > sizeB) {
            int gap = sizeA - sizeB;
            while (gap--) {
                curA = curA->next;
            }
        }
        if (sizeB > sizeA) {
            int gap = sizeB - sizeA;
            while (gap--) {
                curB = curB->next;
            }
        }
        while (curA && curB) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};

int main() {
    ListNode* node = new ListNode(8);
    node->next = new ListNode(4);
    node->next->next = new ListNode(5);
    ListNode* node1 = new ListNode(4);
    node1->next = new ListNode(1);
    node1->next->next = node;
    ListNode* node2 = new ListNode(5);
    node2->next = new ListNode(6);
    node2->next->next = new ListNode(1);
    node2->next->next = node;
    Solution().getIntersectionNode(node1, node2);
    cout << Solution().getIntersectionNode(node1, node2)->val << endl;
    return 0;
}