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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* dummyHead = new ListNode();
        ListNode* cur = dummyHead;
        int x = 0;
        while (l1 != nullptr || l2 != nullptr || x > 0) {  // !!! 三个数任意一个有值就继续循环
            int num1 = 0, num2 = 0;
            if (l1 != nullptr) {
                num1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                num2 = l2->val;
                l2 = l2->next;
            }
            int sum = num1 + num2 + x;
            cur->next = new ListNode(sum % 10);
            x = sum / 10;
            cur = cur->next;
        }
        return dummyHead->next;
    }
};