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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next; // 快指针速度为2
            slow = slow->next; // 慢指针速度为1

            if (slow == fast) { // 相遇
                ListNode* node1 = head;
                ListNode* node2 = slow;
                while (node1 != node2) {
                    node1 = node1->next;
                    node2 = node2->next;
                }
                return node1;
            }
        }
        return nullptr;
    }
};

int main() {
    int x[4] = {3, 2, 0, -4};
    ListNode* dummyHead = new ListNode();
    ListNode* cur = dummyHead;
    for (auto it : x) {
        cur->next = new ListNode(it);
        cur = cur->next;
    }
    int pos = 1;
    ListNode* cycleStart = dummyHead->next;
    while (pos--) {
        cycleStart = cycleStart->next;
    }
    cur->next = cycleStart;
    Solution so = Solution();
    cur = so.detectCycle(dummyHead->next);
    if (cur == cycleStart) {
        cout << "have cycle!" << endl;
    } else {
        cout << "no cycle" << endl;
    }
    return 0;
}