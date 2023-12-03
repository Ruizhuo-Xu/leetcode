#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         // 双指针
//         // 从前往后翻转链表
//         ListNode* pre = nullptr;
//         ListNode* cur = head;
//         while (cur != nullptr) {
//             ListNode* tmp = cur->next;
//             cur->next = pre; // reverse
//             pre = cur;
//             cur = tmp;
//         }
//         return pre;
//     }
// };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 递归法
        // 从前往后翻转链表
        return reverse(nullptr, head);
    }

    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (cur == nullptr) return pre;
        ListNode* tmp = cur->next;
        cur->next = pre;
        return reverse(cur, tmp);
    }
};

int main() {
    ListNode* dummyHead = new ListNode();
    ListNode* cur = dummyHead;
    for (int i = 0; i <= 5; i++) {
        cur->next = new ListNode();
        cur->next->val = i;
        cur = cur->next;
    }
    Solution so = Solution();
    dummyHead->next = so.reverseList(dummyHead->next);
    cur = dummyHead;
    while (cur->next != nullptr) {
        cout << cur->next->val << ' ';
        cur = cur->next;
    }
    return 0;
}