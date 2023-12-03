# include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 双指针,前一个指针和后一个指针间隔n个位置
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* cur = dummyHead;
        while (n--) {
            cur = cur->next;
        }
        while (cur->next != nullptr) {
            cur = cur->next;
            pre = pre->next;
        }
        ListNode* tmp = pre->next;
        pre->next = pre->next->next;
        delete tmp;
        tmp = nullptr;
        return dummyHead->next;
    }
};

int main() {
    ListNode* dummyHead = new ListNode();
    ListNode* cur = dummyHead;
    for (int i = 0; i <= 5; i++) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    Solution so = Solution();
    int n = 2;
    dummyHead->next = so.removeNthFromEnd(dummyHead->next, n);
    cur = dummyHead;
    while (cur->next != nullptr) {
        cout << cur->next->val << ' ';
        cur = cur->next;
    }
    return 0;
}